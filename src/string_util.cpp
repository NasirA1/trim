#include "string_util.h"
#include <cstdarg>

namespace util
{
    std::string format_s(const char* fmt, ...)
    {
        va_list args;

        std::string result;
        int rc = -1;
        size_t length = 1024;

        while (true)
        {
            va_start(args, fmt);
            result.resize(length);
            rc = vsprintf(const_cast<char*>(result.data()), fmt, args);
            va_end(args);

            if (rc > -1 && static_cast<unsigned int>(rc) < length)
            { //all ok
                result.resize(rc);
                return result;
            }

            if (rc > -1)
                //needed size returned, allocate 1 byte for the null terminator
                length = rc + 1;
            else
                //Error occurred. Try doubling buffer size
                length *= 2;
        }

        return result;    
    }
}
