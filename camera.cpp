#include <linux/videodev2.h>
#include "opencv4/opencv2/videoio.hpp"
#include <iostream>
#include <vector>
#include <thread>
#include "opencv4/opencv2/core.hpp"
#include <opencv2/highgui.hpp>
#include <unistd.h>

using namespace cv;
std::vector<int> count;

void videoFrames(int index);

void camCount(bool opencam = true) {
    for (size_t i = 0; i < 10; i++) {
        // Suppress OpenCV error output by redirecting stderr
       // fflush(stderr);
       // int old_stderr = dup(fileno(stderr));
       // freopen("/dev/null", "w", stderr);
        cv::VideoCapture cap(i, cv::CAP_V4L2);
        // Restore stderr
       // fflush(stderr);
        //dup2(old_stderr, fileno(stderr));
        //close(old_stderr);
        if (cap.isOpened()) {
            count.push_back(i);
            cap.release();
        }
    }
}

int main() {
    camCount();

    std::vector<std::thread> threads;
    for (size_t i = 0; i < count.size() ; i++) {
        std::cout << "Opening camera index: " << count[i] << std::endl;
        threads.emplace_back(videoFrames, count[i]);
    }
    // Optionally, join threads if you want to wait for them (will block until all windows are closed)
    for (auto& t : threads) {
        if (t.joinable()) t.join();
    }
    return 0;
}


void videoFrames(int index){
      cv::VideoCapture cap(index, cv::CAP_V4L2);
      std::string windowName = "MJPEG Camera " + std::to_string(index);  ///window names depending on how many fr
    Mat frames; 
     // Set MJPEG mode explicitly (fourcc 'MJPG')
    cap.set(cv::CAP_PROP_FOURCC, cv::VideoWriter::fourcc('M','J','P','G'));
    cap.set(cv::CAP_PROP_FRAME_WIDTH, 1280);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 720);
    cap.set(cv::CAP_PROP_FPS, 120); 
    while(true){
    cap >> frames;
    if (frames.empty() ) {
        std::cerr << "Camera not opened.\n";
        break;
    }else 

        cv::imshow(windowName, frames);
        if (cv::waitKey(1) == 'q') break;

 }
  
   cap.release();
    cv::destroyAllWindows();
}
   
