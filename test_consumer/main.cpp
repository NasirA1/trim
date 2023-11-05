#include <iostream>
#include "string_helper.h"

int main(int argc, char* argv[])
{
    std::cout << util::replicate("hello", 10) << std::endl;

    return EXIT_SUCCESS;
}
