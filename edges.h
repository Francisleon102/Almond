#ifndef EDGES_H
#define EDGES_H
#include "opencv4/opencv2/opencv.hpp"


class edges {
private:
    // Private member variables can be added here if needed
    int lowThreshold = 100;
    int highThreshold = 200;

public:
    // Constructor
    edges() {
        // Initialize the edges object with the image properties
        printf("Edges object created.\n");
    }
    cv::Mat cannyEdgeDetection(cv::Mat & img, double  & low , double high){
        cv::Mat Cannyedges;
        cv::Canny(img, Cannyedges, low, high,5,1); 
        printf("Canny edge detection applied.\n");
        // Optionally, save or display the edges image
        cv::imwrite("Images/canny_edges_output.jpg", Cannyedges);
        return Cannyedges;
    } 

    void laplacianEdgeDetection(cv::Mat & img) {
        // Perform Laplacian edge detection on the image
        cv::Mat Lapedges;
        cv::Laplacian(img, Lapedges, CV_16S, 3); // Use CV_16S to avoid overflow
        cv::convertScaleAbs(Lapedges, Lapedges); // Convert back to CV_8U
        printf("Laplacian edge detection applied.\n");
        
        // Optionally, save or display the edges image
        cv::imwrite("Images/laplacian_edges_output.jpg", Lapedges);
    }


    void sobelEdgeDetection(cv::Mat & img) {
        // Perform Sobel edge detection on the image
        cv::Mat edgesX, edgesY, edges;
        cv::Sobel(img, edgesX, CV_16S, 1, 0); // Sobel in X direction
        cv::Sobel(img, edgesY, CV_16S, 0, 1); // Sobel in Y direction
        cv::convertScaleAbs(edgesX, edgesX); // Convert back to CV_8U
        cv::convertScaleAbs(edgesY, edgesY); // Convert back to CV_8U
        cv::addWeighted(edgesX, 0.5, edgesY, 0.5, 0, edges); // Combine both directions
        printf("Sobel edge detection applied.\n");
        
        // Optionally, save or display the edges image
        cv::imwrite("Images/sobel_edges_output.jpg", edges);
    }

    void ScharrEdgeDetection(cv::Mat & img) {
        // Perform Scharr edge detection on the image
        cv::Mat edgesX, edgesY, edges;
        cv::Scharr(img, edgesX, CV_16S, 1, 0); // Scharr in X direction
        cv::Scharr(img, edgesY, CV_16S, 0, 1); // Scharr in Y direction
        cv::convertScaleAbs(edgesX, edgesX); // Convert back to CV_8U
        cv::convertScaleAbs(edgesY, edgesY); // Convert back to CV_8U
        cv::addWeighted(edgesX, 0.5, edgesY, 0.5, 0, edges); // Combine both directions
        printf("Scharr edge detection applied.\n");
        
        // Optionally, save or display the edges image
        cv::imwrite("Images/scharr_edges_output.jpg", edges);
    }
   
    // Destructor
    ~edges() {
        // Destructor can be used for cleanup if needed
        printf("Edges object destroyed.\n");
    }


};
class Sliders {




};
#endif /* EDGES_H */