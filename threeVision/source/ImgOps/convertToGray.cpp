#include <iostream>
#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

int main(int argc, char** argv)
{
	int retVal = EXIT_FAILURE;
	cv::Mat img;
	std::vector<cv::Mat> channels;

	if(argc != 3){
		std::cout << "Incorrect parameters" << std::endl;
		return retVal;
	}

	img = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);
	if(img.empty()){
		std::cout << "Error opening image" << std::endl;
		return retVal;
	}

	cv::imwrite(argv[2], img);

	return EXIT_SUCCESS;
}
