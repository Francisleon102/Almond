#include <cstdio>
#include <ostream>

#include "opencv4/opencv2/core.hpp"
#include "opencv4/opencv2/opencv.hpp"
#include "opencv4/opencv2/highgui.hpp"
using namespace std;
using namespace cv;




void invertImage(cv::Mat& img){
uchar * ptr = img.ptr<uchar>(320,240);
cout << &ptr << "value at : "<< *ptr +2 << endl;
printf("%d",*ptr);
}

VideoCapture Video(0, cv::CAP_DSHOW);

int main() {
    // Create a black image (480x640, 3 channels, 8-bit)
    cv::Mat img = cv::Mat::zeros(480, 640, CV_8UC3);




    // Draw a green circle in the center
    cv::circle(img, cv::Point(320, 240), 100, cv::Scalar(0, 255, 0), -1);

    invertImage(img);

    // Show the image
    cv::imshow("Test OpenCV Window", img);
    cv::waitKey(0); // Wait for a key press

   

    return 0;
}