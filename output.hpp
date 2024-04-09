#ifndef __OUTPUT_HPP
#define __OUTPUT_HPP

// TODO: Directly interact with individual operating systems instead of wrapping around pre-existing functions

#include <cstdio>
#include <cstring>
#include <unistd.h>

#include "system.hpp"

inline void output(const size_t bytes, const char* str)
{
    #if defined(OS_WINDOWS)
    WriteConsole(GetStdHandle(STD_OUTPUT_HANDLE), str, bytes, 0, 0);

    #elif defined(OS_LINUX)
    // TODO: Silence warning about unused return value by throwing exceptions based on the retval
    write(STDOUT_FILENO, str, bytes);

    #endif
}

void print(const char c)
{
    output(1, &c);
}

void print(const char* str)
{
    output(std::strlen(str), str);
}

template <typename T>
inline void println(const T value)
{
    print(value);
    print('\n');
}

#endif // __OUTPUT_HPP
