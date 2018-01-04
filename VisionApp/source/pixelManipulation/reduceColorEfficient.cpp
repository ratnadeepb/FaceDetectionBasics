#include "reduceColorEfficient.hpp"

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
** As you might compare, for continuous images this is much more faster than using iterators.
**
** I will update the documentation as and when I test with discontinuous images.
**
** Usage: ./reduceColorEfficient <image_file> [reduction_factor]
*/

std::string helpFun()
{
	std::string help("/* In a 3 channel, 8-bits per channel picture there are 256x256x256 colors.\n\
** Consequently, complexity of image processing tasks can be reduced by reducing the number of colors.\n\
**\n\
** Divide the entire BGR space into small cubes. For each cube replace the value of all pixels in the cube \n\
** with the value of the central pixel.\n\
**\n\
** Algorithm: Let desired reduction factor be N. Divide each pixel by N (integer division). \n\
** Then multiply the result by N - value is equal or less to pixel value.\n\
** Add N/2 so the pixel value is now exactly between two adjacent multiples of N. \n\
** Repeating for each channel, you get 256/N x 256/N x 256/N colors.\n\
**\n\
** In this program, we restrict the reduction strictly to powers of two.\n\
** This allows the use of bitwise operators making the program far more efficient.\n\
**\n\
** As you might compare, for continuous images this is much more faster than using iterators.\n\
**\n\
** I will update the documentation as and when I test with discontinuous images.\n\
**\n\
** Usage: ./reduceColorEfficient <image_file> [reduction_factor, default=6]\n\
*/"); 
	return help;
}

int reduceColorEfficient(cv::Mat* img, int n)
{
	int retVal = EXIT_FAILURE;

	if(n > 7){
		std::cerr << "This program supports reduction by power of 2 \
only" << std::endl;
		return retVal;
	}

	if(img->isContinuous()){						// Then there is no padding
		// In this case no memory copy or reallocation is required
		std::cout << "Image is continuous" << std::endl;
		// Number of columns is adjusted accordingly
		img->reshape(1,							// Number of channels
				1);						// Number of rows
	}
	else{
		std::cout << "Image is not continuous" << std::endl;
	}

	int nl = img->rows;							// Number of lines
	int nc = img->cols * img->channels();					// Total number of elements per line

	uchar mask = 0xFF << n;							// Calculate the mask

	for(int j=0; j < nl; j++){
		// Get the address of row j
                uchar* data = img->ptr<uchar>(j);

		for(int i=0; i < nc; i++){
			// process each pixel

			*data &= mask;						// Masking
			*data++ += n >> 1;					// Add div/2
		}
		retVal = EXIT_SUCCESS;
	}
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

	cv::Mat img;

	// This variable is used for measuring efficiency
        double duration;

	if(strcmp(argv[1], "help") == 0){
		std::cout << helpFun() << std::endl;
		return EXIT_SUCCESS;
	}

	if(argc == 2){
		img = cv::imread(argv[1]);
		int ret = errCheck(&img);
		// If successful ret = 0
		if(!ret){							// Continue if image opened successfully
			const int64 start_time = cv::getTickCount();            // Measuring efficiency
			retVal = reduceColorEfficient(&img);
			duration = (cv::getTickCount() - start_time) \
                	                / cv::getTickFrequency();    	        // Measuring efficiency
		}
	}
	else if(argc == 3){
		img = cv::imread(argv[1]);
		int ret = errCheck(&img);
		// If successful ret = 0
		if(!ret){							// Continue if image opened successfully
			int n = atoi(argv[2]);
			const int64 start_time = cv::getTickCount();            // Measuring efficiency
			retVal = reduceColorEfficient(&img, n);
			duration = (cv::getTickCount() - start_time) \
        	                        / cv::getTickFrequency();               // Measuring efficiency
		}
	}
	else{
		std::cerr << helpFun() << std::endl;
		return retVal;
	}

	if(retVal == EXIT_SUCCESS){
		std::cout << "Time taken: " << duration << std::endl;		// Measuring efficiency
		cv::imshow("Reduced image", img);
		cv::waitKey(0);
	}

	return retVal;
}
