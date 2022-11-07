#include "utils.hpp"

#include <opencv2/imgproc/imgproc.hpp>

namespace utils
{

    cv::Mat resizeKeepingAspectRatio(const cv::Mat& img, int size)
    {
        float aspectRatio = float(img.cols)/float(img.rows);
        cv::Mat resized;
        if(aspectRatio>1)
        {
            int row = std::max((int)std::round(size/aspectRatio),1);
            cv::resize(img, resized, cv::Size(size, row));
        }
        else
        {
            int col = std::max((int)std::round(size*aspectRatio),1);
            cv::resize(img, resized, cv::Size(col, size));
        }
        return resized;


    }

    cv::Mat resizeSquarred(const cv::Mat &img, int size)
    {

        cv::Mat resized = resizeKeepingAspectRatio(img, size);

        int dim = std::max(resized.rows, resized.cols);
        cv::Mat out = cv::Mat::zeros(dim, dim, resized.type());
        resized.copyTo(out(cv::Rect((dim-resized.cols)/2, (dim-resized.rows)/2, resized.cols, resized.rows)));

        return out;

    }


}
