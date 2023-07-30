#include "image.hpp"


#include "dcmtk/dcmdata/libi2d/i2dplsc.h"


const QStringList Image::filters =
        QStringList() << "*.jpg" << "*.JPG" << "*.jpeg" << "*.JPEG" << "*.png" << "*.PNG" << "*.tiff" << "*.TIFF"
                      << ".bmp" << ".BMP" << ".dcm" << ".DCM";


cv::Mat dcmImageToCvMat(const DcmImage &img, bool convertTo8Bits) {
    cv::Mat mat;
    switch (img.pixelRepresentation()) {
        case DcmImage::PixelUInt8:
            mat = cv::Mat(img.rows(), img.columns(), CV_8U);
            break;
        case DcmImage::PixelInt8:
            mat = cv::Mat(img.rows(), img.columns(), CV_8S);
            break;
        case DcmImage::PixelUInt16:
            mat = cv::Mat(img.rows(), img.columns(), CV_16U);
            break;
        case DcmImage::PixelInt16:
            mat = cv::Mat(img.rows(), img.columns(), CV_16S);
            break;
        case DcmImage::PixelInt32:
        case DcmImage::PixelUInt32:
            mat = cv::Mat(img.rows(), img.columns(), CV_32S);
            break;
    }

    // Get RAW Pixel data
    img.raw(mat.data, 0, 0, img.columns(), img.rows(), mat.step);

    // Invert if Photometric interpretation is MONOCHROME1 (white is 0)
    if (img.photometricInterpretation() == DcmImage::PmiMonochrome1) {
        cv::Mat max(mat.size(), mat.type());
        max.setTo(img.maxPossibleValue());
        mat = max - mat;
    }

    // Convert to CV_16U with correct scaling of values
    switch (img.pixelRepresentation()) {
        case DcmImage::PixelInt8:
            mat.convertTo(mat, CV_8U, 1.0, -img.minPossibleValue());
            break;
        case DcmImage::PixelInt16:
            mat.convertTo(mat, CV_16U, 1.0, -img.minPossibleValue());
            break;
        case DcmImage::PixelInt32:
        case DcmImage::PixelUInt32:
            mat.convertTo(mat, CV_16U, 1.0 / double(1 << (img.bitsStored() - 16)), -img.minPossibleValue());
            break;
    }

    // Converts to 8 bits if wanted
    if (convertTo8Bits) {
        cv::Mat mat8;
        float scale = 1 << (img.bitsStored() - 8);
        float shift = img.isSigned() ? 127.0 : 0.0;
        cv::convertScaleAbs(mat, mat8, 1.0 / scale, shift);
        return mat8;
    } else
        return mat;
}


Image::Image(QString path)
        : Media(path.toStdString()) {

    cv::Mat img;
    if (path.contains(".tiff")) {
        cv::Mat originalImg = cv::imread(this->path, cv::IMREAD_ANYCOLOR | cv::IMREAD_ANYDEPTH | cv::IMREAD_UNCHANGED);

        if (originalImg.type() == CV_32FC3)
            originalImg.convertTo(img, CV_8UC3);
        else if (originalImg.type() == CV_32F) {
            double min, max;
            cv::minMaxIdx(originalImg, &min, &max);
            originalImg.convertTo(img, CV_8U, 255. / (max - min), 255. * (-min) / (max - min));
        } else
            img = originalImg;
    }
#ifdef __DCMTK__

    else if (path.contains(".dcm") || path.contains(".DCM")) {

        DicomImage dcmImage(this->path.c_str());
        int width = dcmImage.getWidth();
        int height = dcmImage.getHeight();
        unsigned short *pixelData = (unsigned short *) (dcmImage.getOutputData(16));
        cv::Mat imageMat(height, width, CV_16UC1, pixelData);

        img = imageMat;
    }

#endif
    else {
        img = cv::imread(this->path);
    }

    cv::Mat resizedImg = utils::resizeSquarred(img, Media::thumbnailSize);

    this->thumbnail = utils::cvMatToQImage(resizedImg);

    resizedImg.release();
    img.release();

}


const QImage &Image::getThumbnail() {
    return this->thumbnail;
}

MediaType Image::getType() {
    return MediaType::Image;
}

