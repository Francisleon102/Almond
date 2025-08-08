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
}
}