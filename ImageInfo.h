#ifndef IMAGEINFO_H
#define IMAGEINFO_H
#include "opencv4/opencv2/opencv.hpp"

class imageInfo {

private:
    // Private member variables can be added here if needed
    // For example, you might want to store the image width, height, and channels
    int width;
    int height;
    int channels;

public:
    
// Constructor
imageInfo(cv::Mat & img) {
    // Initialize the imageInfo object with the image properties
  int width = img.cols; // Get the width of the image
   int  height = img.rows; // Get the height of the image
   int channels = img.channels(); // Get the number of channels in the image

    printf("Image Info: Width = %d, Height = %d, Channels = %d\n", width, height, channels);
};
   
// Copy constructor
imageInfo(const imageInfo & other) {
    // Copy the properties from another imageInfo object
    printf("Copy constructor called.\n");
}
~imageInfo() {
    // Destructor can be used for cleanup if needed 
    printf("ImageInfo object destroyed.\n");

}
};

#endif /* ImageInfo_h */