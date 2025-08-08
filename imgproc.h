#include <iostream>
#include "opencv4/opencv2/opencv.hpp"
#include "opencv4/opencv2/imgproc.hpp"


class imgproc
{
private:
    
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


