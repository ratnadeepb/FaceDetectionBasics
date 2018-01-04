#include "imgVarDS.hpp"

int g_slider = 0;
cv::VideoCapture g_cap;

void onTrackSlidebar(int dsLevel, void*)
{
	g_cap.set;
}

int imgVarDS(char* src)
{
	int retVar = EXIT_FAILURE;

	g_cap.open(src);
	if(!g_cap.isOpened()){
		std::cerr << "Error opening video" << std::endl;
		return EXIT_FAILURE;
	}

	cv::Mat frame;
	double fps = g_cap.get(cv::CAP_PROP_FPS);
	int width = g_cap.get((int)cv::CAP_PROP_FRAME_WIDTH);
	int height = g_cap.get((int)cv::CAP_PROP_FRAME_HEIGHT);
	cv::Size size(height, width);

	while(true){
		g_cap >> frame;
		if(frame.empty()){
			break;
		}
		cv::pyrDown(frame, frame);
		cv::imshow("DS2", frame);
		if(cv::waitKey(10) > 0){
			break;
		}
		retVal = EXIT_SUCCESS;
	}
	g_cap.release();
	return retVal;
}
