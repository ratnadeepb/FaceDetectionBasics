#include "videoDownSample.hpp"

int videoCopy(char* src, char* dst)
{
        int retVal = EXIT_FAILURE;

        cv::VideoCapture cap(src);

        if(!cap.isOpened()){
                std::cerr << "Error opening video" << std::endl;
        }

        cv::Mat out;

        // Get input parameters
        double fps = cap.get(cv::CAP_PROP_FPS);

        cv::Size size((int)cap.get(cv::CAP_PROP_FRAME_WIDTH),
                        (int)cap.get(cv::CAP_PROP_FRAME_HEIGHT));


        // Create and open the writer
        cv::VideoWriter writer;
        writer.open(dst, CV_FOURCC('M', 'J', 'P', 'G'), fps, size, true);
	while(true){
                cap >> out;
                if(out.empty()){
                        break;
                }

                writer << out;

                retVal = EXIT_SUCCESS;
        }

        return retVal;
}
