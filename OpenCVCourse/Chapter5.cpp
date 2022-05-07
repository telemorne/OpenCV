#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Warp Images

float WIDTH = 160.0;
float HEIGHT = 250.0;

 void main() {

	string path = "Resources/cards.jpg";
	Mat img = imread(path);
	Mat imgWarp;
	Point2f src[4] = { {743,391}, {1017,441}, {653,707}, {963,777} };
	Point2f dst[4] = { {0,0}, {WIDTH,0}, {0.0,HEIGHT}, {WIDTH,HEIGHT} };

	Mat matrix = getPerspectiveTransform(src, dst);
	warpPerspective(img,imgWarp,matrix, Size(WIDTH,HEIGHT));

	imshow("Image", img);
	imshow("Image Warp", imgWarp);
	waitKey(0);

} 

