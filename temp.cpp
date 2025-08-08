#include <opencv2/opencv.hpp>
using namespace cv;

int main() {
    Mat img = imread("Images/frame.jpg", IMREAD_GRAYSCALE);
    if (img.empty()) {
        printf("Image not found!\n");
        return -1;
    }

    // Apply Gaussian Blur for denoising
    Mat denoised;
    GaussianBlur(img, denoised, Size(5, 5), 1.5);

    imshow("Input", img);
    imshow("Denoised (Gaussian Blur)", denoised);
    imwrite("non_local.png",denoised);
    waitKey(0);
    return 0;
}