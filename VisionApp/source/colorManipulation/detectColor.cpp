#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "ColorDetector.hpp"

int main(int argc, char** argv)
{
        ColorDetector cdetect;

	cv::Mat img = cv::imread(argv[1]);
	if(img.empty()) return -1;

	cdetect.setTargetColor(230,190,130);

	cv::Mat result = cdetect.process(img);
	cv::imshow("result", result);

	cv::waitKey(0);

	return 0;
}
