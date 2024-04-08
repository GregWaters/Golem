#ifndef __string_hpp
#define __string_hpp

#include "utility.hpp"
#include "system.hpp"

template <typename size_type = unsigned int>
class string : protected dynamic_container<char, size_type>
{
public:
    ~string()
    {
        free(this->m_internal);
    }

    const char* internal()
    {
        return dynamic_container<char, size_type>::m_internal; // This is why people hate OOP
    }

    constexpr char* begin() const
    {
        return this->internal();
    }

    constexpr char* end() const
    {
        return this->internal() + this->size();
    }

    void reserve(const size_type new_capacity)
    {
        this->m_capacity = new_capacity;
    }

    [[nodiscard]]
    bool empty() const
    {
        return this->size() == 0;
    }

    char operator[](const size_type index)
    {
        return *(this->internal() + index);
    }

    void operator=(const char* str)
    {
        for (int i = 0; str[i]; ++i)
            this->m_internal[i] = str[i];
    }

    string operator+(const char c)
    {
        string str = *this;
        this->expand_if_needed(1);
        this->m_internal[this->m_size] = c;
        return str;
    }
};

template <typename size_type = unsigned int>
void print(const string<size_type>& str)
{
    #if defined(OS_WINDOWS)
    WriteConsole(GetStdHandle(STD_OUTPUT_HANDLE), str.internal(), str.size(), 0, 0);

    #elif defined(OS_LINUX)
    write(stdout, str.internal(), bytes);

    #endif
}


#endif // __string_hpp

