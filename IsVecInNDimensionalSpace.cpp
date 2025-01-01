#include <opencv2/core.hpp>

bool isVecInNDimensionalSpace(cv::Mat vec){
    for(int i = 0; i < vec.rows; i++)
        if(vec.depth() == CV_32F){
            if (vec.at<float>(i, 0) >= 1.0 || vec.at<float>(i, 0) <= 0.0)
                return false;
        } else
            if (vec.at<double>(i, 0) >= 1.0 || vec.at<double>(i, 0) <= 0.0)
                return false;

    return true;
}
