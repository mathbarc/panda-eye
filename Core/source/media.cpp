#include "media.hpp"
#include "image.hpp"

#include <QFileInfo>

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
