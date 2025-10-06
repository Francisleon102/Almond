#include <iostream>
#include "opencv4/opencv2/opencv.hpp"
#include "opencv4/opencv2/imgproc.hpp"


class imgproc
{
private:
struct display_resolution   //different preset display resolutions 
{
    // Use brace-init for resolution elements.
     std::vector<int> width = {1920, 1280, 640};
    std::vector<int> height = {1080, 720, 480};
     std::vector<int> fps = {30, 60, 120};
};display_resolution p;

    
public:
    imgproc(/* args */){};
   
    cv::Mat Gray(cv::Mat & Img);
    cv::Mat Resize(cv::Mat & Img, int h, int w);
    void Contours();
    /// @brief //display Image in Context
    /// @param M 
    void Display(cv::Mat & M); 

    //more to come 
    
    
~imgproc(){printf("Constructor Destryoed");};


};


