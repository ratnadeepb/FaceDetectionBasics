#include "../../source/basicImgOps/readWriteDisplay.hpp"

int main(int argc, char** argv)
{
        int retVal = readWriteDisplay(argv[1], argv[2]);
        std::cout << "The return value is " << retVal << std::endl;
}

