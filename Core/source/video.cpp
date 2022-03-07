#include "video.hpp"
#include "utils.hpp"
#include <QImage>

const QStringList Video::filters = QStringList() << "*.mpeg"<< "*.MPEG" << "*.mp4" << "*.MP4" << "*.avi" << "*.avi" <<"*.mkv"<<"*.MKV";

Video::Video(QString filePath)
    : Media(filePath.toStdString())
{
    cv::VideoCapture video(this->path);
    cv::Mat frame;
    video >> frame;

    this->thumbnail = QPixmap::fromImage(utils::cvMatToQImage(utils::resizeSquarred(frame, Media::thumbnailSize)));
    video.release();

}


const QPixmap& Video::getThumbnail()
{
    return this->thumbnail;
}


MediaType Video::getType()
{
    return MediaType::Video;
}
