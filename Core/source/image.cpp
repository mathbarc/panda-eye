#include "image.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "utils.hpp"


#include "dcmtk/config/osconfig.h"
#include "dcmtk/dcmdata/dcfilefo.h"
#include "dcmtk/dcmdata/libi2d/i2d.h"
#include "dcmtk/dcmdata/libi2d/i2djpgs.h"
#include "dcmtk/dcmdata/libi2d/i2dplsc.h"
#include "dcmtk/dcmdata/dctk.h"


const QStringList Image::filters =
        QStringList() << "*.jpg" << "*.JPG" << "*.jpeg" << "*.JPEG" << "*.png" << "*.PNG" << "*.tiff" << "*.TIFF"
                      << ".dcm" << ".DCM";

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

        DicomImage *dcmImage = new DicomImage(this->path.c_str());
        int depth = dcmImage->getDepth();
        int width = dcmImage->getWidth();
        int height = dcmImage->getHeight();
        unsigned short *pixelData = (unsigned short *) (dcmImage->getOutputData(16));
        cv::Mat imageMat(height, width, CV_16UC1, pixelData);
        imageMat.copyTo(img);
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

