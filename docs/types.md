# Signed Integers
Signed integers are declared using the `int` keyword. Signed integers are distinct in their reservation of the most significant bit to serve as the 'sign bit', used to determine whether or not a given number is negative.
Signed overflow is well-defined behavior in Golem, as only two's complement math is directly supported. 

# Unsigned Integers
Unsigned integers are declared using the `uint` keyword. Unsigned integers 
A boolean type only requires 1 bit, so it is defined as `uint<1>` internally.

Unsigned arithmetic is as simple as it gets, as you never have to deal with signedness and the issues that come along with it.
However, it should be noted that unsigned arithmetic allows for overflow mishaps to happen a lot easier.

# Bit Specifier
Optionally, a non-negative number `N` contained within angled brackets will determine the number of bits reserved for an integer type. By default, `N` is equal to 32.
All bit specifiers must be a power of 2 (alternatively `popcnt(N) == 1`) and must be at most 512.
The reasoning behind these limitations is to aid in compiler design simplicity (if we put limits on things, we don't have to use dynamic memory allocation as much in the compilation process).
The restriction to power of two reduces the chance of several implicit casts being used in the generated assembly.

# Why not allow any number for `N`?
Implicit casting is the devil, that's why! You may think that you're being proactive by telling the compiler that you only need *this* many bits, but it can't represent that easily, so it needs to have some tricks up its sleeve.

For example, we have a C function that returns an `int<5>`, taking two parameters in `int<7> x` and `int<4> y`.
```C
_BitInt(5) add(_BitInt(7) x, _BitInt(4) y)
{
    return x + y;
}
```

GCC 14.1 (-O2) compiles this to
```nasm
; Total bytes = 14
add:
  sal esi, 4
  sar sil, 4
  lea eax, [rdi+rsi]
  and eax, 31
  ret
```

However, if we disallowed these, we can eliminate these implicit casts entirely, and in doing so we change the code's structure as such:
```C
typedef _BitInt(8) byte;

byte add(byte x, byte y)
{
    return x + y;
}
```

Resulting in the compiled assembly being much less complex
```nasm
; Total bytes = 4
add:
  lea eax, [rdi+rsi]
  ret
```

That means that this small change made the function *3.5 times smaller*. Not to mention the saved clock cycles.
I should mention that this is not just applicable to functions, this is everything in your code.
