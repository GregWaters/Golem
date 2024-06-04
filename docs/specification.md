# Credits
- Greg Waters, 2024

# Overview (why would I use Golem?)
The largest part of learning a language is how it will help you make what you want to make.
Golem has been designed from the ground up to benefit all kinds of programmers. Unless you do web-dev, but you did that to yourself.

Golem got its name while I was trying to think of a creature that embodies all the things I want the language to be; ***solid, stable, and simple.***

# Philosophy
> *Make it work, then make it right.*

It's easy to make a working product in Golem, but if you want to make it *right*,
you are encouraged to tune your code like a piano until it's something you can truly be proud of.

> *Don't do anything at runtime that can be done at compile-time*

Because Golem is compiled, we can employ truly lossless abstraction techniques to remove ambiguity in code (see "Representing Data" below).
Things like code compression in Javascript or Python bytecode compilation and subsequent interpretation aren't things you have to worry about.
This means that we can fully analyze the code from all angles to see the best way to generate code for the processor.
Of course, this has its limits. For instance, we don't want to inline every function call as that would massively bloat the resulting machine code (see C++ methods),
nor would we want to statically link everything for the sake of performance (see Golang).

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

Types can be defined with the `type` keyword. Although the syntax is very similar to a standard variable, it should be noted that it holds *identifiers* in your program, not standard values.

Listed below is the standard syntax for declaring variables with their respective types
(while these are all primitive types, equivalent declarations are above in comments):
```java
# int<LONGSIZE>
int n { 5 }

# type bool { uint<1> }
bool we_there_yet { false }

# type byte { uint<8> }
byte bitmask { 0b10101010 } # support for binary literals!

# type word { uint<WORDSIZE> }
word word_max { (word) -1  }

# (No equivalent definition)
byte arr<4> { 1, 3, 3, 7 }

# type str { byte arr }
str hello { "Hello, world!" } # an array of 14 bytes (including the implicit null-terminator)
```

# Representing Data
Data can be represented in many ways, but most data is held between braces (`{}`). There are many built-in features to better represent data.
For example, lets say you need define a type that holds some data, such as an ipv4 address. So, of course, you define a type so nobody gets it mixed up in linear algebra functions like so
```java
type ipv4_addr { uint<32> }
```
However, this presents an issue. You assign the value 2147483649 to the address and none of your poor co-workers have any idea what that means. However, you went to Golem school, so you clearly know what to do next. You face your co-workers and say, *fear not, for data is part of the design of this language*, and hastily redefine the variable as a graceful cast to a(n implicitly 4-element) byte array that holds the *exact same data* in a *different, more readable format!*
```java
ipv4_addr loopback { (byte arr) {127, 0, 0, 1} }
```
As you can see, this casts an array of standard 32-bit integers to a literal array of bytes with implied size (8-bit integers). Then, the initialization occurs and the variable reads 32 bits into the array literal, finding the data we entered exactly as planned.

# Attributes
Attributes are possibly the most important part of the language specification. They apply to functions, variables, types, and pretty much anything.
We want the compiler to know exactly as much about our program as we do. Golem has some of its roots in more functional languages,
as I believe there's lessons to learn there even if you don't care for the whole functional death-cult thing.

Let's say you're defining a function named `square` that takes a type as input and returns its value times itself. This is quite trivial and can be defined as
```java
square(int x) -> int
{
    return x * x
}
```
And that's perfectly fine, but what if we wanted to tell the compiler that this function is entirely stateless? The answer, of course, is the explosive power of *attributes*.
With one line of code, we can avoid several redundant lines of machine code (you can't see this, but it's there I promise :)
```java
@pure @inline
square(int x) -> int
{
    return x * x
}
```
`@pure` tells the compiler that the next function declaration does not modify global variables or outside memory (Input/Output, global variables, etc.) and
`@inline` tells the compiler that the function call should be eliminated entirely, and the machine code should simply be placed wherever a call occurs.
This allows for each call to be optimized to fit the current use (for example, if one parameter is a constant value, the function doesn't have to treat it as unknown),
but be aware that your code size may greatly increase if you apply this attribute to large functions!

# Integer Arithmetic

Working with integers is similar to how C deals with integers. The arithmetic type is the left operand and the right operand is casted to the given arithmetic type to get the resulting value.
This will later be expanded upon more in detail.

# Keeping track of everything (advanced and boring topic)
Golem uses its own, optional calling convention, that's not even a convention in itself.
Each function implicitly keeps track of the registers it clobbers to decide whether or not registers need to be pushed to the stack beforehand.
Additionally, when working with operating-system specific code, you have the choice to use direct system calls instead of API calls.

Furthermore, *all* register values are kept track of and can use processor-specific code when possible.
For example, if the `EAX` register needs to be set to `VALUE`, here's some C/C++ code that shows the compiler's thinking.
```cpp
if (EAX == VALUE)
    encode(NULL);
else if (EAX == (VALUE - 1))
    encode("INC EAX");
else if (EAX == (VALUE + 1))
    encode("DEC EAX");
else
    encode("MOV EAX, VALUE");
```

# TBA?
There's *much* to be decided on here. I want to avoid making all the decisions myself,
because I'd much prefer if this language was molded in part by the people who will eventually use it.
That means that all suggestions will be weighed against each other to get the *best possible* result.

Happy coding!
