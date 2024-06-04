# Credits
- Greg Waters, 2024

# Use case
The largest part of learning a language is how it will help you make what you want to make. This language has been designed from the ground up with systems engineering and compiler design in mind,
but it does not restrict itself to these applications.
As I am a systems engineer by day, just trust me on that one. This language is ***not*** designed to replace C or C++, but to serve as an alternative for those who share my ideas on syntax-oriented design.

Golem got its name while I was trying to think of a creature that embodies all the things I want the language to be; ***solid, stable, and simple.***

# Comments
All comments are denoted with the `#` symbol, and last for the rest of the line.

# Types
Types are a large part of the underlying structure of the Golem language. Using clean, yet descriptive type names denotes intention.
Some types can be used with angled brackets (`<>`) to give extra information to their use case.
For an example with the `int` type, the integer's bits can be specified within the parameter, as in a standard 64-bit integer here: `int<64>`.
You can also specify larger arithmetic types, like `int<512>`. This has many uses in cryptography and other fields that have to use massive integers, like scientific computation.

Boolean types can also be easily represented in this format, as `uint<1>` is just as valid as any other bit specifier. The more astute of you may think that there is no reason to hold just one
bit in a type, as you cannot pass 1 bit in any standard assembly register. However, this is not the only purpose of the bit specifier.
Because you can not only pass bit specifiers that are larger than your system's long bit (`sizeof(long long)` in C/C++),
but also specifiers that are *smaller*, you give a hint to the compiler that this type can only hold up to 2 possible values. This helps keep your compiled code smaller and faster.

Bit specifiers should be passed as unsigned integers. The maximum value is at least 512. Bit specifiers can only be powers of 2.
If a bit-specifier does not meet these requirements, the compiler should throw an error.

Types can be defined with the `type` keyword, similar to variables in syntax.

Standard type syntax:
```
bool we_there_yet { false }
byte bitmask { 0b10101010 } # type byte { uint<8> }
word # type word { uint<WORDSIZE> }
int  # int<LONGSIZE>
byte arr<4> { 1, 3, 3, 7 } # a 4-element byte array -- can be declared with any type, including the array type itself.
str hello { "Hello, world!" } # an array of 14 bytes (including the implicit null-terminator) 
```

# Representing data
Data can be represented in many ways, but most data is held between braces (`{}`). There are many built-in features to better represent data.
For example, lets say you need define a type that holds some data, such as an ipv4 address. So, of course, you define a type so nobody gets it mixed up in linear algebra functions like so
```
type ipv4_addr { uint<32> }
```
However, this presents an issue. You assign the value 2147483649 to the address and none of your poor co-workers have any idea what that means. However, you went to Golem school, so you clearly know what to do next. You tell your co-workers, *fear not, for data is part of the design of this language*, and hastily redefine the variable as a graceful cast to a 4-element byte array that holds the *exact same data* in a *different, more readable format*
```
ipv4_addr loopback { (byte arr) {127, 0, 0, 1} }
```

# Integer arithmetic

Working with integers within this standard is meant to be intuitive. If you are familiar with other standard arithmetic, it is no different.
The most significant bit in a signed integral type is referred to as the *sign bit*, and integers of this type invoke undefined behavior on overflow.

In all integer types, both operands in a syntax tree are cast to the type of the left operand.

