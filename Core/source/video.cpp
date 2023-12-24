#include "video.hpp"

#include <QImage>
#include <opencv2/videoio/videoio.hpp>

#include "utils.hpp"


const QStringList Video::filters = QStringList() << "*.mpeg"<< "*.MPEG" << "*.mp4" << "*.MP4" << "*.avi" << "*.avi" <<"*.mkv"<<"*.MKV"<<"*.mov"<<"*.MOV";

Video::Video(QString filePath)
    : Media(filePath.toStdString())
{
    cv::VideoCapture video(this->path, cv::CAP_FFMPEG);

    if(!video.isOpened())
    {
        throw MediaNotFound(filePath);
    }

    cv::Mat frame;
    video >> frame;

    if(frame.empty())
    {
        frame = cv::Mat::zeros(cv::Size(200,200),CV_8UC3);
    }

    this->thumbnail = utils::cvMatToQImage(utils::resizeSquarred(frame, Media::thumbnailSize));
    video.release();

}


const QImage& Video::getThumbnail()
{
    return this->thumbnail;
}


MediaType Video::getType()
{
    return MediaType::Video;
}
