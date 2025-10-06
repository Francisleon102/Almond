#ifndef CAMERA_HPP
#define CAMERA_HPP

// camera.hpp

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include "opencv4/opencv2/core.hpp"
#include <opencv2/highgui.hpp>
#include <unistd.h>

// Description: Camera class declaration

class Camera {
public:
	Camera();

	// Copy constructor and assignment
	Camera(const Camera& other);

	void camera();
	int initialize();
    std::vector <cv::Mat> grabFrames();
	std::vector<int> count;
	void videoFrames(int index, int slots);
	std::vector<cv::Mat> frames;
	std::mutex frameMutex;
	~Camera() = default;
private:
    
};

#endif // CAMERA_HPP