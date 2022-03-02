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

inline QImage cvMatToQImage(const cv::Mat& inputImg)
{
    QImage img;

    if(inputImg.channels()==3)
    {
        img = QImage(inputImg.ptr(), inputImg.cols, inputImg.rows, inputImg.step, QImage::Format_RGB888);
        img = img.rgbSwapped();
    }
    else
        img = QImage(inputImg.ptr(), inputImg.cols, inputImg.rows, inputImg.step, QImage::Format_Mono);

    return img;
}

#endif // IMAGE_HPP
