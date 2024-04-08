#ifndef __MATH_HPP
#define __MATH_HPP

// Generic math library, balanced between speed and precision

template <typename T>
constexpr T abs(const T value)
{
    return (value > 0) ? value : -value;
}

template <typename T>
constexpr T& max(const T& t1, const T& t2)
{
    return (t1 > t2) ? t1 : t2;
}

template <typename T>
constexpr T& min(const T& t1, const T& t2)
{
    return (t1 < t2) ? t1 : t2;
}

constexpr double pow(const double base, int exp)
{
    double retval = 1;

    if (exp > 0)
        while (exp--)
            retval *= base;
    else
        while (exp++)
            retval /= base;

    return retval;
}

template <typename T>
constexpr long long pow(const T base, int exp)
{
    long long result = 1;
    for ( ; exp; --exp)
        result *= base;
    return result;
}


#endif // __MATH_HPP
