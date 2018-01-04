#include "basicOps.hpp"

void mouseClick(int event, int x, int y, int flags, void* param)
{
        cv::Mat* img = static_cast<cv::Mat*>(param);				/* We are using static_cast because it's a conversion to and from
										** void*
										*/
        switch (event) {
                case cv::EVENT_LBUTTONDOWN:
                        std::cout << "at (" << x << ", " << y << ") value is: " <<
                        	static_cast<int>(img->at<uchar>(cv::Point(x, y))) <<
				std::endl;
                        break;
  	}
}

/* cv::Mat always uses shallow copy by default - only the header is copied which holds a pointer to the data
** In this case, we are passing a pointer to the header which in turn contains a pointer to the data
**
** Deep copy
** img1.copyTo(img2) - can be used to reallocate img2 memory to contain a copy of img1
** cv::Mat img2 = img1.clone()
*/
void loadColorImg(char* src, cv::Mat* img)
{
	*img = cv::imread(src, cv::IMREAD_COLOR);
}

void loadGrayImg(char* src, cv::Mat* img)
{
	*img = cv::imread(src, cv::IMREAD_GRAYSCALE);
}

void loadAsIs(char* src, cv::Mat* img)
{
	*img = cv::imread(src);
}

int displayImg(char* src, void(*load)(char*, cv::Mat*))
{
	int retVal = EXIT_FAILURE;
	cv::Mat img;

	(*load)(src, &img);

	if(img.empty()){
		std::cerr << "Error opening image" << std::endl;
		return retVal;
	}

	cv::imshow("Image", img);
	cv::setMouseCallback("Image", mouseClick, static_cast<void*>(&img));
	cv::waitKey(0);
	retVal = EXIT_SUCCESS;

	return retVal;
}
