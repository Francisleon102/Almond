#include "opencv4/opencv2/core.hpp"
#include "opencv4/opencv2/opencv.hpp"
#include "opencv4/opencv2/highgui.hpp"
using namespace std;
using namespace cv;



using namespace cv;
using namespace std;
cv::VideoCapture cap(0, cv::CAP_V4L2); //or use path /dev/video 

int main() {
// Open the default camera Linux videom driver



    // Check if the camera opened successfully
    if (!cap.isOpened()) {
        cerr << "Error: Could not open video stream." << endl;
        return -1;
    }

    while (true) {
        Mat frame;
        cap.read(frame);

        if (frame.empty()) {
            cerr << "Error: Blank frame grabbed." << endl;
            break;
        }

        imshow("Test OpenCV Window", frame);

        // Exit the loop if any key is pressed
        if (waitKey(30) >= 0) break;
        
    }

    // Release the camera and close windows
    cap.release();
    destroyAllWindows();

    return 0;
}