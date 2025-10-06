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
    count.clear();
    for (size_t i = 0; i <= 10; i++) {
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
    return static_cast<int>(count.size());
}



void  Camera::camera() {
    initialize();
    std::vector<std::thread> threads;
    // allocate frames slots
    frames.resize(count.size());
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
    Mat frame ;
     // Set MJPEG mode explicitly (fourcc 'MJPG')
    cap.set(cv::CAP_PROP_FOURCC, cv::VideoWriter::fourcc('M','J','P','G'));
    cap.set(cv::CAP_PROP_FRAME_WIDTH, 1280);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 720);
    cap.set(cv::CAP_PROP_FPS, 120); 
    while(true){
    cap >> frame;
    if (frame.empty() ) {
        std::cerr << "Empty frame for camera " << index << "\n";
        break;
    } else {
        std::lock_guard<std::mutex> lock(frameMutex);
        frame.copyTo(frames[slot]);  // update shared slot
    }
        // show only this camera's frame
        {
            std::lock_guard<std::mutex> lock(frameMutex);
            cv::imshow(windowName, frames[slot]);
        }
        if (cv::waitKey(1) == 'q') break;

 }
  
   cap.release();
    cv::destroyAllWindows();
    
}

