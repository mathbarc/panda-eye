#include "video.hpp"
#include "utils.hpp"
#include <QImage>

const QStringList Video::filters = QStringList() << "*.mpeg"<< "*.MPEG" << "*.mp4" << "*.MP4" << "*.avi" << "*.avi" <<"*.mkv"<<"*.MKV";

Video::Video(QString filePath)
{
    this->video.open(filePath.toStdString());
    cv::Mat frame;
    this->video >> frame;
    this->video.set(cv::CAP_PROP_POS_FRAMES, 0);

    this->thumbnail = QPixmap::fromImage(utils::cvMatToQImage(utils::resizeSquarred(frame, Media::thumbnailSize)));

}


QPixmap Video::getThumbnail()
{
    return this->thumbnail;
}


MediaType Video::getType()
{
    return MediaType::Video;
}
