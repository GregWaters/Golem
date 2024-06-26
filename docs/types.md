# Signed Integers
Signed integers are declared using the `int` keyword. Signed integers are distinct in their reservation of the most significant bit to serve as the 'sign bit', used to determine whether or not a given number is negative.
Signed overflow is well-defined behavior in Golem, as only two's complement math is directly supported. 

# Unsigned Integers
Unsigned integers are declared using the `uint` keyword. Unsigned integers 
A boolean type only requires 1 bit, so it is defined as `uint<1>` internally.

Unsigned arithmetic is as simple as it gets, as you never have to deal with signedness and the issues that come along with it.
However, it should be noted that unsigned arithmetic allows for overflow mishaps to happen a lot easier.

# Floating-point Types
There isn't as much flexibility in floating-point types relative to integral types. The bit specifier must be a power of two between 8 and 256 (inclusive).
This defines relatively few floating-point types that can be defined. Here's a list of possible names for them (these are not part of the standard):
```nasm
; Each IEEE floating-point type will have the bits shown above it, commented.
; Each number denotes the sign bit, exponent bits, and mantissa bits respectively.

; 1.5.10
type float_half { float<16> }

; 1.8.23
type float_single { float<32> }

; 1.11.52
type float_double { float<64> }

; 1.15.112
type float_quadruple { float<128> }

; 1.19.236
type float_octuple { float<256> }
```

# Bit Specifier
Optionally, a non-negative number `N` contained within angled brackets will determine the number of bits reserved for an integer type. By default, `N` is equal to 32.
The maximum value for `N` is implementation defined, but will throw an error if `N` is exceeds this value. It is safe to assume that the maximum value is at *least* 512.

Originally, these values were required to be powers of two, but after working with the `_BitInt` type in C23, I really do think that it's unhealthy for the language as a whole to [assume that programmers don't know what they're doing](https://en.wikipedia.org/wiki/Rust_(programming_language)).

# The `data` Type
Every literal in Golem is given a type, due to the semantics of arithmetic evaluation within the language. However, **all** literals have one unified type, and that type is named `data` - a byte-type for the typeless.

Data is everywhere in the Golem language. However, it's even more omnipresent than you'd think, even after reading up on the 'Representing data' section.
Strings are an array of bytes with `0x00` byte at the end to signal termination. It is important to remember that **this is all just an array of bytes**. Under the hood, a string is stored similarly to the code block below.

```nasm
; These expressions are identical
"Hello!"
{ 0x48, 0x65, 0x6C, 0x6C, 0x6F, 0x21, 0x00 }
```

However, both of these expressions are meaningless without something to interpret their meaning.
Using a `print` function on any of these types will spell ambiguity, as we never assigned a type to the data!
If you haven't figured it out already, we give meaning to data when we assign it to a *typed variable*.

Indeed, the only reason this data has any meaning at all is through implicit casting. When I call a function that prints out a character, the parameter must have a type in order to exist. For example

```nasm
func print_char -> null
char ch
{
    ; (code)
}
```

where I could call `print_char` with any single byte, or with any non-explicit type, and interpret the value as a character. Unlike in C, you can create array literals without assigning them to a variable.
These literals may be stored in the `.data` section or the `.text` section, depending on the size and architecture of the compile target.

Here's an example of `data` being used correctly.

```nasm
func bswap16 -> data<16>
data<16> input
{
    return ((input & 0x00FF) << 8) | ((input & 0xFF00) >> 8)
}
```

Sending/receiving type-agnostic data is invaluable in many different scenarios, like memory allocation and computer networking.
