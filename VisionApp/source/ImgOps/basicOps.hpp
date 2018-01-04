#ifndef  BASIC_IMG_OPS
#define  BASIC_IMG_OPS
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

void mouseClick(int event, int x, int y, int flags, void* param);
void loadColorImg(char* src, cv::Mat* img);
void loadGrayImg(char* src, cv::Mat* img);
void loadAsIs(char* src, cv::Mat* img);
int displayImg(char* src, void(*load)(char*, cv::Mat*));
#endif
