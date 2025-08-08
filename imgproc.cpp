#include "imgproc.h"
#include "opencv4/opencv2/opencv.hpp"
#include "opencv4/opencv2/imgproc.hpp"

using namespace cv;
void imgproc::Contours()
{
}

void imgproc::Display(cv::Mat &M){
 if (M.empty())
{printf("Display Function : Empty");  return ; }
else {
    resize(M, M, Size(640, 480));
    imshow("Output", M);}
}



Mat imgproc::Gray(cv::Mat & Img){
        if (Img.empty())
        { printf("Gray Function : Image Empty !");   return cv::Mat(); }
         cv::Mat GrayImage = cv::Mat::zeros(Img.size(),CV_8UC1);//gray Image
        (Img.channels() >= 3) ? cv::cvtColor(Img, GrayImage, cv::COLOR_BGR2GRAY) : void();
        cv::imwrite("Images/grayImage.png", GrayImage);
        printf("Gray Function : Sucess\n");
        return  GrayImage;
}