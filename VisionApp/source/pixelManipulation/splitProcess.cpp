#include "splitProcess.hpp"

std::string helpFun()
{
	std::string help("This function takes a source image and a processing image.\n\
** It converts the processing image to grayscale and adds it to the blue channel of the source.\n\
** Usage: ./splitProcess <src_image> <processing_image>");
	return help;
}

int splitProcess(cv::Mat &img1, cv::Mat &img2, std::vector<cv::Mat> &planes)
{
	int retVal = EXIT_FAILURE;
	int img1Channels = static_cast<int>(img1.channels());
	if(img1Channels == 1){
		std::cout << "Only one channel in the input image" << std::endl;
		return retVal;
	}
	int img2Channels = static_cast<int>(img2.channels());
	cv::split(img1, planes);						// Split 1 3-channel image to 3 1-channel image
	planes[0] += img2;
	cv::merge(planes, img1);						// Merge 3 1-channel images to 1 3-channel image
	retVal = EXIT_SUCCESS;
	return retVal;
}

int errCheck(cv::Mat &img)
{
	int retVal = EXIT_SUCCESS;
	if(img.empty()){
		std::cerr << "Error opening image" << std::endl;
		retVal = EXIT_FAILURE;
	}
	return retVal;
}

int main(int argc, char** argv)
{
	int retVal = EXIT_FAILURE;
	std::vector<cv::Mat> planes;						// Create a vector to hold split color images
	cv::Mat img1, img2;

	if(strcmp(argv[1], "help") == 0){
		std::cout << helpFun() << std::endl;
		return EXIT_SUCCESS;
	}
	else if(argc == 3){
		img1 = cv::imread(argv[1]);
		int ret1 = errCheck(img1);
		img2 = cv::imread(argv[2], cv::IMREAD_GRAYSCALE);
		int ret2 = errCheck(img2);
		if(ret1+ret2 == 0){
			if(img1.size() != img2.size()){
				cv::resize(img2, img2, img1.size());		// Resize img2 to img1 size
			}
			retVal = splitProcess(img1, img2, planes);
		}
	}
	else{
		std::cerr << helpFun() << std::endl;
		retVal = EXIT_FAILURE;
	}
	if(retVal == EXIT_SUCCESS){
		cv::imshow("Superimposed", img1);
		cv::waitKey(0);
		cv::destroyAllWindows();
	}

	return retVal;
}
