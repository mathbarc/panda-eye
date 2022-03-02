#include "image.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>

const QStringList Image::filters = QStringList() << "*.jpg" << "*.JPG"<<"*.png"<<"*.PNG";

Image::Image(QString path)
{

    cv::Mat img = cv::imread(path.toStdString());
    QImage qImg = cvMatToQImage(img);
    this->thumbnail = QPixmap::fromImage(qImg.scaled(100,100,Qt::KeepAspectRatio));
}

QPixmap Image::getThumbnail()
{
    return this->thumbnail;
}

MediaType Image::getType()
{
    return MediaType::Image;
}
