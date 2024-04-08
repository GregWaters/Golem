#ifndef __string_hpp
#define __string_hpp

#include "utility.hpp"

class string
{
    unsigned long long m_length;
    unsigned long long m_capacity;
    char* m_str;

public:
    string()
    {
        m_length = 0;
        m_capacity = 0;
        m_str = static_cast<char*>(malloc(0));
    }

    ~string()
    {
        free(m_str);
    }

    constexpr char* begin() const
    {
        return m_str;
    }

    constexpr char* end() const
    {
        return m_str + m_length;
    }

    constexpr unsigned long long length() const
    {
        return m_length;
    }


    void resize(unsigned long long new_size)
    {
        m_length = new_size;
    }


    void reserve(unsigned long long new_capacity)
    {
        m_capacity = new_capacity;
    }

    [[nodiscard]]
    bool empty()
    {
        return this->m_length == 0;
    }

    char operator[](unsigned long long index)
    {
        return *(this->m_str + index);
    }

    void operator+=(const char c)
    {
        this->m_str[m_length] = c;
        ++m_length;
    }

    void operator+=(const string& str)
    {
        for (const char c : str)
            *this += c;
        m_length += str.length();
    }

    void operator=(const char* str)
    {

    }

    T& operator[](size_t index)
    {
        return m_internal[index];
    }



};

#endif // __string_hpp

