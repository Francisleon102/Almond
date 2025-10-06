#include <linux/videodev2.h>
#include "opencv4/opencv2/videoio.hpp"
#include <iostream>
#include <vector>
#include <thread>
#include "camera.h"
#include "opencv4/opencv2/core.hpp"
#include <opencv2/highgui.hpp>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

/*

#ifdef _WIN32
cv::VideoCapture cap(0, cv::CAP_DSHOW);
#elif __APPLE__
cv::VideoCapture cap(0, cv::CAP_AVFOUNDATION);
#else
cv::VideoCapture cap(2, cv::CAP_V4L2); // fix indexing
#endif // or use path /dev/video

*/
using namespace cv;



Camera::Camera(){
    // default constructor
}

int Camera::initialize() {
    
    for (size_t i = 0; i <= 10; ++i) {
        // Suppress OpenCV error output by redirecting stderr
       fflush(stderr);
       int old_stderr = dup(fileno(stderr));
       freopen("/dev/null", "w", stderr);
        cv::VideoCapture cap(static_cast<int>(i), cv::CAP_ANY);
        // Restore stderr
       fflush(stderr);
        dup2(old_stderr, fileno(stderr));
        close(old_stderr);
        if (cap.isOpened()) {
            count.push_back(static_cast<int>(i));
            cap.release();
            
        }
    }
    frames.resize(count.size());
    return static_cast<int>(count.size());
}



void  Camera::camera() {
    initialize();
    std::vector<std::thread> threads;
    // allocate frames slots
   
    for (size_t i = 0; i < count.size() ; i++) {
        std::cout << "Opening camera index: " << count[i] << std::endl;
        threads.emplace_back(&Camera::videoFrames, this, count[i], (int)i);
    }
    // Optionally, join threads if you want to wait for them (will block until all windows are closed)
    for (auto& t : threads) {
        if (t.joinable()) t.join();
        std::cout << "Thread joined" << std::endl;
    }
    
    
}


void Camera::videoFrames(int index, int slot){
      cv::VideoCapture cap(index, cv::CAP_ANY);
      std::string windowName = "MJPEG Camera " + std::to_string(index);  ///window names depending on how many fr
 // frames to smal size of 8 bits
    Mat frame  = Mat::zeros(720,1280, CV_8UC1);
     // Set MJPEG mode explicitly (fourcc 'MJPG')
    cap.set(cv::CAP_PROP_FOURCC, cv::VideoWriter::fourcc('M','J','P','G')); //using Video Wriitter MPEG 
    cap.set(cv::CAP_PROP_FRAME_WIDTH, p.width[1]);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, p.height[1]);
    cap.set(cv::CAP_PROP_FPS, p.fps[1]); 
    while(true){
    cap >> frame;
    if (frame.empty() ) {
        std::cerr << "Empty frame for camera " << index << "\n";
        break;
    } else {
        std::lock_guard<std::mutex> lock(frameMutex);
        frame.copyTo(frames[slot]);  // this updates frame vector based on thread ID, giving  vector of frames based on  inidivla frames found. 
    }
        // show only this camera's frame
        {
            std::lock_guard<std::mutex> lock(frameMutex);  // stop access to threads 
            cv::imshow(windowName, frames[slot]);
        }
        if (cv::waitKey(1) == 'q') break;

 }
  
   cap.release();
    cv::destroyAllWindows();
    
}

