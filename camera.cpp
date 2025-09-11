#include <linux/videodev2.h>
#include "opencv4/opencv2/videoio.hpp"
#include <iostream>
#include <vector>
#include <thread>
#include "opencv4/opencv2/core.hpp"
#include <opencv2/highgui.hpp>

using namespace cv;
std::vector<int> count;

void videoFrames(int index);

void camCount(bool opencam = 0) {
    for (size_t i = 0; i < 10; i++) {
        cv::VideoCapture cap(i, cv::CAP_V4L2);
        if (cap.isOpened()) {
            count.push_back(i);
            cap.release();
        }
    }
    for (size_t i = 0; i < count.size(); i++) {

        if (opencam)
        {
            std::cout << count[i] << std::endl;
          
           std::thread t (videoFrames, count[i]);
           t.detach();
        }
        else{
            std::cout << count[i] << count.size() <<  std::endl;
        }
        
        
    }
}

int main() {
    camCount();
    return 0;
}


void videoFrames(int index){
      cv::VideoCapture cap(index, cv::CAP_V4L2);
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
   
