#pragma once
#include <string>

namespace string_helper
{
    std::string join(char**, size_t);
    std::string trim_all(const std::string&);
    std::string sadd(const std::string&, const std::string&);
}
