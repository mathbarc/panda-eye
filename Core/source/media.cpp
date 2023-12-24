#include "media.hpp"

#include <QFileInfo>

#include "image.hpp"
#include "video.hpp"

#include <QDebug>


MediaNotFound::MediaNotFound(QString path)
    : message("Media: "+path.toStdString()+" could not be opened")
{}

const char* MediaNotFound::what() const
{
    return this->message.c_str();
}


int Media::thumbnailSize = 200;

Media::Media(const std::string path)
    : path(path)
{}


Media* Media::makeMedia(QString path)
{
    QFileInfo info(path);

    if(Image::filters.contains("*."+info.suffix()))
    {
        return new Image(path);
    }
    if(Video::filters.contains("*."+info.suffix()))
    {
        return new Video(path);
    }

    return nullptr;
}

void Media::setThumnailSize(int size)
{
    Media::thumbnailSize = size;
}
