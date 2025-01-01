#include "mainHederFile.hpp"
#include <opencv2/opencv.hpp>


int main(){
    cv::Mat img1 = cv::imread("img1.jpg", cv::IMREAD_COLOR);
    cv::Mat img2 = cv::imread("img2.jpg", cv::IMREAD_COLOR);

    cv::Ptr<cv::SIFT> sift = cv::SIFT::create();

    std::vector<cv::KeyPoint> kep1;
    std::vector<cv::KeyPoint> kep2;
    cv::Mat des1;
    cv::Mat des2;

    sift->detectAndCompute(img1, cv::noArray(), kep1, des1);
    sift->detectAndCompute(img2, cv::noArray(), kep2, des2);

    ComparisonOfDescriptors comparisonOfDescriptors(10, 0.4);
    std::vector<cv::DMatch> matches = comparisonOfDescriptors.match(des1, des2);

    cv::Mat imgMatches;
    cv::drawMatches(img1, kep1, img2, kep2, matches, imgMatches,
                    cv::Scalar::all(-1), cv::Scalar::all(-1), std::vector<char>(),
                    cv::DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
    cv::imshow("img", imgMatches);
    cv::imwrite("imgMatch.jpg", imgMatches);
    cv::waitKey(0);
    cv::destroyAllWindows();


    return 0;
}
