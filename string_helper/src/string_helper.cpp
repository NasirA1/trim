#include "string_helper.h"
#include <sstream>

namespace string_helper
{
    std::string join(char** str_array, size_t length)
    {
        std::ostringstream oss;
        for(auto i = 0u; i < length; ++i)
        {
            oss << str_array[i];
        }
        return oss.str();
    }

    std::string trim_all(const std::string& input)
    {
        std::ostringstream oss;
        for(const auto& ch: input)
        {
            switch(ch)
            {
                case ' ':
                case '\r':
                case '\n':
                case '\t':
                break;
                default:
                    oss << ch;
            }
        }
        return oss.str();
    }
}
