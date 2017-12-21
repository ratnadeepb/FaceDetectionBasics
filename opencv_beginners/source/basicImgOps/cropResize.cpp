#include "cropResize.hpp"

int cropResize(char* src)
{
	Mat source, scaleDown, scaleUp;						// Create required matrices
	source = imread(src, 1);						// Read the image

	if(source.empty()) {
		return EXIT_FAILURE;
	}
	
	double scaleX = 0.6, scaleY = 0.6;					// Scaling factors

	/* Resizing:
	** 	cv::resize(src_img, dst_img, Size(,), scaleX, scaleY, interpolation method)
	**		Size(,) specifies the size of the dst_img which will compute the scale factors automatically.
	*/

	resize(source, scaleDown, Size(), scaleX, scaleY, INTER_LINEAR); 	// Scale down to 60% of original size
	resize(source, scaleUp, Size(), scaleX*3, scaleY*3, INTER_LINEAR); 	// Scale up to 180% of original size

	/* Crop:
	** 	Use the Range function
	**	source(row_range, column_range)
	*/

	Mat crop = source(cv::Range(50, 150), cv::Range(50, 150));

	// Create Display windows for all three images
	namedWindow("Original", WINDOW_AUTOSIZE);
	namedWindow("Scaled Down", WINDOW_AUTOSIZE);
	namedWindow("Scaled Up", WINDOW_AUTOSIZE);
	namedWindow("Cropped Image", WINDOW_AUTOSIZE);

	// Show images
	imshow("Original", source);
	imshow("Scaled Down", scaleDown);
	imshow("Scaled Up", scaleUp);
	imshow("Cropped Image", crop);

	return EXIT_SUCCESS;
}
