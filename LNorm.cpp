#include "mainHederFile.hpp"
#include <cmath>

double LNorm(cv::Mat des1, cv::Mat des2){
    float sum = 0;
    for(int i = 0; i < des1.rows; i++)
        if(des1.depth() == CV_32F)
            sum += (des1.at<float>(i, 0) - des2.at<float>(i, 0)) * (des1.at<float>(i, 0) - des2.at<float>(i, 0));
        else
            sum += (des1.at<double>(i, 0) - des2.at<double>(i, 0)) * (des1.at<double>(i, 0) - des2.at<double>(i, 0));

    return std::sqrt(sum);
}
