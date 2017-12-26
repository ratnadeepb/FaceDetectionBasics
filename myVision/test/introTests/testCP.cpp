#include "../../source/intro/videoCopy.hpp"

int main(int argc, char** argv)
{
	int retVal = EXIT_FAILURE;
	if(argc != 3){
		return retVal;
	}

	retVal = videoCopy(argv[1], argv[2]);

	std::cout << "The return value is " << retVal << std::endl;

	return retVal;
}
