#ifndef __BIGINT_HPP
#define __BIGINT_HPP

// Use native assembly for the bigint class
// For x86_64, I believe this is the `ADCX` instruction
#include "cpuarch.hpp"

#include <vector>
#include <cstdint>
#include <cmath>
#include <string>
#include <limits>

// Arbitrary precision signed integer (naive implementation)
// Might not even compile, I don't know yet
class bigint
{
private:
    std::vector<unsigned int> m_internal;
    bool m_sign = false;

    inline size_t& operator[](size_t index)
    {
        return m_internal[index];
    }

public:
    operator+=(unsigned int value)
    {
        size_t index = 0;

        while (overflow)
        {
            ++index;
        }
    }
};

#endif // __BIGINT_HPP