#ifndef UTILS_HPP
#define UTILS_HPP

#include <QImage>
#include <iostream>
#include <opencv2/core/core.hpp>

namespace utils
{

    cv::Mat resizeKeepingAspectRatio(const cv::Mat &img, int size);

    cv::Mat resizeSquarred(const cv::Mat &img, int size);

    inline QImage cvMatToQImage(const cv::Mat &inputImg)
    {
        QImage img;

        if(inputImg.channels() == 3)
        {
            img = QImage(inputImg.ptr(), inputImg.cols, inputImg.rows, inputImg.step, QImage::Format_RGB888);
            img = img.rgbSwapped();
        }
        else if(inputImg.channels() == 1)
        {
            img = QImage(inputImg.ptr(), inputImg.cols, inputImg.rows, inputImg.step, QImage::Format_Grayscale16);
            img = img.rgbSwapped();
        }
        else
            img = QImage(inputImg.ptr(), inputImg.cols, inputImg.rows, inputImg.step, QImage::Format_Grayscale8);

        return img.copy();
    }

}

#endif // UTILS_HPP
