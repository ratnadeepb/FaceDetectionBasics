#include "imageDraw.hpp"

int imageDraw(char* name)
{
	Mat img = imread(name, 1);

	if(img.empty()){
		return EXIT_FAILURE;
	}

	// Draw a line
	Mat imgLine = img.clone();						// Clone the image - both header and data is copied
	line(imgLine, Point(100, 100), Point(300, 100), Scalar(0, 0, 255), 
		1, CV_AA);
	imshow("Line", imgLine);

	// Draw a circle
	Mat imgCircle = img.clone();
	circle(imgCircle, Point(100, 100), 50, Scalar(0, 0, 255), -1, CV_AA);
	imshow("Circle", imgCircle);

	// Draw an ellipse
	Mat imgEllipse = img.clone();
	ellipse(imgEllipse, Point(100, 100), Size(100, 100), 45, 0, 360, 
			Scalar(0, 0, 255), 1, 8);

	// Draw a rectangle
	Mat imgRect = img.clone();
	rectangle(imgRect, Point(100, 100), Point(200, 200), Scalar(0, 0, 255), 
			1, 8);
	imshow("Rectangle", imgRect);

	// Put text in image
	Mat imgText = img.clone();
	putText(imgText, "Sourav Ganguly", Point(100, 100), FONT_HERSHEY_SIMPLEX,
			 1, Scalar(0, 255, 0), 1);
	imshow("Text", imgText);

	waitKey(0);
	return EXIT_SUCCESS;
}
