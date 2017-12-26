#include "../../source/basicVideoOps/videoWrite.hpp"

int main(int argc, char** argv)
{
	int retVal = videoWrite(argv[1], argv[2]);
	std::cout << "The return value is " << retVal << std::endl;
	return 0;
}
