#ifndef __BENCHMARK_HPP
#define __BENCHMARK_HPP

#include <chrono>

namespace bench
{
    class timer
    {
        using Clock = std::chrono::high_resolution_clock;

        std::chrono::time_point<Clock> m_beg = Clock::now();

    public:
        void reset()
        {
            m_beg = Clock::now();
        }

        double elapsed() const
        {
            return std::chrono::duration_cast<std::chrono::microseconds>(Clock::now() - m_beg).count();
        }
    };


}

#endif // __BENCHMARK_HPP
