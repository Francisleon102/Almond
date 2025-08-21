
#include "opencv4/opencv2/opencv.hpp"
#include "opencv4/opencv2/highgui.hpp"
#include "opencv4/opencv2/imgproc.hpp"
#include "opencv2/core.hpp"
#include "imgproc.h"
#include <iostream>
#include <stdbool.h>
#include <thread>
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
void on_trackbar(Mat & M);
void imagesRange(int value, void* data);
void videoFrames();

/// @brief Image processing functions here 
/// @param 
imgproc I;

#ifdef _WIN32
cv::VideoCapture cap(0, cv::CAP_DSHOW);
#else
cv::VideoCapture cap(5, cv::CAP_V4L2); // fix indexing 
#endif//or use path /dev/video 



const string path = "Images/cir1.jpg";
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
  
    Mat main_Img = file();
    Mat Img = main_Img.clone();
    //findImgContours(Img); // Call the function to find contours in the image
     //videoFrames();
    on_trackbar(Img);
    printf("Ontrack was called ~");
    return 0;
    
}

void on_trackbar(Mat & M){
   cv::namedWindow("Edges", cv::WINDOW_AUTOSIZE);
    int Max = 200;
    int sliderValue = 110;
    cv::createTrackbar("Slider", "Edges",&sliderValue,Max, imagesRange, &M);  //SilderVslue is mapped to int value in imageRange Function 
        // Add an event loop to keep the window and trackbar responsive
        //I.Display(M);
        int key = cv::waitKey(0);
        if (key == 27) ;// Exit on ESC
    
    cv::destroyWindow("Edges");
}


void findImgContours(Mat & Img){
    Mat C = I.Gray(Img);
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(C, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);
    cv::Mat contourImage = cv::Mat::zeros(Img.size(), CV_8UC3);
    drawContours(contourImage,contours, -1, Scalar(0, 255, 0), cv::FILLED); // Draw all contours in green
    imwrite("Contours.jpg", contourImage); // Save the image with contours drawn
    std::cout << "Found contours: " << contours.size() << "\n";
    

};

 //could use some asyncronos programming 
 /// @brief adjust values for image out puts 
 void imagesRange(int value, void* data){
    Mat & Img = *static_cast<Mat*>(data) ;  // castiing *data to Mat 
    double low = static_cast<double>(value);
    edges e;
    Mat t = e.cannyEdgeDetection(Img, low,200);
   // e.laplacianEdgeDetection(Img);
    I.Display(t);
    
 }

 void videoFrames(){
    Mat frames; 
     // Set MJPEG mode explicitly (fourcc 'MJPG')
    cap.set(cv::CAP_PROP_FOURCC, cv::VideoWriter::fourcc('M','J','P','G'));
    cap.set(cv::CAP_PROP_FRAME_WIDTH, 1280);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 720);
    cap.set(cv::CAP_PROP_FPS, 120); 
    while(true){
    cap >> frames;
    if (!cap.isOpened()) {
        std::cerr << "Camera not opened.\n";
        break;
    }
          cv::imshow("MJPEG Camera", frames);
        if (cv::waitKey(1) == 'q') break;

 }
  
   cap.release();
    cv::destroyAllWindows();
}
   

