
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
#include "camera.h"

using namespace std;
using namespace cv;

// Function Prototypes
template<typename T>
void findImgContours(T & Img);
void imgtoGrey(Mat & Img);
void on_trackbar(Mat & M);
void imagesRange(int value, void* data);
void videoFrames();

/// @brief Image processing functions here 
/// @param 
imgproc I;

  /// @brief Camera Handlin
  Camera cam;



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
    findImgContours(Img); // Call the function to find contours in the image
    //videoFrames();
    // Instantiate the template with a concrete type. Use cv::Mat here as an example.
    Atype A;
    A.init();
    //on_trackbar(Img);
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
    
    
Camera cam;
int found = cam.initialize();
std::cout << "Found cameras: " << found << ", cam.count.size(): " << cam.count.size() << ", cam.frames.size(): " << cam.frames.size() << "\n";
cam.camera();

}

// Templated findImgContours to accept cv::Mat or cv::UMat
template<typename T>
void findImgContours(T & Img) {
    // If T is UMat, call UMat Gray and download to Mat for processing
    Mat C;
    if constexpr (std::is_same_v<T, cv::Mat>) {
        C = I.Gray(Img);
    } else {
        cv::UMat u = I.Gray(Img);
        u.copyTo(C);
    }
    if (C.empty()) {
        std::cerr << "findImgContours: gray image empty\n";
        return;
    }
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(C, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);
    cv::Mat contourImage = cv::Mat::zeros(Img.size(), CV_8UC3);
    drawContours(contourImage, contours, -1, Scalar(0, 255, 0), cv::FILLED);
    imwrite("Contours.jpg", contourImage);
    std::cout << "Found contours: " << contours.size() << "\n";
}
    // Destructor will be called automatically when cam goes out of scope
    
 


   

