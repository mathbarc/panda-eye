#ifndef IMAGE_HPP
#define IMAGE_HPP

#include "media.hpp"
#include <QImage>
#include <opencv2/core/core.hpp>
#include <dcmtk/config/osconfig.h>
#include <dcmtk/dcmdata/dctk.h>
#include <dcmtk/dcmimgle/dcmimage.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include "utils.hpp"

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
