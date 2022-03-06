#ifndef IMAGE_HPP
#define IMAGE_HPP

#include "media.hpp"
#include <QPixmap>
#include <opencv2/core/core.hpp>

class Image : public Media
{
    public:
        Image(QString path);
        virtual QPixmap getThumbnail();
        virtual MediaType getType();
        static const QStringList filters;

    private:
        QPixmap thumbnail;
};

#endif // IMAGE_HPP
