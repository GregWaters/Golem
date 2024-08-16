# Signed Integers

Signed integers are declared using the `int` keyword. Signed integers are distinct in their reservation of the most significant bit to serve as the 'sign bit', used to determine whether or not a given number is negative.
Signed overflow is well-defined behavior in Golem, as only two's complement math is explicitly supported.

# Unsigned Integers

Unsigned integers are declared using the `uint` keyword.

Unsigned arithmetic is as simple as it gets, as you never have to deal with signedness and the issues that come along with it.
However, it should be noted that unsigned arithmetic allows for overflow mishaps to happen a lot easier.

# Booleans

The only values a variable of type `bool` is capable of holding are `true` and `false`.
Doing so only requires a single bit, so it is defined as `uint<1>` internally.

# Character types

`char` is implicitly an unsigned type. `schar` is a signed character type of the same size. There are no safeguards to prevent you from adding characters together.
If you add a character to another, you will get a _character_, not a _string_.

# Arrays

Arrays are completely static-sized in Golem, but you are able to modify the values held within them after initialization.
As an example, lets declare an array of digits with the type `uint<4>`; `array<uint<4>, 8> pi_digits`, and potentially initialize it with braced array values as such; `{ 3, 1, 4 }`.
Note that we did not use all 8 spaces, and the remaining values of the array are initialized to the given type's representation of `null`.

# Vectors (work in progress, may not exist in the final standard)

Vector types are very powerful for efficient data processing. Vectors can perform math on multiple integers at a time.
To declare a vector, we use the `vector` type keyword and then specify the type and size (in that order).
Here's the declaration for a simple vector of pixels for perhaps modifying a large image in an image manipulation software; `vector< uint<8>, 64 >`
For example, lets declare a function to compare a bunch of characters!

```
func strcmp64 ( vector<char, 64> a, vector<char, 64> b ) -> bool
{
    return a == b;
}
```

To better explain why this is included as a built-in type, here's the equivalent code in C (only available in the recent C23 standard);

```C
bool strcmp64(char a[static 64], char b[static 64])
{
    return *(_BitInt(512) *) a == *(_BitInt(512) *) b;
}
```

This is ridiculously unsafe due to C's semantics on passing arrays as pointers. Many C programmers would consider vectorizing this function 'premature optimization'.
Which, itself, is only a problem *because* you sacrifice readability and adaptability for raw performance.

Vectors provide type-safety **and** don't make your performant program kick rocks and segfault while it's trying to run!

# Floating-point Types

There isn't as much flexibility in floating-point types relative to integral types. The bit specifier must be a power of two between 8 and 256 (inclusive).
This defines relatively few floating-point types that can be defined.

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

Optionally, a non-negative power-of-two `N` contained within angled brackets will determine the number of bits reserved for a primitive type.

# Implied size of all primitive types

Every type has a size, even if it's not shown.

| Type  | Size |
| ----- | ---- |
| int   | `sizeof(int) * 8` in C |
| uint  | `sizeof(unsigned) * 8` in C |
| char  | 8    |
| schar | 8    |
| float | 32   |
