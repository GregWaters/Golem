#ifndef __OUTPUT_HPP
#define __OUTPUT_HPP

// TODO: Directly interact with individual operating systems instead of wrapping around pre-existing functions
#include "utility.hpp"

#include <cstring>
#include <cstdio>

static void output(const size_t bytes, const char* str)
{
    #if defined(OS_WINDOWS)
    WriteConsole(GetStdHandle(STD_OUTPUT_HANDLE), str, bytes, 0, 0);

    #elif defined(OS_LINUX)
    write(stdout, str, bytes);

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
void branch_print(T num)
{
    char digits[20];
    int i;

    if (num < 0)
    {
        digits[0] = '-';
        i = 1;
        num = -num;

        while (num)
        {
            digits[i] = num % 10 + '0';
            num /= 10;
        }
    }

    else
    {
        i = 0;
        do
        {
            digits[i] = (abs(num) % 10 + '0');
            num /= 10;
            ++i;
        } while (num);
    }

    output(i, digits);
}

template <typename T>
void print(T num)
{
    char digits[20];

    int i = 0;
    if (num < 0)
        digits[i++] = '-';

    do
    {
        digits[i] = (abs(num) % 10 + '0');
        num /= 10;
        ++i;
    } while (num);

    output(i, digits);
}

/*
void print(const float f)
{

}

void print(const double d)
{

}
*/

template <typename T>
inline void println(const T value)
{
    print(value);
    print('\n');
}

#endif // __OUTPUT_HPP
