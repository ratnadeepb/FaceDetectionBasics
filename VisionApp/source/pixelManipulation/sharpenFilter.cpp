#include "sharpenFilter.hpp"

void sharpenFilter(cv::Mat &img, cv::Mat &res)
{
	cv::Mat kernel(3, 3, CV_32F, cv::Scalar(0));				// The filter
	kernel.at<float>(1, 1) = 5;
	kernel.at<float>(0, 1) = -1;
	kernel.at<float>(1, 0) = -1;
	kernel.at<float>(1, 2) = -1;
	kernel.at<float>(2, 1) = -1;

	cv::filter2D(	img, 							// Source
			res, 							// Destination
			img.depth(), 						// Image depth
			kernel);						// Kernel to apply
}

int main(int argc, char** argv)
{
	int retVal = EXIT_FAILURE;

	cv::Mat img, res;
	if(argc == 2){
		img = cv::imread(argv[1]);
		sharpenFilter(img, res);
	}
	else{
		std::cerr << "Incorrect parameters" << std::endl;
	}

	cv::imshow("Original Image", img);
	cv::imshow("Sharpened Image", res);
	cv::waitKey(0);
	cv::destroyAllWindows();

	return EXIT_SUCCESS;
}
