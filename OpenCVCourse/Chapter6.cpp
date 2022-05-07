#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Color Detection
Mat imgHSV, mask;
int hmin{ 0 }, smin{ 0 }, vmin{0};
int hmax{179}, smax{ 255 }, vmax{ 255 };

int main() {

	string path = "Resources/shapes.png";
	Mat img = imread(path);
	cvtColor(img, imgHSV, COLOR_BGR2HSV);
	namedWindow("Trackbars");
	createTrackbar("hmin", "Trackbars", &hmin, 179);
	createTrackbar("hmax", "Trackbars", &hmax, 179);
	createTrackbar("smin", "Trackbars", &smin, 255);
	createTrackbar("smax", "Trackbars", &smax, 255);
	createTrackbar("vmin", "Trackbars", &vmin, 255);
	createTrackbar("vmax", "Trackbars", &vmax, 255);

	while (1) {
		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);
		inRange(imgHSV, lower, upper, mask);

	//	imshow("Image", img);
	//	imshow("Image HSV", imgHSV);
		imshow("Mask", mask);
		waitKey(1);
	}

} 

