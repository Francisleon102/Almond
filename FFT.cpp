#include <opencv2/opencv.hpp>
using namespace cv;

int main() {
    Mat img = imread("Images/frame.jpg", IMREAD_GRAYSCALE);
   std::cout << system("v4l2-ctl --list-devices") << std::endl;

    if (img.empty()) {
        printf("Image not found!\n");

        
    return 0;
        return -1;
    }

    // Expand to optimal size
    Mat padded;
    int m = getOptimalDFTSize(img.rows);
    int n = getOptimalDFTSize(img.cols);
    copyMakeBorder(img, padded, 0, m - img.rows, 0, n - img.cols, BORDER_CONSTANT, Scalar::all(0));

    // Make planes and merge into a complex image
    Mat planes[] = {Mat_<float>(padded), Mat::zeros(padded.size(), CV_32F)};
    Mat complexImg;
    merge(planes, 2, complexImg);

    // Perform DFT
    dft(complexImg, complexImg);

    // Shift the zero-frequency component to the center
    int cx = complexImg.cols / 2;
    int cy = complexImg.rows / 2;
    Mat q0(complexImg, Rect(0, 0, cx, cy));
    Mat q1(complexImg, Rect(cx, 0, cx, cy));
    Mat q2(complexImg, Rect(0, cy, cx, cy));
    Mat q3(complexImg, Rect(cx, cy, cx, cy));
    Mat tmp;
    q0.copyTo(tmp); q3.copyTo(q0); tmp.copyTo(q3);
    q1.copyTo(tmp); q2.copyTo(q1); tmp.copyTo(q2);

    // Create a low-pass filter mask (center square is 1, rest is 0)
    Mat mask = Mat::zeros(complexImg.size(), CV_32F);
    int r = complexImg.rows / 5; // radius of low frequencies to keep
    int c = complexImg.cols / 5;
    mask(Rect(cx - c, cy - r, 2 * c, 2 * r)).setTo(1);

    // Apply mask to both real and imaginary parts
    Mat mask_planes[] = {mask, mask};
    Mat mask_complex;
    merge(mask_planes, 2, mask_complex);
    multiply(complexImg, mask_complex, complexImg);

    // Shift back
    q0.copyTo(tmp); q3.copyTo(q0); tmp.copyTo(q3);
    q1.copyTo(tmp); q2.copyTo(q1); tmp.copyTo(q2);

    // Inverse DFT to get denoised image
    Mat invDFT;
    idft(complexImg, invDFT, DFT_SCALE | DFT_REAL_OUTPUT);

    // Crop to original size and normalize
    invDFT = invDFT(Rect(0, 0, img.cols, img.rows));
    normalize(invDFT, invDFT, 0, 255, NORM_MINMAX);
    invDFT.convertTo(invDFT, CV_8U);

    imshow("Input", img);
    imshow("Denoised (Low-pass FFT)", invDFT);
    imwrite("FFT_denoised.png", invDFT);
    waitKey(0);
    return 0;

    /// g++ temp.cpp -o temp `pkg-config --cflags --libs opencv4`
}