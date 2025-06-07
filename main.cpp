#include "opencv4/opencv2/core.hpp"
#include "opencv4/opencv2/opencv.hpp"
#include "opencv4/opencv2/highgui.hpp"
#include "opencv4/opencv2/imgproc.hpp"
#include <sysexits.h>
#include "ImageInfo.h"
#include "edges.h"
#include <vector>
#include "main.h"
using namespace std;
using namespace cv;


void findImgContours(Mat & Img);
void imgtoGrey(Mat & Img);

cv::VideoCapture cap(0, cv::CAP_V4L2); //or use path /dev/video 

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
    return 0;
}


void colorToGray(Mat & Img) {
    if (!Img.empty()) {
        cvtColor(Img, Img, COLOR_BGR2GRAY); // Convert the image to grayscale
        printf("Image converted to grayscale.\n");
    } else {
        printf("Error: Image is empty.\n");
    }
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
/*
    //edge object
    // Apply Canny edge detection
    edges edgeDetector(Img);
    edgeDetector.cannyEdgeDetection(Img);
    // Perform Canny edge detection on the image
    edgeDetector.laplacianEdgeDetection(Img);
    // Perform Laplacian edge detection on the image

    edgeDetector.sobelEdgeDetection(Img); // Perform Sobel edge detection on the image
    edgeDetector.ScharrEdgeDetection(Img); // Perform Scharr edge detection on the image
*/
};
 // Create an edges object with the image


 //could use some asyncronos programming 
 void cannyslider(int & lowthreshold , int & highthreshold, Mat & Img){
    
    edges edge(Img);
    void (edges::*cannif)(Mat&) = &edges::cannyEdgeDetection;
    (edge.*cannif)(Img);

 }

