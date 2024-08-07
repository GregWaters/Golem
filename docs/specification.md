# Overview (why would I use Golem?)
The largest part of learning a language is how it will help you make what you want to make.
Golem has been designed from the ground up to benefit all kinds of programmers. Unless you do web-dev, but you did that to yourself.

Golem got its name while I was trying to think of a creature that embodies all the things I want the language to be; ***solid, stable, and simple.***

# Philosophy
> *Make it work, then make it right.*

It should be easy to make a working product in Golem, but if you want to make it *right*,
you are encouraged to tune your code like a piano until it's something you can truly be proud of.

> *Don't do anything at runtime that can be done at compile-time*

Because Golem is compiled, we can employ truly lossless abstraction techniques to remove ambiguity in code (see "Representing Data" below).
Things like code compression in Javascript or Python bytecode compilation and subsequent interpretation aren't things you have to worry about.
This means that we can fully analyze the code from all angles to see the best way to generate code for the processor.

Of course, this has clear limits. For instance, we don't want to [inline every function](https://en.wikipedia.org/wiki/C%2B%2B_classes) as that would massively bloat the resulting machine code,
nor would we want to [statically link everything for the sake of compatibility](https://en.wikipedia.org/wiki/Go_(programming_language)).

# Comments
Comments last until the next occurrence of a newline character, and begin with the `;` character. This was originally planned to be similar to Python and Bash, with `#` as the designated start of a comment, but I feel that it is much better to kill two birds with one stone. With semicolons as the comment character, code like
```cpp
return 0;
```
is entirely valid. This makes the language easier to learn for people who know languages like Java, C, and C++, where all statements are terminated with a semicolon.

Additionally, comments can be placed immediately after a semicolon in this C-style formatting, making documentation just that much easier.
```cpp
func square -> int<32>
int<32> n
{
    return n * n ; multiply n by itself to get a square value
}
```

# Escape Characters
Largely similar to C, escape characters are denoted with a `\` character. Some characters do not have any printed representation, such as a NUL character ('\0').
Others may be impractical to include in source code for practicality reasons, such as the newline character ('\n').
These character literals can be used in place of a character in a string or on their own as a literal value.

It should also be noted that, within the source file, you can escape a newline character in order to break a line without breaking your code.
This is almost necessary, as newlines are the 'semicolon' of the Golem language.

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
(equivalent declarations are above in comments):
```java
; int<LONGSIZE>
int n { 5 }

; type bool { uint<1> }
bool we_there_yet { false }

; type byte { uint<8> }
byte bitmask { 0b10101010 } ; support for binary literals!

; type word { uint<WORDSIZE> }
word word_max { (word) -1  }
```

# Representing Data
Data can be represented in many ways, but most data is held between braces (`{}`). There are many built-in features to better represent data.
For example, lets say you need define a type that holds some data, such as an ipv4 address. So, of course, you define a type so nobody gets it mixed up in linear algebra functions like so
```java
type ipv4_addr { uint<32> }
```
However, this presents an issue. You assign the value 2147483649 to the address and none of your poor co-workers have any idea what that means. However, you went to Golem school, so you clearly know what to do next. You face your co-workers and say, *fear not, for data is part of the design of the language*, and hastily redefine the variable as a graceful cast to a(n implicitly 4-element) byte array that holds the *exact same data* in a different, more readable format!
```java
ipv4_addr loopback { [byte]( {127, 0, 0, 1} ) }
```
As you can see, this casts an array of standard 32-bit integers to a literal array of bytes with implied size (8-bit integers).
Then, the initialization occurs and the variable reads 32 bits into the array literal, finding the data we entered exactly as planned.
Note that if it reads beyond a defined data area, the compiler can safely assume that all undefined bytes are zero in the same way that assigning `0x42` to a 16-bit integer would implicitly give it the value `0x0042`.

```java
int<64> num { [byte]( {0xDE, 0xAF, 0xDE, 0xED} ) }
; num = 0x00000000DEAFDEED
```

# Modules
Golem will hopefully be the first to implement a working module system instead of the preprocessor copy-paste system that C and C++ programmers are familiar with.
Modules are a way to include external definitions without the overhead of opening, reading, and writing to several files.
And better yet, you can build in a defense against conflicting identifiers using the `as` keyword.
This is something I commend the Python ecosystem for endorsing, as it doesn't just make ***writing*** libraries easier, it makes ***using*** libraries easier.

For example,

```java
; Search the current directory (and optionally specified paths on the commandline) for this file 
include "mathlibraryname.mod" as math  

func main() -> int<32>
{
    print("pi = " + (str) math.pi)
    return math.log2(256) - 8 ; Exit with a success value (0) if log2 produces a valid answer (8)
}
```

This cuts down on compile times greatly, as you are not only preventing name collisions with the <module>.<function> syntax, but also letting the compiler know exactly where to look to find the declaration.

If an identifier is not found within a given module, an error should be thrown similar to "Could not find <IDENTIFIER> in module <MODULE>"

# Integer Arithmetic
Integer literals can be represented with any number of digits, unrestricted to the long bit size on the system. This goes hand-in-hand with other decisions made in respect to arbitrarily sized integers.
Because of this, we can define massive constant values very easily. However, I believe it also requires the use of arbitrary integer sizing when compiling code. It is unknown what side-effects this may cause.
Perhaps we could simply process them as strings, after they cross the 512-bit integer limit in length? Literals greater than `(1 << 64) - 1` or less than `-(1 << 63)` must be stored in the data section of the generated assembly,
as it does not support numbers beyond the 64-bit integer limit.

Off the topic of literals, the actual arithmetic. Arithmetic is not very special, as I don't want to overcomplicate a set-in-stone system for zero benefit (I see no way to improve the C-style evaluation).
Integers are evaluated with a standard binary tree evaluation process. The operand on the left is the destination, it will be replaced by the result. This is important to note because the left operand's type determines the type of the result.
This evaluation continues until no answer can reached (there is only one operand, or the value is indeterminate at compile-time and must be performed at runtime).

# TBA?
There's *much* to be decided on here. I want to avoid making all the decisions myself,
because I'd much prefer if this language was molded in part by the people who may eventually use it.
That means that all suggestions will be weighed against each other to get the *best possible* result.

Currently, I am trying to split this large file up into smaller, more easily read files.

Happy hacking!
