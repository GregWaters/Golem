#ifndef __CPUARCH_HPP
#define __CPUARCH_HPP

namespace cpu
{
    enum class arch
    {
        X86_64,
        X86_32,
        ARM2,
        ARM3,
        ARM4T,
        ARM5,
        ARM6T2,
        ARM6,
        ARM7,
        ARM7A,
        ARM7R,
        ARM7M,
        ARM7S,
        ARM64,
        MIPS,
        SUPERH,
        POWERPC,
        POWERPC64,
        SPARC,
        M68K,
        UNKNOWN
    };

    constexpr arch get_arch()
    {
        #if defined(__x86_64__) || defined(_M_X64)
        return arch::X86_64;
        #elif defined(i386) || defined(__i386__) || defined(__i386) || defined(_M_IX86)
        return arch::X86_32;
        #elif defined(__ARM_ARCH_2__)
        return arch::ARM2;
        #elif defined(__ARM_ARCH_3__) || defined(__ARM_ARCH_3M__)
        return arch::ARM3;
        #elif defined(__ARM_ARCH_4T__) || defined(__TARGET_ARM_4T)
        return arch::ARM4T;
        #elif defined(__ARM_ARCH_5_) || defined(__ARM_ARCH_5E_)
        return arch::ARM5;
        #elif defined(__ARM_ARCH_6T2_) || defined(__ARM_ARCH_6T2_)
        return arch::ARM6T2;
        #elif defined(__ARM_ARCH_6__) || defined(__ARM_ARCH_6J__) || defined(__ARM_ARCH_6K__) || defined(__ARM_ARCH_6Z__) || defined(__ARM_ARCH_6ZK__)
        return arch::ARM6;
        #elif defined(__ARM_ARCH_7__) || defined(__ARM_ARCH_7A__) || defined(__ARM_ARCH_7R__) || defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7S__)
        return arch::ARM7;
        #elif defined(__ARM_ARCH_7A__) || defined(__ARM_ARCH_7R__) || defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7S__)
        return arch::ARM7A;
        #elif defined(__ARM_ARCH_7R__) || defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7S__)
        return arch::ARM7R;
        #elif defined(__ARM_ARCH_7M__)
        return arch::ARM7M;
        #elif defined(__ARM_ARCH_7S__)
        return arch::ARM7S;
        #elif defined(__aarch64__) || defined(_M_ARM64)
        return arch::ARM64;
        #elif defined(mips) || defined(__mips__) || defined(__mips)
        return arch::MIPS;
        #elif defined(__sh__)
        return arch::SUPERH;
        #elif defined(__powerpc) || defined(__powerpc__) || defined(__powerpc64__) || defined(__POWERPC__) || defined(__ppc__) || defined(__PPC__) || defined(_ARCH_PPC)
        return arch::POWERPC;
        #elif defined(__PPC64__) || defined(__ppc64__) || defined(_ARCH_PPC64)
        return arch::POWERPC64;
        #elif defined(__sparc__) || defined(__sparc)
        return arch::SPARC;
        #elif defined(__m68k__)
        return arch::M68K;
        #else
        return arch::UNKNOWN;
        #endif
    }
}

#endif // __CPUARCH_HPP