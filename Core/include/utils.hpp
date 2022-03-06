#ifndef UTILS_HPP
#define UTILS_HPP

#include <opencv2/core/core.hpp>

namespace utils
{

    cv::Mat resizeKeepingAspectRatio(const cv::Mat& img, int size);
    cv::Mat resizeSquarred(const cv::Mat& img, int size);

}

#endif // UTILS_HPP
