#include "imgproc.h"
#include "opencv4/opencv2/opencv.hpp"
#include "opencv4/opencv2/imgproc.hpp"

using namespace cv;
void imgproc::Contours()
{
}

void imgproc::Display(cv::Mat M){
 if (M.empty())
{printf("Display Function : Empty");  return ; }
else {

    resize(M, M, Size(640, 480));
    imshow("Conext",M);
    // Wait for ESC key to exit
        while (true) {
            int key = cv::waitKey(30);
            if (key == 27) { // 27 is the ASCII code for ESC
                break;
            }
        }
        cv::destroyWindow("Conext");
    
}

}