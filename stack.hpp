#ifndef __STACK_HPP
#define __STACK_HPP

#include "utility.hpp"

template <typename T, typename size_type = size_t>
class stack : utils::dynamic_container<T, size_type>
{
private:
    unsigned long long size;
};


#endif // __STACK_HPP

