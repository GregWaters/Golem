#ifndef __SYSTEM_HPP
#define __SYSTEM_HPP

// Begin operating system macro definition and header inclusion
#if defined(__linux__)
    #define OS_LINUX
    #include "unistd.h"

#elif defined(_WIN32) || defined(__WIN32__) || defined(__WIN32) || defined(WIN32) || defined(__WIN64) || defined(__WIN64__)
    #define OS_WINDOWS
    #include "windows.h"

#elif defined(__APPLE__) || defined(macintosh) || defined(Macintosh)
    #define OS_MAC
    #error "Mac is not yet supported"

#else
    #error "Your operating system is not yet supported"

#endif
// End operating system macro definition

#include <cstdint>

namespace sys
{
    // For information on why these two functions work, see en.wikipedia.org/wiki/Endianness#/media/File:32bit-Endianess.svg

    [[nodiscard]]
    constexpr bool big_endian()
    {
        union
        {
            uint32_t i;
            char as_str[4];
        } bytes = {0x0A'0B'0C'0D};

        return bytes.as_str[0] == 0x0A;
    }

    [[nodiscard]]
    constexpr bool little_endian()
    {
        union
        {
            uint32_t i;
            char as_str[4];
        } bytes = {0x0A'0B'0C'0D};

        return bytes.as_str[0] == 0x0D;
    }
}


#endif // __SYSTEM_HPP
