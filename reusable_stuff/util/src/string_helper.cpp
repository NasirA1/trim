#include "string_helper.h"
#include <sstream>

namespace util
{
    std::string replicate(const std::string& s, size_t count)
    {
        std::ostringstream oss;
        for(auto i = 0u; i < count; ++i) {
            oss << s;
        }
        return oss.str();
    }
}