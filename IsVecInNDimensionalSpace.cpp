#include <opencv2/core.hpp>

bool isVecInNDimensionalSpace(cv::Mat vec){
    for(int i = 0; i < vec.rows; i++)
        if (vec.at<double>(i, 0) > 1.0 || vec.at<double>(i, 0) < 0.0)
            return false;

    return true;
}
