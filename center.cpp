#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // === Adjustable parameters ===
    int rmin      = 6;      // Min circle radius (px)
    int rmax      = 30;     // Max circle radius (px)
    double dp     = 1.0;    // Accumulator resolution inverse ratio
    double minDist = 10;    // Min center distance (px)
    double param1 = 100;    // Canny high threshold (low = param1/2)
    double param2 = 30;     // Accumulator threshold (lower → more sensitive)

    // --- Load image ---
    cv::Mat I = cv::imread("Images/gray_image.jpg", cv::IMREAD_COLOR);
    if (I.empty()) {
        std::cerr << "Could not read image\n";
        return -1;
    }

    // --- Convert to grayscale ---
    cv::Mat G;
    cv::cvtColor(I, G, cv::COLOR_BGR2GRAY);

    // --- Detect circles ---
    std::vector<cv::Vec3f> circles;
    cv::HoughCircles(G, circles, cv::HOUGH_GRADIENT, dp, minDist,
                     param1, param2, rmin, rmax);

    // --- Print radii ---
    std::cout << "Detected radii (px):\n";
    for (auto &c : circles) {
        std::cout << c[2] << "\n";
    }

    // --- Display original ---
    cv::imshow("Original Image", I);

    // --- Display grayscale + red '+' at centers ---
    cv::Mat grayBGR;
    cv::cvtColor(G, grayBGR, cv::COLOR_GRAY2BGR);

    for (auto &c : circles) {
        cv::Point center(cvRound(c[0]), cvRound(c[1]));
        int s = 5; // size of plus sign arms
        cv::line(grayBGR, {center.x - s, center.y}, {center.x + s, center.y}, {0, 0, 255}, 2);
        cv::line(grayBGR, {center.x, center.y - s}, {center.x, center.y + s}, {0, 0, 255}, 2);
    }

    std::string title = "Detected " + std::to_string(circles.size()) + " circles";
    cv::imshow(title, grayBGR);
    cv::imwrite("Images/gray_cur.jpg",grayBGR);

    cv::waitKey(0);
    return 0;
}
