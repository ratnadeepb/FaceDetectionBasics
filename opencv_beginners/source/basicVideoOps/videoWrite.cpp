#include "videoWrite.hpp"

/* In this program we will read a video from the webcam,
** display the feed
** and save it with a VideoWriter object.
*/

int videoWrite(char* src, char* dst)
{
	// std::cout << "src value type is " << typeid(atoi(src)).name() << std::endl;
	VideoCapture camera;
	camera.open(atoi(src));							/* We are capturing video from a webcam, generally with index 0
										** The main function will pass a char
										** We are casting it to int. */
	if(!camera.isOpened()){
		std::cout << "Error capturing video" << std::endl;
		return EXIT_FAILURE;
	}

	// Get the system dependent default resolution - frame width and height
	int frame_width  = camera.get(CV_CAP_PROP_FRAME_WIDTH);
	int frame_height = camera.get(CV_CAP_PROP_FRAME_HEIGHT);

	// Create the writer object
	char* output = dst;
	strcpy(output, ".avi");							// AVI is a safe output format
	VideoWriter video(output,						// MJPG is a safe bet for encoding videos, other codecs may not be
				CV_FOURCC('M', 'J', 'P', 'G'),			// available or may be unusable by OpenCV.
				10,						// Frame rate (fps)
				Size(frame_width, frame_height));		// Frame size

	// Read the feed until ESC is pressed
	while(true){
		Mat frame;
		camera >> frame;
		if(frame.empty()){
			break;
		}
		video.write(frame);
		imshow("Live Feed", frame);
	}

	return EXIT_SUCCESS;
}
