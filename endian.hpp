#ifndef __ENDIAN_HPP
#define __ENDIAN_HPP

// hash-defines for pre-processor evaluation

#define LITTLE_ENDIAN 0x41424344UL
#define BIG_ENDIAN    0x44434241UL
#define ENDIAN_ORDER  ('ABCD')

// Variables for compile-time / runtime evaluation

namespace endian
{
#if ENDIAN_ORDER == LITTLE_ENDIAN
    constexpr bool little = true;
    constexpr bool big = false;
#elif ENDIAN_ORDER == BIG_ENDIAN
    constexpr bool little = false;
    constexpr bool big = true;
#else
    #error Unable to determine byte ordering (did you *have* to use a PDP to compile this?)
#endif
}


#endif // __ENDIAN_HPP
