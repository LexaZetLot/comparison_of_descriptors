#include "mainHederFile.hpp"
#include <random>
#include <iostream>
#include <opencv2/opencv.hpp>


int main(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(0.0, 1.0);

    cv::Mat des(1000, 3, CV_64F);
    for(int i = 0; i < des.rows; i++)
        for(int j = 0; j < des.cols; j++)
            des.at<double>(i, j) = dis(gen);


    TreeNDimensionalSpace treeNDimensionalSpace(des, 4);

    treeNDimensionalSpace.treeBuild();
    treeNDimensionalSpace.treeWalk();

    std::cout << treeNDimensionalSpace.searchTree(des.row(32), 0.2) << std::endl;


    return 0;
}
