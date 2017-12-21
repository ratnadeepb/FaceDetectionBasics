#include "picture1.hpp"

using namespace cv;

int picture1(char* name)
{
    IplImage* img = cvLoadImage(name);						/* This loads an image and stores it as an IplImage */
    cvNamedWindow("Picture1", CV_WINDOW_AUTOSIZE);				/* Open a window called Picture1 that resizes automatically */
    cvShowImage("Picture1", img);
    cvWaitKey(0);								/* Wait for user to press a key to cancel */
    cvReleaseImage(&img);							/* Clear memory */
    cvDestroyWindow("Picture1");
    return 0;
}

