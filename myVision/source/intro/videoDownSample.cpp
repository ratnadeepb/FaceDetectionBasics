#include "videoDownSample.hpp"

int videoDownSample(char* src, char* dst)
{
        /*
        ** This program will read from a video file
        ** Downsample by a factor of 2
        ** Store it to an output file
        **
        ** Inputs:
        **      src: file to read from
        **      dst: name of file to store to
        ** Output:
        **      dst: file where downsampled video is stored
        */

        int retVal = EXIT_FAILURE;

        cv::VideoCapture cap(src);

        if(!cap.isOpened()){
                std::cerr << "Error opening video" << std::endl;
        }

        cv::Mat inter, out;

        // Get input parameters
        double fps = cap.get(cv::CAP_PROP_FPS);

	// The division by 2 is because the writer is going to be writing frames that have been
	// downsampled by a factor of 2
	// It will throw assertion errors if the frame size do not match the size of the writer
        cv::Size size((int)cap.get(cv::CAP_PROP_FRAME_WIDTH) / 2,
                        (int)cap.get(cv::CAP_PROP_FRAME_HEIGHT) / 2);


        // Create and open the writer
        cv::VideoWriter writer;
        writer.open(dst, CV_FOURCC('M', 'J', 'P', 'G'), fps, size, true);
	while(true){
                cap >> inter;
                if(inter.empty()){
                        break;
                }
                cv::pyrDown(inter, out);
                writer << out;

                retVal = EXIT_SUCCESS;
        }
	cap.release();
        return retVal;
}
