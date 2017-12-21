#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

using namespace cv;

/*
** cv::line ( image, starting point , end point , color , line thickness, line type)
** cv:: circle ( image, center, radius, color of border, line thickness / fill type, line type)
** cv:: ellipse ( image, center, axes lengths, rotation degree of ellipse, 
** 			starting angle , ending angle, color, line thickness / fill type, line type)
** cv:: rectangle ( image, upper left corner vertex, lower right corner vertex, line thickness / fill type, line type)
** cv :: putText ( image, text, starting point of text, font type, font scale, color, linetype )
*/

int imageDraw(char* name);
