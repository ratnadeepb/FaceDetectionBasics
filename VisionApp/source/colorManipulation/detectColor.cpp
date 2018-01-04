#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "ColorDetector.hpp"

int main(int argc, char** argv)
{
        int retVal = EXIT_FAILURE;
        ColorDetector cdetect;

        if(argc < 4){
            std::cerr << "Incorrect parameters" << std::endl;
            return retVal;
        }
        
	cv::Mat img = cv::imread(argv[1]);
	if(img.empty()) return retVal;
        
        int blue, green, red;
        blue = atoi(argv[2]);
        green = atoi(argv[3]);
        red = atoi(argv[4]);
        
        int useLab = 0;
        if(argc == 5){
            useLab = atoi(argv[5]);
            cdetect.setUseLab(useLab);
        }

	cdetect.setTargetColor(blue, green, red);

	cv::Mat result = cdetect.process(img);
	cv::imshow("result", result);

	cv::waitKey(0);

	return 0;
}
