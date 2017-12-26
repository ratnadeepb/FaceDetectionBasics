#include "imgDS.hpp"

int imgDS(char* src, char* dst)
{
        int retVal = EXIT_FAILURE;

        cv::Mat img = cv::imread(src,1);

        if(img.empty()){
                std::cerr << "Error opening image" << std::endl;
		return EXIT_FAILURE;
        }

        cv::Mat inter;
	cv::pyrDown(img, inter);
	cv::Mat out;
	cv::pyrDown(inter, out);

	cv::imwrite(dst, out);

        retVal = EXIT_SUCCESS;

        return retVal;
}
