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
    #include "unistd.h"
    
#else
    #error "Your operating system is not yet supported"

#endif
// End operating system macro definition

#endif //__SYSTEM_HPP
