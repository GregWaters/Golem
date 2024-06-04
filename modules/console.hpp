#ifndef __CONSOLE_HPP
#define __CONSOLE_HPP

#include "system.hpp"

namespace console
{
    inline bool clear()
    {
        #if defined(OS_WINDOWS)
        return WriteConsole(GetStdHandle(STD_OUTPUT_HANDLE), "\e[2J", 4, 0, 0);

        #elif defined(OS_LINUX) || defined(OS_MAC)
        return (write(1, "\e[1;1H\e[2J", 10) != -1);

        #endif
    }
}

#endif // __CONSOLE_HPP
