#ifndef __BIGINT_HPP
#define __BIGINT_HPP


#include <vector>
#include <cstdlib>

// Bigint class -- inherits from `long_array` with a size_type of `unsigned int`
// If anyone encounters an overflow issue, please check your supercomputer in at the door, as the max value is so large that my calculator just prints `infinity`
// Have fun with it!
class unsigned_bigint
{
    // It's not a raw pointer if you just let me cook
    unsigned int* m_internal;
    unsigned int m_size;


    // Get current size
    size_type size() const
    {
        return m_size;
    }


    // Allocate memory for `n` integers -- typically called within a constructor
    // Note that there should be a call to `deallocate()` for every call to `allocate()`
    void allocate(const size_type n)
    {
        m_internal = static_cast<value_type*>(std::malloc(n * sizeof(value_type)));
    }


    // Free all memory -- typically called within a destructor
    void deallocate()
    {
        std::free(m_internal);
    }


    // Debug tool
    void print()
    {
        std::putchar('[');
        for (int i = 0; i < size(); ++i)
            std::printf("%010d, ", m_internal[i]);
        std::putchar(']');
    }


    // Reserve `amount` integers in the internal array
    void reserve(size_type amount)
    {
        m_internal = std::realloc(m_internal, amount * sizeof(size_type));
        
        if (m_internal == nullptr)
            throw std::bad_alloc;
    }


    // Random access operator
    value_type& operator[](size_type index)
    {
        return m_internal[index];
    }


public:
    unsigned_bigint()
    {
        allocate(4);
    }


    ~unsigned_bigint()
    {
        deallocate();
    }


    // Conversions

    operator int()
    {

    }

    operator double()
    {
        
    }
    


    operator+(unsigned int x) const;
    operator-(unsigned int x) const;
    operator*(unsigned int x) const;
    operator/(unsigned int x) const;
    operator+=(unsigned int x);
    operator-=(unsigned int x);
    operator*=(unsigned int x);
    operator/=(unsigned int x);
    
    
    // Boolean operations
    
    operator!=(unsigned_bigint b) const
    {
        if (b.size() != size())
            return true;
        
        for (int i = 0; i < size(); ++i)
            if (b.m_internal[i] != m_internal[i])
                return true;
        return false;
    }


    operator==(unsigned_bigint b) const
    {
        // lol ez
        return !(operator!=(b));
    }


    operator<(unsigned_bigint b) const;
    operator>(unsigned_bigint b) const;
    operator<=(unsigned_bigint b) const;
    operator>=(unsigned_bigint b) const;
};

class bigint
{
    bool m_sign;

public:
    // Get the sign bit
    bool sign()
    {
        return m_sign;
    }
};

#endif // __BIGINT_HPP