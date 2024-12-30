#include "mainHederFile.hpp"

cv::Mat linearCoefficients(cv::Mat matBasis, cv::Mat vecT, cv::Mat des){
    cv::Mat vectorSubtraction = des - vecT;
    cv::Mat matBasisInv;
    cv::invert(matBasis, matBasisInv);

    return matBasisInv * vectorSubtraction;
}
