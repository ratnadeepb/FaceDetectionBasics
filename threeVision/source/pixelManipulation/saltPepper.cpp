#include "saltPepper.hpp"

/*
** Randomly selected pixels are replaced with black or white (white in this case)
** This sort of noise can be introduced through faulty transmission when some of the pixels
** are lost.
*/

int saltPepper(cv::Mat* img, int n)
{
	int retVal = EXIT_FAILURE;
	//C++11 random number generator
	std::default_random_engine gen;
	std::uniform_int_distribution<int> randomRow(0, img->rows - 1);
	std::uniform_int_distribution<int> randomCol(0, img->cols - 1);

	int i, j;

	for(int k = 0; k < n; k++){
		i = randomCol(gen);
		j = randomRow(gen);
		if(img->type() == CV_8UC1){					// Gray image
			img->at<uchar>(j, i) = 255;
		}
		else if(img->type() == CV_8UC3){					// Color image
			// 3-channel image
			//img->at<cv::Vec3b>(j, i) = cv::Vec3b(255, 255, 255);
			img->at<cv::Vec3b>(j, i)[0] = 255;
			img->at<cv::Vec3b>(j, i)[1] = 255;
			img->at<cv::Vec3b>(j, i)[2] = 255;
		}
		retVal = EXIT_SUCCESS;
	}
	return retVal;	
}

int main(int argc, char** argv)
{
	int retVal = EXIT_FAILURE;
	if(argc != 3){
		std::cerr << "Incorrect parameters" << std::endl;
		return retVal;
	}
	int n = atoi(argv[1]);
	cv::Mat img = cv::imread(argv[2]);
	retVal = saltPepper(&img, n);
	cv::imshow("Image", img);
	cv::waitKey(0);

	return retVal;
}
