#include "media.hpp"
#include "image.hpp"
#include "video.hpp"

#include <QFileInfo>


int Media::thumbnailSize = 200;

Media::Media(const std::string path)
    : path(path)
{

}


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
}

void Media::setThumnailSize(int size)
{
    Media::thumbnailSize = size;
}
