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
The maximum value for `N` is implementation defined, but will throw an error if `N` is exceeds this value. It is safe to assume that the maximum value is at *least* 512.

Originally, these values were required to be powers of two, but after working with the `_BitInt` type in C23, I really do think that it's unhealthy for the language as a whole to [assume that programmers don't know what they're doing](https://en.wikipedia.org/wiki/Rust_(programming_language)).
