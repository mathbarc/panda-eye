#ifndef IMAGE_HPP
#define IMAGE_HPP

#include "media.hpp"
#include <QImage>
#include <opencv2/core/core.hpp>

class Image : public Media
{
    public:
        Image(QString path);
        virtual const QImage& getThumbnail();
        virtual MediaType getType();
        static const QStringList filters;

    private:
        QImage thumbnail;
};

#endif // IMAGE_HPP
