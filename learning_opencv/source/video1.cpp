#include "video1.hpp"

using namespace cv;

int video1(char* name)
{
	cvNamedWindow("Video1", CV_WINDOW_AUTOSIZE);
	CvCapture* capture = cvCreateFileCapture(name);				/* Store the video in a CvCapture data structure */
	IplImage* frame;							/* Storing each frame */

	while(1) {
		frame = cvQueryFrame(capture);					/* Get the frames */
		if (!frame) {
			break;							/* Break if there are no more frames */
		}
		cvShowImage("Video1", frame);					/* Show individual frames */
		char c = cvWaitKey(33);						/* Wait for 33 ms, if any key is pressed value is stored in c 
										** 30 frames per second rate is assumed */
		if (c == 27) {
			break;							/* Break if the ESC key (ASCII 27) is pressed */
		}
	}
	cvReleaseCapture(&capture);						/* Release memory for capture. IplImage uses memory from capture
										** space */
	cvDestroyWindow("Video1");

	return 0;
}
