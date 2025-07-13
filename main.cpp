
#include "opencv4/opencv2/opencv.hpp"
#include "opencv4/opencv2/highgui.hpp"
#include "opencv4/opencv2/imgproc.hpp"
#include "opencv2/core.hpp"
#include <iostream>
#include <sysexits.h>
#include "ImageInfo.h"
#include "edges.h"
#include <vector>
#include "main.h"
#include <dlfcn.h>



using namespace std;
using namespace cv;



// Function Prototypes
void findImgContours(Mat & Img);
void imgtoGrey(Mat & Img);
void on_trackbar(int, void*);


#ifdef _WIN32
cv::VideoCapture cap(0, cv::CAP_DSHOW);
#else
cv::VideoCapture cap(0, cv::CAP_V4L2);
#endif//or use path /dev/video 

const string path = "Images/test.jpg";
// Function to read an image from a file
Mat file() {
    Mat img = imread(path, IMREAD_COLOR);
        if (img.empty()) {
            printf("Error: Image is empty.\n");
            exit(EX_NOINPUT); // Exit with an error code if the image cannot be loaded
        }
    return img;
}

int main() {
    Mat Img = file();
    findImgContours(Img); // Call the function to find contours in the image

    Mat * Imgcopy = &Img;
   on_trackbar(0, Imgcopy);
    
    return 0;
    
}


Mat colorToGray(Mat & Img) {
    Mat grayImg = Mat::zeros(Img.size(), CV_8UC1); // Create a grayscale image with the same size as the input image
    if (!Img.empty()) {
        cvtColor(Img, grayImg, COLOR_BGR2GRAY); // Convert the image to grayscale
        printf("Image converted to grayscale.\n");
        imwrite("Images/gray_image.jpg", grayImg); // Save the grayscale image
    } else {
        printf("Error: Image is empty.\n");
    }
    return grayImg; // Return the grayscale image
}

void findImgContours(Mat & Img){
    if (Img.channels() != 3) {
        printf("Error: Image must have 3 channels (RGB).\n");

    }else {
        colorToGray(Img); // Convert the image to grayscale before finding contours
        printf("Image is ready for contour detection.\n");

        
    }

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    /*
    +findContours(Img, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);
    +cv::Mat contourImage = cv::Mat::zeros(Img.size(), CV_8UC3);
    +drawContours(contourImage,contours, -1, Scalar(0, 255, 0), cv::FILLED); // Draw all contours in green
    +imwrite("Contours.jpg", contourImage); // Save the image with contours drawn
    +std::cout << "Found contours: " << contours.size() << "\n";
    */


};
 // Create an edges object with the image
 //could use some asyncronos programming 
 void imagesRange(int value, void* data){
    Mat & Img = *static_cast<Mat*>(data) ;
    edges e;
    e.cannyEdgeDetection(Img);
    
 }

 void on_trackbar(int v, void*) {
     printf("Trackbar value changed.\n");
    cv::namedWindow("Edges", cv::WINDOW_AUTOSIZE);
    int Max = 200;
    cv::createTrackbar("Slider", "Edges",&v,Max, imagesRange);

 }
   
   

