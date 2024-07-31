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

# The `data` Type

Every literal in Golem is given a type, due to the semantics of arithmetic evaluation within the language. However, **all** literals have one unified type, and that type is named `data<8>` - a byte-sized type for the typeless.

Data is everywhere in the Golem language. However, it's even more omnipresent than you'd think, even after reading up on the 'Representing data' section.
Strings are an array of bytes with `0x00` byte at the end to signal termination. It is important to remember that **this is all just an array of bytes**. Under the hood, a string is stored similarly to the code block below.

```nasm
; These expressions are identical
"Hello!"
{ 0x48, 0x65, 0x6C, 0x6C, 0x6F, 0x21, 0x00 }
```

This is what a literal looks like before and after a cast:

```nasm
; assigning a literal array of variably sized integers in the data<8> format to an integer array
[uint<32>] arr { 0x48656C6C, 0x6F21, 0x00 }

; (the actual value of arr)
; { 0x48656C6C, 0x6F210000, 0x00000000 }
```

As you've likely noticed, all of these expressions are meaningless without something to interpret their meaning.
Using a `print` function on any of these types will spell ambiguity, as we never assigned a type to the data!
If you haven't figured it out already, we give meaning to data when we assign it to a _typed variable_.

Indeed, the only reason this data has any meaning at all is through implicit casting. When I call a function that prints out a character, the parameter must have a type in order to exist. For example

```nasm
func print_char -> null
char ch
{
    ; (code)
}
```

where I could call `print_char` with any single byte, or with any non-explicit type, and interpret the value as a character. You may create array literals without assigning them to a variable.
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

# Enumerations

Declared with the `enum` type keyword, these are very similar to C enumerations.
Each element has a size reflected in the formula $2^{⌈log_2(N)⌉}$, where $N$ is the number of enum elements. If an expression with enumeration type is out of bounds for the given enumeration, the behavior is undefined.

```nasm
; red { 0b00 }
; blue { 0b01 }
; green { 0b10 }
enum color { red, blue, green }
```

`color` would be of type `uint<2>`, not able to be implicitly casted by definition.
The compiler is able to safely assume that the value stored in a variable of enumeration type `color` will never exceed the bounds of the lowest and highest element respectively.

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
