#include "flipImg.hpp"
#include "basicOps.hpp"
#include <stdlib.h>

int flipImg(char* src, int flip, void(*load)(char*, cv::Mat*))
{
  int retVal = EXIT_FAILURE;
  cv::Mat img;
  (*load)(src, &img);
  if(img.empty()){
    std::cerr << "Error opening image" << std::endl;
    return retVal;
  }
  cv::Mat res;
  cv::flip(img, res, flip);                                                     // positive for horizontal
                                                                                // 0 for vertical
                                                                                // negatove for both
  if(res.empty()){
    std::cerr << "Error flipping image" << std::endl;
  }
  cv::imshow("Flipped Image", res);
  cv::waitKey(0);
  return retVal;
}

int main(int argc, char** argv)
{
  int retVal = EXIT_FAILURE;
  if(argc != 4){
    std::cerr << "Incorrect parameters" << std::endl;
    return retVal;
  }
  std::string option(argv[1]);
  int flip = atoi(argv[2]);
  char* src = argv[3];
  if(option.compare("gray")){
    retVal = flipImg(src, flip, loadGrayImg);
  }
  else if(option.compare("color")){
    retVal = flipImg(src, flip, loadColorImg);
  }
  else {
    std::cout << "Incorrect options" << std::endl;
  }
  return retVal;
}
