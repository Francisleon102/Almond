// main.cpp
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

// --- our helper (define it before main or put in a header you include) ---
Point2d findCenter(const Mat &binaryMask) {
    CV_Assert(binaryMask.type() == CV_8UC1);
    Moments m = moments(binaryMask, /*binaryImage=*/true);
    if (m.m00 == 0) return Point2d(-1, -1);
    return Point2d(m.m10 / m.m00, m.m01 / m.m00);
}

int main() {
    Mat I = imread("Images/canny_edges_output.jpg", IMREAD_GRAYSCALE);
    if (I.empty()) { cerr << "Could not read cir1.jpg\n"; return 1; }

    // make a binary mask (tune these to your image)
    Mat bw;
    adaptiveThreshold(I, bw, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 31, -5);
    // optional cleanups similar to MATLAB:
    // - clear border-ish (skip for brevity)
    // - remove tiny blobs
    Mat labels, stats, cents;
    int n = connectedComponentsWithStats(bw, labels, stats, cents, 8, CV_32S);
    for (int i = 1; i < n; ++i) { // skip background
        if (stats.at<int>(i, CC_STAT_AREA) < 20) {
            bw.setTo(0, labels == i);
        }
    }
    // fill holes
    {
        Mat inv; bitwise_not(bw, inv);
        Mat flood = inv.clone();
        copyMakeBorder(flood, flood, 1,1,1,1, BORDER_CONSTANT, Scalar(0));
        floodFill(flood, Point(0,0), Scalar(255));
        flood = flood(Rect(1,1,bw.cols,bw.rows));
        Mat holes; bitwise_not(flood, holes);
        bitwise_or(bw, holes, bw);
    }

    // now find center on the filled binary
    Point2d c = findCenter(bw);

    // visualize
    Mat vis; cvtColor(I, vis, COLOR_GRAY2BGR);
    if (c.x >= 0) {
        drawMarker(vis, c, Scalar(0,0,255), MARKER_CROSS, 12, 2);
        cout << "Center: (" << c.x << ", " << c.y << ")\n";
    } else {
        cout << "No foreground found.\n";
    }
    imshow("binary", bw);
    imshow("center", vis);
    waitKey(0);
    return 0;
}



