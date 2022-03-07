#include "image.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include "utils.hpp"

const QStringList Image::filters = QStringList() << "*.jpg" << "*.JPG" << "*.jpeg" << "*.JPEG" <<"*.png"<<"*.PNG";

Image::Image(QString path)
    : Media(path.toStdString())
{

    cv::Mat img = cv::imread(this->path);
    this->thumbnail = QPixmap::fromImage(utils::cvMatToQImage(utils::resizeSquarred(img, Media::thumbnailSize)));
    img.release();

}

const QPixmap &Image::getThumbnail()
{
    return this->thumbnail;
}

MediaType Image::getType()
{
    return MediaType::Image;
}

