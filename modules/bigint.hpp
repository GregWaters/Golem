#ifndef __BIGINT_HPP
#define __BIGINT_HPP

// Use native assembly for the bigint class
// For x86_64, I believe this is the `ADCX` instruction
#include "cpuarch.hpp"
#include <vector>

class bigint
{
    bool m_sign = false;
    std::vector<unsigned char> m_bytes;

public:
    // TODO
};

#endif // __BIGINT_HPP