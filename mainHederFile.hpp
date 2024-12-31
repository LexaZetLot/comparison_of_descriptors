#ifndef MAIN_HEDER_FILE
#define MAIN_HEDER_FILE

#include <opencv2/core.hpp>


cv::Mat linearCoefficients(cv::Mat matBasis, cv::Mat vecT, cv::Mat des);
bool isVecInNDimensionalSpace(cv::Mat vec);
double LNorm(cv::Mat des1, cv::Mat des2);

struct MatArray{
    cv::Mat des;
    int index;
};

struct Tree{
    cv::Mat mat;
    cv::Mat vec;
    std::vector<MatArray> arrDes;

    struct Tree *left;
    struct Tree *right;
};

class TreeNDimensionalSpace{
    private:
        int sCT;
        struct Tree tree;
    public:
        TreeNDimensionalSpace(cv::Mat mat, int spaceCapacityThreshold);
        void treeBuild();
        void buildTreeRecursion(struct Tree* treeFunc, int index, double sizeBasis);
        void treeWalk();
        void treeWalkRecursion(struct Tree* tree, int deph);
        int searchTree(cv::Mat des, double threshold);

        struct Tree getTree();
};


#endif
