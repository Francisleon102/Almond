#include <iostream>
#include "opencv4/opencv2/opencv.hpp"
#include "opencv4/opencv2/imgproc.hpp"


class imgproc
{
private:
    
public:
    imgproc(/* args */){};
   
    cv::Mat Gray(cv::Mat & Img){
        if (Img.empty())
        { printf("Gray Function : Image Empty !");   return cv::Mat(); }
         cv::Mat GrayImage = cv::Mat::zeros(Img.size(),CV_8UC1);//gray Image
        (Img.channels() >= 3) ? cv::cvtColor(Img, GrayImage, cv::COLOR_BGR2GRAY) : void();
        cv::imwrite("Images/grayImage.png", GrayImage);
        printf("Gray Function : Sucess\n");
        return  GrayImage;
    }

    cv::Mat Resize(cv::Mat & Img, int h, int w);

    void Contours();

    /// @brief //display Image in Context
    /// @param M 
    void Display(cv::Mat  M); 
    
    //more to come 
    
~imgproc(){printf("Constructor Destryoed");};


};


