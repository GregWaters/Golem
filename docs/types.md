# Signed Integers
Signed integers are declared using the `int` keyword. Signed integers are distinct in their reservation of the most significant bit to serve as the 'sign bit', used to determine whether or not a given number is negative.

***IMPORTANT!*** - Signed integers are different in Golem than in most languages. This is due to the use of one's complement instead of two's complement.
There are many reasons why one's complement is better and worse than two's complement. Here's a rundown of the pros and cons;

**PROS**
- Simpler negation and absolute value - With one's complement, negation is as simple as doing a bitwise xor on the most significant bit.
  Likewise, absolute value is just as simple. 
- Absolute value of `~0` is no longer an issue - Getting the absolute value of a binary number that is all ones in standard two's complement format is perfectly safe, and does not require to throw an invalid argument.
  For example, in C/C++, `abs(-2147483648)` returns `-2147483648`, because two's complement simply cannot represent that number.
  One's compliment wraps around before this point, and unlike in C++, signed overflow is well-defined behavior.

**CONS**
- Signed zero - Some people dislike the possibility of a signed zero,
- ABI breakage - This will almost certainly break compatibility with C-based libraries. This is not to be understated, as many, many libraries are written in C primarily.
This would require an ABI using one's complement or would require many libraries to be rewritten in Golem.
Alternatively, a simple function could be used to convert Golem signed integers to C standard signed integers.

# Unsigned Integers
Unsigned integers are declared using the `uint` keyword. Unsigned integers 
A boolean type only requires 1 bit, so it is defined as `uint<1>` internally.

Unsigned arithmetic is as simple as it gets, as you never have to deal with signedness and the issues that come along with it.
However, it should be noted that unsigned arithmetic allows for overflow mishaps to happen a lot easier.

# Bit Specifier
Optionally, a non-negative number `N` contained within angled brackets will determine the number of bits reserved for an integer type. By default, `N` is equal to 32.
All bit specifiers must be a power of 2 (alternatively `popcnt(N) == 1`) and must be at most 512.
The reasoning behind these limitations is to aid in compiler design simplicity (if we put limits on things, we don't have to use dynamic memory allocation as much in the compilation process).
Additionally, the restriction to power of two reduces the chance of several implicit casts being used in the generated assembly.
