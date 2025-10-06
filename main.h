// ...existing code...
#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include "opencv4/opencv2/core/ocl.hpp"

template <typename T = cv::Mat>
class Atype {
public:
    Atype() = default;

    T init() {
        if (cv::ocl::haveOpenCL()) {
            cv::ocl::Context context;
            context.create(cv::ocl::Device::TYPE_GPU);
            std::cout << "OpenCL Device: " << context.device(0).name() << std::endl;


        } else {
            std::cout << "OpenCL not available" << std::endl;
        }
        return T(); // construct and return a T instance
    }

    ~Atype() = default;
};

#endif // MAIN_H
// ...existing code...