#include "videoRead.hpp"

/* In this program we read a video file.
** In order to read from a camera, the device index needs to be passed.
** For the web camera, the index is generally 0.
** In case, reading from a camera, the argument to the function needs to be cast
** to an int.
*/

int videoRead(char* name)
{
	VideoCapture cap(name);							// Capture the video

	if(!cap.isOpened()){							// Check if video file is read successfully
		std::cout << "Error reading file" << std::endl;
		return EXIT_FAILURE;
	}

	// Read and display frames until the video completes or user presses ESC
	while(true){
		Mat frame;
		cap >> frame;							// Capture frame by frame
		if (frame.empty()){						// Exit when video ends
			break;
		}
		imshow("Video", frame);
		char c = (char)waitKey(25);
		if(c == 27){							// Exit if ESC is pressed
			break;
		}
	}

	// Release memory and destroy windows
	cap.release();
	destroyAllWindows();

	return EXIT_SUCCESS;
}
