#include "reduceColorIterator.hpp"

/* In a 3 channel, 8-bits per channel picture there are 256x256x256 colors.
** Consequently, complexity of image processing tasks can be reduced by reducing the number of colors.
**
** Divide the entire BGR space into small cubes. For each cube replace the value of all pixels in the cube 
** with the value of the central pixel.
**
** Algorithm: Let desired reduction factor be N. Divide each pixel by N (integer division). 
** Then multiply the result by N - value is equal or less to pixel value.
** Add N/2 so the pixel value is now exactly between two adjacent multiples of N. 
** Repeating for each channel, you get 256/N x 256/N x 256/N colors.
**
** In this program, we restrict the reduction strictly to powers of two.
** This allows the use of bitwise operators making the program far more efficient.
**
** Furthermore, now we use iterators to loop through the image
**
** Usage: reduceColorIterator <image_file> [reduction_factor, default=6]
*/

std::string helpFun()
{
	std::string help("/* In a 3 channel, 8-bits per channel picture there are 256x256x256 colors.\n\
** Consequently, complexity of image processing tasks can be reduced by reducing the number of colors.\n\
**\n\
** Divide the entire BGR space into small cubes. For each cube replace the value of all pixels in the cube\n\
** with the value of the central pixel.\n\
**\n\
** Algorithm: Let desired reduction factor be N. Divide each pixel by N (integer division).\n\
** Then multiply the result by N - value is equal or less to pixel value.\n\
** Add N/2 so the pixel value is now exactly between two adjacent multiples of N.\n\
** Repeating for each channel, you get 256/N x 256/N x 256/N colors.\n\
**\n\
** In this program, we restrict the reduction strictly to powers of two.\n\
** This allows the use of bitwise operators making the program far more efficient.\n\
**\n\
** Furthermore, now we use iterators to loop through the image\n\
** The main use of the iterators is to make programming easier and less error prone.\n\
**\n\
** Usage: reduceColorIterator <image_file> [reduction_factor, default=6]\n\
*/");

	return help;
}

int reduceColorIterator(cv::Mat* img, int n)
{
	int retVal = EXIT_FAILURE;

	if(img->isContinuous()){                                                // Then there is no padding
                // In this case no memory copy or reallocation is required
                std::cout << "Image is continuous" << std::endl;
	}

	if(n > 7){
		std::cerr << "This program supports reduction by power \
of 2 only" << std::endl;
		return retVal;
	}

	cv::Mat_<cv::Vec3b>::iterator start = img->begin<cv::Vec3b>();
	cv::Mat_<cv::Vec3b>::iterator end = img->end<cv::Vec3b>();

	uchar mask = 0xFF << n;							// Calculate the mask

	// Scan all pixels
	while(start != end){
		for(int i = 0; i < 3; i++){
			(*start)[i] &= mask;
			(*start)[i] |= n >> 1;
		}
		start++;
	}
	retVal = EXIT_SUCCESS;
	return retVal;
}

int errCheck(cv::Mat* img)
{
        /* Function to check if image is successfully opened */
        if(img->empty()){
                std::cerr << "Error opening image" << std::endl;
                return EXIT_FAILURE;
        }
        return EXIT_SUCCESS;
}

int main(int argc, char** argv)
{
	int retVal = EXIT_FAILURE;

	if(strcmp(argv[1], "help") == 0){
                std::cout << helpFun() << std::endl;
		return EXIT_SUCCESS;
        }

	cv::Mat img;
	// This variable is used for measuring efficiency
	double duration;

	if(argc == 2){
		img = cv::imread(argv[1]);
		int ret = errCheck(&img);
		// If successful, ret == 0
		if(!ret){
			const int64 start_time = cv::getTickCount();		// Measuring efficiency
			retVal = reduceColorIterator(&img);
			duration = (cv::getTickCount() - start_time) \
					/ cv::getTickFrequency();		// Measuring efficiency
		}
	}
	else if(argc == 3){
		img = cv::imread(argv[1]);
		int ret = errCheck(&img);
		// If successful, ret == 0
		if(!ret){
			int n = atoi(argv[2]);
			const int64 start_time = cv::getTickCount();		// Measuring efficiency
			retVal = reduceColorIterator(&img, n);
			duration = (cv::getTickCount() - start_time) \
					/ cv::getTickFrequency();		// Measuring efficiency
		}
	}
	else{
		std::cerr << "Incorrect input parameters" << std::endl;
		return retVal;
	}

	if(retVal == EXIT_SUCCESS){
		std::cout << "Time taken: " << duration << std::endl;		// Measuring efficiency
		cv::imshow("Reduced image", img);
		cv::waitKey(0);
	}

	return retVal;
}
