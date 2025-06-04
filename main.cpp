#include "opencv4/opencv2/core.hpp"
#include "sysexits.h"
#include "opencv4/opencv2/opencv.hpp"
#include "opencv4/opencv2/highgui.hpp"
#include "libv4l2.h"
#include "ImageInfo.h"
#include "main.h"
using namespace std;
using namespace cv;

void findImgContours(Mat & Img);

cv::VideoCapture cap(0, cv::CAP_V4L2); //or use path /dev/video 

const string path = "Images/test.jpg";
// Function to read an image from a file
Mat file() {
    Mat img = imread(path, IMREAD_COLOR);
   // Check if the image is empty
        if (img.empty()) {
            printf("Error: Image is empty.\n");
            exit(EX_NOINPUT); // Exit with an error code if the image cannot be loaded
        }
    return img;
}

int main() {
Mat Img = file();
findImgContours(Img); // Call the function to find contours in the image

    return 0;
}

 // Read the image from file
void findImgContours(Mat & Img){
    
 imageInfo imgInfo(Img); // Create an instance of imageInfo to get image properties

}