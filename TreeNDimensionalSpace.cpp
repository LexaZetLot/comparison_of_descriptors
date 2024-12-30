#include "mainHederFile.hpp"
#include <cstddef>
#include <opencv2/core/hal/interface.h>
#include <iostream>


TreeNDimensionalSpace::TreeNDimensionalSpace(cv::Mat mat, int spaceCapacityThreshold){
    sCT = spaceCapacityThreshold;

    tree.right = NULL;
    tree.left = NULL;

    tree.mat = cv::Mat(cv::Mat::eye(mat.cols, mat.cols, CV_64F));
    tree.vec = cv::Mat(cv::Mat::zeros(mat.cols, 1, CV_64F));

    struct MatArray matArray;
    for(int i = 0; i < mat.rows; i++){
        matArray.des = mat.row(i).clone();
        cv::transpose(matArray.des, matArray.des);
        matArray.index = i;
        tree.arrDes.push_back(matArray);
    }
}

void TreeNDimensionalSpace::treeBuild(){
    tree.right = new struct Tree();
    tree.left = new struct Tree();


    tree.right->right = NULL;
    tree.right->left = NULL;

    tree.left->right = NULL;
    tree.left->left = NULL;


    tree.right->vec = cv::Mat(tree.vec.clone());
    tree.right->vec.at<double>(0, 0) = 0.5;

    tree.left->vec = cv::Mat(tree.vec.clone());


    tree.right->mat = cv::Mat(tree.mat.clone());
    tree.right->mat.at<double>(0, 0) = 0.5;

    tree.left->mat = cv::Mat(tree.right->mat.clone());


    for(long unsigned int i = 0; i < tree.arrDes.size(); i++){
        cv::Mat cof = linearCoefficients(tree.right->mat.clone(), tree.right->vec.clone(), tree.arrDes[i].des.clone());
        if(isVecInNDimensionalSpace(cof))
            tree.right->arrDes.push_back(tree.arrDes[i]);
        else
            tree.left->arrDes.push_back(tree.arrDes[i]);
    }


    if(tree.right->arrDes.size() > (long unsigned int)sCT)
        buildTreeRecursion(tree.right, 1, 1.0);
    if(tree.left->arrDes.size() > (long unsigned int)sCT)
        buildTreeRecursion(tree.left, 1, 1.0);
}

void TreeNDimensionalSpace::buildTreeRecursion(struct Tree* treeFunc, int index, double sizeBasis){
    if(index == tree.mat.cols){
        index = 0;
        sizeBasis /= 2;
    }


    treeFunc->right = new struct Tree();
    treeFunc->left = new struct Tree();


    treeFunc->right->right = NULL;
    treeFunc->right->left = NULL;

    treeFunc->left->right = NULL;
    treeFunc->left->left = NULL;


    treeFunc->right->vec = cv::Mat(treeFunc->vec.clone());
    treeFunc->right->vec.at<double>(index, 0) += sizeBasis / 2;

    treeFunc->left->vec = cv::Mat(treeFunc->vec.clone());


    treeFunc->right->mat = cv::Mat(treeFunc->mat.clone());
    treeFunc->right->mat.at<double>(index, index) = treeFunc->right->vec.at<double>(index, 0);

    treeFunc->left->mat = cv::Mat(treeFunc->right->mat.clone());


    for(long unsigned int i = 0; i < treeFunc->arrDes.size(); i++){
        cv::Mat cof = linearCoefficients(treeFunc->right->mat.clone(), treeFunc->right->vec.clone(), treeFunc->arrDes[i].des.clone());
        if(isVecInNDimensionalSpace(cof))
            treeFunc->right->arrDes.push_back(treeFunc->arrDes[i]);
        else
            treeFunc->left->arrDes.push_back(treeFunc->arrDes[i]);
    }


    if(treeFunc->right->arrDes.size() > (long unsigned int)sCT)
        buildTreeRecursion(treeFunc->right, index + 1, sizeBasis);
    if(treeFunc->left->arrDes.size() > (long unsigned int)sCT)
        buildTreeRecursion(treeFunc->left, index + 1, sizeBasis);
}

void TreeNDimensionalSpace::treeWalk(){
    std::cout << "________________________________________" << std::endl;
    std::cout << "Deph " << 1 << std::endl;
    std::cout << tree.right << std::endl;
    std::cout << tree.left << std::endl;
    std::cout << tree.vec << std::endl;
    std::cout << tree.mat << std::endl;

    for(long unsigned int i = 0; i < tree.arrDes.size(); i++)
        std::cout << "tree.arrDes" << "[" << i << "]" << tree.arrDes[i].des << " " << tree.arrDes[i].index << std::endl;

    if(tree.right != NULL)
        treeWalkRecursion(tree.right, 2);
    if(tree.left != NULL)
        treeWalkRecursion(tree.left, 2);
}

void TreeNDimensionalSpace::treeWalkRecursion(struct Tree* treeFunc, int deph){
    std::cout << "________________________________________" << std::endl;
    std::cout << "Deph " << deph << std::endl;
    std::cout << treeFunc->right << std::endl;
    std::cout << treeFunc->left << std::endl;
    std::cout << treeFunc->vec << std::endl;
    std::cout << treeFunc->mat << std::endl;

    for(long unsigned int i = 0; i < treeFunc->arrDes.size(); i++)
        std::cout << "tree.arrDes" << "[" << i << "]" << treeFunc->arrDes[i].des << " " << treeFunc->arrDes[i].index << std::endl;

    if(treeFunc->right != NULL)
        treeWalkRecursion(treeFunc->right, deph +1);
    if(treeFunc->left != NULL)
        treeWalkRecursion(treeFunc->left, deph +1);
}


//TODO
int TreeNDimensionalSpace::searchTree(cv::Mat des, double threshold){
    return 0;
}


struct Tree TreeNDimensionalSpace::getTree(){
    return tree;
}
