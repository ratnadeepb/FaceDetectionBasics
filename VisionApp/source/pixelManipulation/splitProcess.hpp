#include <iostream>
#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

int splitProcess(cv::Mat &img1, cv::Mat &img2, std::vector<cv::Mat> &planes);
