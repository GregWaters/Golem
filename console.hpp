#ifndef __CONSOLE_HPP
#define __CONSOLE_HPP

#include "input.hpp"
#include "output.hpp"

namespace console
{
    void clear()
    {
        #if defined(OS_WINDOWS)
        print("\033[2J");

        #elif defined(OS_LINUX)
        print("\033[1;1H\e[2J");

        #endif
    }
}
#endif // __CONSOLE_HPP
