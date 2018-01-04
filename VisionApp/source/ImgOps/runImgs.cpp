#include <string>
#include "basicOps.hpp"

int main(int argc, char** argv)
{
  int retVal = EXIT_FAILURE;
  if(argc != 3){
    std::cerr << "Too few arguments" << std::endl;
    return retVal;
  }
  std::string option(argv[1]);
  char* src = argv[2];

  if(option.compare("gray")){
    retVal = displayImg(src, loadGrayImg);
  }
  else if(option.compare("color")){
    retVal = displayImg(src, loadColorImg);
  }
  else {
    std::cout << "Incorrect options" << std::endl;
    std::cout << "Displaying image as is" << std::endl;
    retVal = displayImg(src, loadAsIs);
  }
  return retVal;
}
