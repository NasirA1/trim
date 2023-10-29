#include <iostream>
#include "arithmetic.h"
#include "string_helper.h"

int main(int argc, char* argv[])
{    
    std::cout << "Hello, world!\n";
    std::cout << calc::add(1, 2) << std::endl;
    std::cout << util::replicate("hello", 3) << std::endl;
    return EXIT_SUCCESS;
}