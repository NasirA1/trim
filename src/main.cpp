#include <iostream>
#include <sstream>
#include "string_helper.h"

int main(int argc, char* argv[])
{    
    const auto joined = string_helper::join(argv + 1, static_cast<size_t>(argc - 1));
    std::cout << string_helper::trim_all(joined) << std::endl;

    return EXIT_SUCCESS;
}