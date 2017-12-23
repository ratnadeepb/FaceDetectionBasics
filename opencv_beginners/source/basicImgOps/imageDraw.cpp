#include "imageDraw.hpp"

int imageDraw(char* name)
{
	Mat img = imread(name, 1);

	// Get number of rows and columns in the image
	int rows = img.rows;
	int cols = img.cols;

	if(img.empty()){
		return EXIT_FAILURE;
	}

	// Draw a line
	Mat imgLine = img.clone();						// Clone the image - both header and data is copied
	line(imgLine, Point(0, (int)rows/2), Point(cols, (int)rows/2), 
		Scalar(0, 0, 255), 1, CV_AA);
	imshow("Line", imgLine);

	// Draw a circle
	Mat imgCircle = img.clone();
	circle(imgCircle, Point((int)cols/2, (int)rows/2), 50, 
		Scalar(0, 0, 255), -1, CV_AA);
	imshow("Circle", imgCircle);

	// Draw an ellipse
	Mat imgEllipse = img.clone();
	ellipse(imgEllipse, Point((int)cols/2, (int)rows/2), 
			Size(100, 100), 45, 0, 360, 
			Scalar(0, 0, 255), 1, 8);

	// Draw a rectangle
	Mat imgRect = img.clone();
	rectangle(imgRect, Point((int)cols/4, (int)rows/4), 
			Point((int)3*cols/4, (int)3*rows/4), 
			Scalar(0, 0, 255), 1, 8);
	imshow("Rectangle", imgRect);

	// Put text in image
	Mat imgText = img.clone();
	putText(imgText, "Sourav Ganguly", Point((int)cols/4, (int)rows/4),
		 FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 255, 0), 1);
	imshow("Text", imgText);

	waitKey(0);
	return EXIT_SUCCESS;
}
