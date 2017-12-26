#include "../../source/basicVideoOps/videoRead.hpp"

int main(int argc, char** argv)
{
	int retVal = videoRead(argv[1]);
	std::cout << "The return value is " << retVal << std::endl;
	return 0;
}
