// Example 2-7. The Canny edge detector writes its output to a single-channel (grayscale) image
// 2
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char **argv) {
    const Mat &mat = imread("/home/lion/1.png", -1);
    circle(mat, Point(0, 0), 100, Scalar(0, 0, 255, 1));
    putText(mat, "ABC", Point(500, 500), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255, 0, 0, 1));
    cvNamedWindow("test01", cv::WINDOW_AUTOSIZE);
    int rows = mat.rows;
    int cols = mat.cols;
    for (int i = 0; i < rows / 100; ++i) {
        line(mat, Point(0, i * 100), Point(cols, i * 100), Scalar(0, 255, 0, 1));
    }
    imshow("test01", mat);
    waitKey(0);
}
