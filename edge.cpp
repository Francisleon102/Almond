#include "edges.h"
#include "opencv4/opencv2/opencv.hpp"


//edges edge(cv::Mat & Img);

void cannyEdgeDetection(cv::Mat &img )
    {
        // Perform Canny edge detection on the image
        cv::Mat edges;
        cv::Canny(img, edges, 100, 200); // Adjust thresholds as needed
        printf("Canny edge detection applied.\n");
        // Optionally, save or display the edges image
        cv::imwrite("Images/edges_output.jpg", edges);
        
    }
