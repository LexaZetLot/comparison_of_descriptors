#ifndef MAIN_HEDER_FILE
#define MAIN_HEDER_FILE

#include <opencv2/core.hpp>
#include <opencv2/core/types.hpp>


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
        int spaceCapacityThreshold;
        double treshold;
        struct Tree tree;
    public:
        TreeNDimensionalSpace(cv::Mat mat, int spaceCapacityThreshold, double treshold);
        void treeBuild();
        void buildTreeRecursion(struct Tree* treeFunc, int index, double sizeBasis);
        void treeWalk();
        void treeWalkRecursion(struct Tree* tree, int deph);
        std::vector<double> searchTree(cv::Mat des);


        void setTree(struct Tree tree);
        struct Tree getTree();

        void setSpaceCapacityThreshold(int spaceCapacityThreshold);
        int getSpaceCapacityThreshold();

        void setThreshold(double treshold);
        double getThreshold();
};

class ComparisonOfDescriptors{
    private:
        int spaceCapacityThreshold;
        double treshold;
    public:
        ComparisonOfDescriptors(int spaceCapacityThreshold, double treshold);
        std::vector<cv::DMatch> match(cv::Mat des1, cv::Mat des2);


        void setSpaceCapacityThreshold(int spaceCapacityThreshold);
        int getSpaceCapacityThreshold();

        void setThreshold(double treshold);
        double getThreshold();
};


#endif
