#include "image.hpp"

#include "utils.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>

const QStringList Image::filters = QStringList() << "*.jpg" << "*.JPG" << "*.jpeg" << "*.JPEG" << "*.png" << "*.PNG"
                                                 << "*.tif" << "*.tiff" << "*.TIFF"
                                                 << "*.bmp" << "*.BMP" << "*.dcm" << "*.DCM";

Image::Image(QString path) : Media(path.toStdString())
{

    cv::Mat img;
    if(path.contains(".tif") || path.contains(".tiff"))
    {
        cv::Mat originalImg = cv::imread(this->path, cv::IMREAD_ANYCOLOR | cv::IMREAD_ANYDEPTH | cv::IMREAD_LOAD_GDAL);

        if(originalImg.type() == CV_32FC3)
            originalImg.convertTo(img, CV_8UC3);
        else if(originalImg.type() == CV_32F)
        {
            double min, max;
            cv::minMaxIdx(originalImg, &min, &max);
            originalImg.convertTo(img, CV_8U, 255. / (max - min), 255. * (-min) / (max - min));
        }
        else
            img = originalImg;
    }
    else if(path.contains(".dcm") || path.contains(".DCM"))
    {
        cv::Mat originalImg = cv::imread(this->path, cv::IMREAD_ANYCOLOR | cv::IMREAD_ANYDEPTH);
        img = originalImg;
    }
    else
    {
        img = cv::imread(this->path);
    }

    if(img.empty())
    {
        throw MediaNotFound(path);
    }

    cv::Mat resizedImg = utils::resizeSquarred(img, Media::thumbnailSize);

    this->thumbnail = utils::cvMatToQImage(resizedImg);

    resizedImg.release();
    img.release();
}

const QImage &Image::getThumbnail()
{
    return this->thumbnail;
}

MediaType Image::getType()
{
    return MediaType::Image;
}
