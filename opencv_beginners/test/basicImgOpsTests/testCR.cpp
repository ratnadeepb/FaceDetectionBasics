#include "../../source/basicImgOps/cropResize.hpp"

int main(int argc, char** argv)
{
        int retVal = cropResize(argv[1]);
        std::cout << "The return value is " << retVal << std::endl;
}
