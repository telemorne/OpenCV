#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Shapes and Contout Detection 


void getContours(Mat imgDil, Mat img) {

	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	//drawContours(img,contours,-1,Scalar(255,0,255),2);
	vector<Rect> boundRect(contours.size());
	vector<vector<Point>> conPoly(contours.size());
	String conShape;

	for (int i{ 0 }; i < contours.size(); i++) {

		double area{ contourArea(contours[i]) };
		cout << area << endl;
		if (area >1000) {

			double peri{ arcLength(contours[i],true)};
			boundRect[i] = boundingRect(contours[i]);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
			drawContours(img,conPoly,i,Scalar(255,0,255),2);
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 0, 255), 2);
			switch (conPoly[i].size()) {
			
			case 3:
				conShape = "Tri";
				break;
			case 4:
			{
				auto aspRatio = boundRect[i].width * 1.0/ boundRect[i].height;
				if (aspRatio > 0.95 && aspRatio < 1.05)
					conShape = "Square";
				else
					conShape = "Rect";
				break;
			}
				
			default:
				conShape = "Circle";
				break;
			
			}
			putText(img, conShape, { boundRect[i].x,boundRect[i].y - 5 }, FONT_HERSHEY_DUPLEX, 0.5, Scalar(255, 0, 255), 1);

		}
		
	}



}



int main() {

	string path = "Resources/shapes.png";
	Mat img = imread(path);
	Mat imgGray, imgBlur, imgCanny, imgDil, imgEro;

	// Preprocessing
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
	Canny(imgBlur, imgCanny, 25, 75);

	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDil, kernel);

	getContours(imgDil,img);

	//	imshow("Image", img);
	//	imshow("Image Gray", imgGray);
	//	imshow("Image Blur", imgBlur);
	//	imshow("Image Canny", imgCanny);
	imshow("Image Contours", img);
	waitKey(0);

}


