#include "../../source/basicImgOps/rotation.hpp"

int main(int argc, char** argv)
{
        int retVal = rotate(argv[1]);
        std::cout << "The return value is " << retVal << std::endl;
}

