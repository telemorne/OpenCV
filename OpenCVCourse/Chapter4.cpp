#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Adding circles rectangles and lines


void main() {

	Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));
	circle(img, Point(256, 256), 155, Scalar(0, 0, 0),FILLED);
	rectangle(img, Point(130, 226), Point(382, 286), Scalar(255, 255, 255), FILLED);
	line(img, Point(130, 269), Point(382, 450), Scalar(122, 14, 29),2);
	putText(img, "Frere Jacques", Point(138, 252), FONT_HERSHEY_DUPLEX, 0.5, Scalar(0, 0, 0), 2);

	imshow("Image", img);

	waitKey(0);

	
}


