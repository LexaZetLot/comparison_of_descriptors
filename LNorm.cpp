#include "mainHederFile.hpp"
#include <cmath>

double LNorm(cv::Mat des1, cv::Mat des2){
    double sum = 0;
    for(int i = 0; i < des1.rows; i++)
        sum += (des1.at<double>(i, 0) - des2.at<double>(i, 0)) * (des1.at<double>(i, 0) - des2.at<double>(i, 0));

    return std::sqrt(sum);
}
