#include "video2.hpp"

/* 
** Play a video with a trackbar on a side
** Some videos may not allow you play back due to encoding
*/

using namespace cv;

int g_slider_pos = 0;
CvCapture* g_capture = NULL;

void onTrackbarSlide(int pos)
{
	cvSetCaptureProperty(							/* Set property of video */
		g_capture,
		CV_CAP_PROP_POS_FRAMES,						/* Set position as the nth frame. Replacing FRAMES with AVI_RATIO
										** lets position the slider as a ratio of the total length of the
										** video. */
		pos
	);
}

int video2(char* name)
{
	cvNamedWindow("Video3", CV_WINDOW_AUTOSIZE);
	g_capture = cvCreateFileCapture(name);
	int frames = (int) cvGetCaptureProperty(				/* Set video property */
				g_capture,
				CV_CAP_PROP_FRAME_COUNT);
	if (frames != 0) {
		cvCreateTrackbar(
			"Position",						/* Label for the slider */
			"Video2",						/* Window to attach to */
			&g_slider_pos,						/* Variable bound to the trackbar */
			frames,							/* Maximum range of the trackbar */
			onTrackbarSlide						/* Callback function. Maybe NULL */
			);
	}

	IplImage* frame;
	int pos = 0;
	while(1) {
		frame = cvQueryFrame(g_capture);
		onTrackbarSlide(pos);						/* Update trackbar position*/
		pos++;
		cvShowImage("Video2", frame);
		if (!frame) {
			break;
		}
		char c = cvWaitKey(33);
		if (c == 27) {
			break;
		}
	cvReleaseCapture(&g_capture);
	cvDestroyWindow("Video2");
	}
	return 0;
}
