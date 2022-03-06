#include "media.hpp"
#include "image.hpp"

#include <QFileInfo>


int Media::thumbnailSize = 200;

Media::Media()
{

}


Media* Media::makeMedia(QString path)
{
    QFileInfo info(path);
    if(Image::filters.contains("*."+info.suffix()))
    {
        return new Image(path);
    }
}

void Media::setThumnailSize(int size)
{
    Media::thumbnailSize = size;
}
