#include <linux/videodev2.h>
#include "opencv4/opencv2/videoio.hpp"
#include <iostream>
#include <vector>
#include <thread>
#include "camera.hpp"
#include "opencv4/opencv2/core.hpp"
#include <opencv2/highgui.hpp>
#include <unistd.h>

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
std::vector<int> count;

void videoFrames(int index, int slots);
std::vector<cv::Mat> frames;
std::mutex frameMutex;
void initialize() {
    for (size_t i = 0; i < 10; i++) {
        // Suppress OpenCV error output by redirecting stderr
       fflush(stderr);
       int old_stderr = dup(fileno(stderr));
       freopen("/dev/null", "w", stderr);
        cv::VideoCapture cap(i, CAP_ANY);
        // Restore stderr
       fflush(stderr);
        dup2(old_stderr, fileno(stderr));
        close(old_stderr);
        if (cap.isOpened()) {
            count.push_back(i);
            cap.release();

        }
        
    }
}

int camera() {
    initialize();
    std::vector<std::thread> threads;
    for (size_t i = 0; i < count.size() ; i++) {
        std::cout << "Opening camera index: " << count[i] << std::endl;
        threads.emplace_back(videoFrames, count[i],i);
    }
    // Optionally, join threads if you want to wait for them (will block until all windows are closed)
    for (auto& t : threads) {
        if (t.joinable()) t.join();
        std::cout << "Thread ID: " << std::this_thread::get_id() << std::endl;
    }
    return 0;
    
}


void videoFrames(int index, int slot){
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
    if (frames.empty() ) {
        std::cerr << "Camera not opened.\n";
        break;
    }else 
    {

          {
            std::lock_guard<std::mutex> lock(frameMutex);
            frame.copyTo(frames[slot]);  // update shared slot
        }
    }
        cv::imshow(windowName, frames);
        if (cv::waitKey(1) == 'q') break;

 }
  
   cap.release();
    cv::destroyAllWindows();
}
   
