#ifndef MEDIA_HPP
#define MEDIA_HPP

#include <QSharedPointer>

enum class MediaType
{
    Image = 0,
    Video = 1
};

class Media
{
    public:
        Media();
        static Media* makeMedia(QString path);
        virtual QPixmap getThumbnail() = 0;
        virtual MediaType getType() = 0;

        static void setThumnailSize(int size);

    protected:

        static int thumbnailSize;

};

#endif // MEDIA_HPP
