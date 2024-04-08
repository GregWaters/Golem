#ifndef __UTILITY_HPP
#define __UTILITY_HPP

#include <cstdlib>

typedef unsigned long long size_type;

template <typename T, typename size_type = size_t>
class dynamic_container // This class is a base for others to be inherited from
{
protected:
    size_type m_size = 0;
    size_type m_capacity = 1;
    T* m_internal = static_cast<T*>(malloc(0));

    void expand_if_needed(size_type count)
    {
        m_size += count;
        if (m_size < m_capacity)
        {
            m_capacity <<= 1;
            m_internal = static_cast<T*>(realloc(m_internal, sizeof(T) * m_capacity));
        }
    }

    size_type size() const
    {
        return m_size;
    }

    void resize(size_type new_size)
    {
        m_size = new_size;
    }

    void shrink_to_fit()
    {
        m_capacity = m_size;
    }
};


#endif // __UTILITY_HPP

