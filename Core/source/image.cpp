#include "image.hpp"


#include "dcmtk/dcmdata/libi2d/i2dplsc.h"


const QStringList Image::filters =
        QStringList() << "*.jpg" << "*.JPG" << "*.jpeg" << "*.JPEG" << "*.png" << "*.PNG" << "*.tiff" << "*.TIFF"
                      << "*.bmp" << "*.BMP" << "*.dcm" << "*.DCM";


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

#ifdef __DICOM__
        else if(path.contains(".dcm"))
        {

            cv::Mat dicomImage =  cv::imread(this-> path);
            dicomImage.copyTo(img);
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

