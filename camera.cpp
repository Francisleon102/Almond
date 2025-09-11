#include <linux/videodev2.h>
#include "opencv4/opencv2/videoio.hpp"
#include <iostream>
#include <vector>

std::vector<int> count;

void camCount() {
    for (size_t i = 0; i < 10; i++) {
        cv::VideoCapture cap(i, cv::CAP_V4L2);
        if (cap.isOpened()) {
            count.push_back(i);
            cap.release();
        }
    }
    for (size_t i = 0; i < count.size(); i++) {
        std::cout << count[i] << std::endl;
    }
}

int main() {
    camCount();
    return 0;
}
