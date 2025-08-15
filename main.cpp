
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
int getWorkingCameraIndex();

/// @brief Image processing functions here 
/// @param 
imgproc I;

int getWorkingCameraIndex() {
    int maxIndex = 10;
    for (int i = 0; i < maxIndex; ++i) {
        cv::VideoCapture testCap(i, cv::CAP_V4L2);
        if (testCap.isOpened()) {
            testCap.release();
            return i;
        }
    }
    return -1; // No working camera found


}



#ifdef _WIN32
cv::VideoCapture cap(getWorkingCameraIndex(), cv::CAP_DSHOW);
#else
cv::VideoCapture cap(getWorkingCameraIndex(), cv::CAP_V4L2); // fix indexing 
#endif//or use path /dev/video 



const string path = "Images/Denoised/non_local.png";
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
     videoFrames();
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
    cv::threshold(C, C,200,255,2);
    I.Display(C);

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
   

