#include "addImgs.hpp"

void addImgs(cv::Mat &img1, cv::Mat &img2, cv::Mat &res, double part)
{
	cv::addWeighted(img1,							// First image
			part,							// Its weight
			img2,							// Second image
			1 - part,						// Its weight
			0,
			res);							// Output
}

int errCheck(cv::Mat &img)
{
        /* Function to check if image is successfully opened */
        if(img.empty()){
                std::cerr << "Error opening image" << std::endl;
                return EXIT_FAILURE;
        }
        return EXIT_SUCCESS;
}

int main(int argc, char** argv)
{
	int retVal = EXIT_SUCCESS;

	cv::Mat img1, img2, res;

	if(argc == 3){
		img1 = cv::imread(argv[1]);
		img2 = cv::imread(argv[2]);
		int ret1 = errCheck(img1);
		int ret2 = errCheck(img2);
		if(ret1+ret2 == 0){
			// The input and output images need to match in size
			res.create(img1.size(), img1.type());

			// The superimposed image needs to match as well
			cv::resize(img2, img2, img1.size());

			addImgs(img1, img2, res);
			int retRes = errCheck(res);
			retVal = retRes;
		}
	}

	else if(argc == 4){
		img1 = cv::imread(argv[1]);
		img2 = cv::imread(argv[2]);
		int ret1 = errCheck(img1);
		int ret2 = errCheck(img2);
		if(ret1+ret2 == 0){
			double part = atof(argv[3]);
			// The input and output images need to match in size
			res.create(img1.size(), img1.type());

			// The superimposed image needs to match as well
			cv::resize(img2, img2, img1.size());

			addImgs(img1, img2, res, part);
			int retRes = errCheck(res);
			retVal = retRes;
		}
	}

	if(retVal){
		return retVal;
	}
	else{
		cv::imshow("Superimposed", res);
		cv::waitKey(0);
		cv::destroyAllWindows();
	}
	return retVal;
}
