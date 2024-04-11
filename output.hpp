#ifndef __OUTPUT_HPP
#define __OUTPUT_HPP

// TODO: Directly interact with individual operating systems instead of wrapping around pre-existing functions

#include <cstdio>
#include <cstring>
#include <unistd.h>
#include <string>

#include "system.hpp"

inline int output(const size_t bytes, const char* str)
{
    #if defined(OS_WINDOWS)
    return WriteConsole(GetStdHandle(STD_OUTPUT_HANDLE), str, bytes, 0, 0);

    #elif defined(OS_LINUX)
    return write(STDOUT_FILENO, str, bytes)

    #endif
}

// Recursive variadic print function
template <typename... args>
inline void print(args... elements)
{
    std::string str;
    for (const auto p : {elements...})
        str += std::to_string(p);

    output(str.size(), str.c_str());
}

template <typename T>
inline void println(const T value) // Check if this is valid
{
    print(value);
    print('\n');
}

#endif // __OUTPUT_HPP
