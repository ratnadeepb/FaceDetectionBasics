#include "rotation.hpp"

int rotate(char* name)
{
	Mat src, M, dst;

	src = imread(name, 1);

	if(src.empty()) {
		return EXIT_FAILURE;
	}
	
	Point2f center(src.cols/2, src.rows/2);					// Define the center of the image, We use this as center of rotation
	double rotAngle = 30, scale = 2;					// Angle of rotation and scale

	// Rotate
	M = getRotationMatrix2D(center, rotAngle, scale);			// Get the rotation matrix
	warpAffine(src, dst, M, Size(src.cols * 2, src.rows * 2));		// We are resizing the image by a factor of 2 matching the scale

	// Create windows for display
	namedWindow("Original Image", WINDOW_AUTOSIZE);
	namedWindow("Rotated Image", WINDOW_AUTOSIZE);

	// Display images
	imshow("Original Image", src);
	imshow("Rotated Image", dst);

	waitKey(0);

	return EXIT_SUCCESS;
}
