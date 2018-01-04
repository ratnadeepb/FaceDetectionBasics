#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

int main(int argc, char** argv)
{
	int retVal = EXIT_FAILURE;
	if(argc != 2){
		std::cout << "We can handle only one input at a time" << std::endl;
		return retVal;
	}
	cv::Mat img = cv::imread(argv[1]);
	if(img.empty()){
		std::cout << "Error opening image" << std::endl;
		return retVal;
	}
	std::cout << "Image channels " << static_cast<int>(img.channels()) << std::endl;
	retVal = EXIT_SUCCESS;
	return retVal;
}
