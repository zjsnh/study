#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include "md5.h"

int main()
{
    std::cout << "md5 of 'grape': " << md5("grape") << std::endl;
    return 0;
}