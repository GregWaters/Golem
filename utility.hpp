#ifndef __UTILITY_HPP
#define __UTILITY_HPP

// Begin operating system macro definition
#if defined(__linux__)
#define OS_LINUX
#include "unistd.h"

#elif defined (_WIN32) || defined(__WIN32__) || defined(__WIN32) || defined(WIN32) || defined(__WIN64) || defined(__WIN64__)
#define OS_WINDOWS
#include "windows.h"

#elif defined(__APPLE__) || defined(macintosh) || defined(Macintosh)
#define OS_MAC
#error "Mac is not yet supported"

#else

#error "Your operating system is not yet supported"

#endif
// End operating system macro definition

#include <cstdlib>

typedef unsigned long long size_t;
namespace utility
{

// This class is a base for others to be inherited from

// TODO: overload [] operator for index access
    template <typename T>
    class dynamic_container
    {
    private:
        size_t m_size = 0;
        size_t m_capacity = 0;
        T* m_internal = static_cast<T*>(malloc(0));

        void expand_if_needed()
        {
            if (m_size < m_capacity)
            {
                m_capacity <<= 1;
                m_internal = static_cast<T*>(realloc(m_internal, sizeof(T) * m_capacity));
            }
        }

    public:
        size_t size() const
        {
            return m_size;
        }

        void append(const T& element)
        {
            ++m_size;
            expand_if_needed();

            m_internal[m_size] = element;
        }


    };
}

#endif // __UTILITY_HPP

