# Signed Integers

Signed integers are declared using the `int` keyword. Signed integers are distinct in their reservation of the most significant bit to serve as the 'sign bit', used to determine whether or not a given number is negative.
Signed overflow is well-defined behavior in Golem, as only two's complement math is explicitly supported.

# Unsigned Integers

Unsigned integers are declared using the `uint` keyword. Unsigned integers
A boolean type only requires 1 bit, so it is defined as `uint<1>` internally.

Unsigned arithmetic is as simple as it gets, as you never have to deal with signedness and the issues that come along with it.
However, it should be noted that unsigned arithmetic allows for overflow mishaps to happen a lot easier.

# Character types

`char` is implicitly an unsigned type. `schar` is a signed character type of the same size. There are no safeguards to prevent you from adding characters together.
If you add a character to another, you will get a _character_, not a _string_.

# Floating-point Types

There isn't as much flexibility in floating-point types relative to integral types. The bit specifier must be a power of two between 8 and 256 (inclusive).
This defines relatively few floating-point types that can be defined. Here's a list of possible names for them (these are not part of the standard):

```nasm
; Each IEEE floating-point type will have the bits shown above it, commented.
; Each number denotes the sign bit, exponent bits, and mantissa bits respectively.

; 1.5.10
float<16>

; 1.8.23
float<32>

; 1.11.52
float<64>

; 1.15.112
float<128>

; 1.19.236
float<256>
```

# Bit Specifier

Optionally, a non-negative power-of-two `N` contained within angled brackets will determine the number of bits reserved for a primitive type. By default, `N` is equal to 32.

# Implied size of all primitive types

Every type has a size, even if it's not shown.

| Type  | Size |
| ----- | ---- |
| int   | 32   |
| uint  | 32   |
| char  | 8    |
| schar | 8    |
| byte  | 8    |
| float | 32   |
| data  | 8    |
