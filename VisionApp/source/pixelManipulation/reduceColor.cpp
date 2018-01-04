#include "reduceColor.hpp"

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
** The add method should be used only for access to random pixel values but never for such operations.
*/

int reduceColor(cv::Mat* img, int div)
{
	int retVal = EXIT_FAILURE;

	if(div > 128){
		std::cerr << "This program supports reduction by power \
of 2 only" << std::endl;
                return retVal;
	}

	int nl = img->rows;							// Number of lines
	int nc = img->cols * img->channels();					// Total number of elements per line

	if(img->isContinuous()){                                                // Then there is no padding and we can reduce the number of loops
                std::cout << "Image is continuous" << std::endl;
                nc = nc * nl;							/* Since there is no zero padding we can treat the image as a
										** single array of numbers */
                nl = 1;
        }
        else{
                std::cout << "Image is not continuous" << std::endl;
        }

	for(int j=0; j < nl; j++){
		// Get the address of row j
		uchar* data = img->ptr<uchar>(j);

		for(int i=0; i < nc; i++){
			// process each pixel
			data[i] = (data[i] / div) * div + div/2;
		}
		retVal = EXIT_SUCCESS;
	}
	return retVal;
}

int main(int argc, char** argv)
{
	int retVal = EXIT_FAILURE;

	cv::Mat img;

	if(argc == 2){
                img = cv::imread(argv[1]);
                retVal = reduceColor(&img);
        }
        else if(argc == 3){
                img = cv::imread(argv[1]);
                int n = atoi(argv[2]);
                retVal = reduceColor(&img, n);
        }
        else{
                std::cerr << "Incorrect input parameters" << std::endl;
                return retVal;
        }

        if(retVal == EXIT_SUCCESS){
                cv::imshow("Reduced image", img);
                cv::waitKey(0);
        }

	return retVal;
}
