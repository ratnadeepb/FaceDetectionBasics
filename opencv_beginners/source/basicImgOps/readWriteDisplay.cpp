#include "readWriteDisplay.hpp"

int readWriteDisplay(char* src, char* dst)
{
	using namespace std;
	Mat img = imread(src);

	if (img.empty()) {
		cout << "Could not open image" << endl;
		return EXIT_FAILURE;
	}

	// Convert to grayscale
	Mat gray;
	cvtColor(img, gray, COLOR_BGR2GRAY);

	// Save result
	imwrite(dst, gray);

	// Create display window
	namedWindow("Original", WINDOW_AUTOSIZE);
	namedWindow("Gray", WINDOW_NORMAL);

	// Show image
	imshow("Original", img);
	imshow("Gray", gray);

	// Wait for a keystroke
	waitKey(0);

	return EXIT_SUCCESS;
}
