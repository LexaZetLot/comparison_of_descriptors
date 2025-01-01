#include "mainHederFile.hpp"
#include <opencv2/core/types.hpp>


ComparisonOfDescriptors::ComparisonOfDescriptors(int spaceCapacityThreshold, double treshold){
    this->spaceCapacityThreshold = spaceCapacityThreshold;
    this->treshold = treshold;
}


std::vector<cv::DMatch> ComparisonOfDescriptors::match(cv::Mat des1, cv::Mat des2){
    cv::normalize(des1, des1, 1, 0, cv::NORM_L2);
    cv::normalize(des2, des2,  1, 0, cv::NORM_L2);

    TreeNDimensionalSpace treeNDimensionalSpace(des2, spaceCapacityThreshold, treshold);
    std::vector<cv::DMatch> res;

    cv::DMatch dMatch;
    std::vector<double> indexDistance;
    for(int i = 0; i < des1.rows; i++){
        indexDistance = treeNDimensionalSpace.searchTree(des1.row(i));

        if(((int)indexDistance[0]) == -1)
            continue;

        dMatch.queryIdx = i;
        dMatch.trainIdx = (int)indexDistance[0];
        dMatch.distance = indexDistance[1];
        dMatch.imgIdx = 0;

        res.push_back(dMatch);
    }

    if(res.size() == 0)
        return std::vector<cv::DMatch>();
    else
        return res;
}


void ComparisonOfDescriptors::setSpaceCapacityThreshold(int spaceCapacityThreshold){
    this->spaceCapacityThreshold = spaceCapacityThreshold;
}

int ComparisonOfDescriptors::getSpaceCapacityThreshold(){
    return spaceCapacityThreshold;
}

void ComparisonOfDescriptors::setThreshold(double treshold){
    this->treshold = treshold;
}

double ComparisonOfDescriptors::getThreshold(){
    return treshold;
}
