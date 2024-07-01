# Overview
Optimized machine code generation is not a large part of the Golem programming language - it is the largest part.
The programmer has plenty of opportunities to tune the code and give the compiler helpful hints at things it may have missed.
However, when hints are not employed, the compiler must be smart about how it traverses code.

# Dead-code elimination
There are a couple different kinds of dead-code. Both share one property, however: They will change nothing about the program's semantics if removed.

## Unreachable code
Unreachable code will *never* be executed by the machine, and is entirely useless within the program's executable.

INPUT:
```nasm
func foo -> int<32>
{
    if (false)
    {
        return 1
    }

    else
    {
        return 0
    }
}
```

OUTPUT:
```nasm
func foo -> int<32>
{
    return 0
}
```

## Unused variables
Unused variables are exactly what they sound like. They are variables that are written to, but never read.
This optimization is made much easier by the concept of scope. The variable only needs to be checked within its scope.

INPUT:
```nasm
func foo -> int<32>
{
    int<32> unused { 5 }

    return 0
}
```

OUTPUT:
```nasm
func foo -> int<32>
{
    return 0
}
```

# 'Tuning' optimization
This section is centered around optimizations that may have downsides if employed arrogantly. This includes all subheaders beneath this section header.

## Function inlining
The inlining of functions is discussed in *heavy* detail in [the inline guide](https://github.com/GregWaters/Golem/blob/master/docs/inline.md), but I'll go over the definition of function inlining briefly.
Essentially, we are able to optimize away a function call if the call itself causes significant overhead. There are several reasons why you would and would *not* want this to occur.

## Alignment
A very dicey subject that is relatively small in performance impact (depending on the application, of course) is alignment.
Some architectures work better when functions are aligned (x86, most notably). Although others (RISC-V, ARM) have implicit alignment by design.

The issues arise when programmers may want to optimize for program size, rather than speed. Adding NOPs to pad out functions does have an impact on code size.
Whether that difference in size is significant enough to warrant its removal/addition is entirely up to the compiler designer.

# Constant folding
One of the most well-known optimizations that nearly all optimizing compilers utilize. Constant folding is the precalculation of simple expressions containing at least two separate constant values.

## Within expressions

INPUT:
```nasm
func foo -> int<32>
{
    return 5 * 5
}
```

OUTPUT:
```nasm
func foo -> int<32>
{
    return 25
}
```

## Within loops

INPUT:
```nasm
func foo -> int<32>
{
    int<32> i   { 3 }
    int<32> sum { 0 }

    while (i > 0)
    {
        sum { sum + i }
        i { i - 1 }
    }

    return sum
}
```

OUTPUT:
```nasm
func foo -> int<32>
{
    int<32> i   { 0 }
    int<32> sum { 6 }

    return sum
}
```

## Constant propagation
Similar to constant folding, but involves keeping track of constant *variables*, which is a bit different. If variable expressions can be determined at compile-time, they should be.
If not, everything *but* the unknown variable should be evaluated.

INPUT:
```nasm
func foo -> int<32>
{
    int<32> x { 5 }
    int<32> y { 3 }

    return x + y
}
```

OUTPUT:
```nasm
func foo -> int<32>
{
    int<32> x { 5 }
    int<32> y { 3 }

    return 8
}
```

# Live range analysis
Live range analysis is the ability of a compiler to determine when a variable is "alive" (in scope) and when a variable is "dead" (out of scope).
Almost every programming language utilizes this technique, even interpreted languages. However, it is especially useful when *registers* are brought into play.

A simple system to determine if something is reserved is by associating a register with a metaphorical 'owner'.
When an owner is no longer able to be referenced, the register can be used by other variables.
If this sounds familiar, it is an extremely well-documented part of C++ and Rust's ability to make safe allocations of dynamic memory.

I will attempt to demonstrate a compiler deciding whether a register needs to remain allocated below, on a hypothetical system with only 2 registers - EAX and EBX.
Note that the example showcases a lot of dead code, but it is only to demonstrate the process.

```nasm
func foo -> int<32>
int<32> input_value ; Let input_value own EAX
{
    {
        int<32> tempval1 { 5 } ; tempval1 now owns EBX and stores 5 in it
    }
    ; Deallocate EBX here

    {
        int<32> tempval2 { 3 } ; tempval1 now owns EBX and stores 5 in it
    }
    ; Deallocate EBX here

    return input_value
}
; Change the owner of EAX to whatever expression foo's return value is used in
; If there is no owner (or if the return value is unused) deallocate EAX
```

# Tail-call optimization
Certain functions have a function call as their last instruction.
In these specific cases, the overhead of setting up a stack frame for a function call can be entirely avoided and the called function can simply reuse the previous function's stack frame.
This allows recursive functions to effectively act as a callable loop block.

# Arithmetic optimizations
Beyond this point, we will no longer cover optimizations that are unanimously used.
In this section, we'll go over some optimizations that not even LLVM or GCC have implemented (as of Clang 18.1 and GCC 14.1, respectively).

## Integral reduction of expressions
Shown below are ways to simplify unknown expressions into simpler, or even known (constant) expressions.

### Associative property
`(a + b) + c` == `a + (b + c)`,

`(a * b) * c` == `a * (b * c)`

### Commutative property
`a + b` == `b + a`,

`a * b` == `b * a`

`a | b` == `b | a`

`a & b` == `b & a`

`a ^ b` == `b ^ a`

### Distributive property
`a * b + a * c` == `a * (b + c)`

### Determine result of undefined expressions
`a & 0` == `0`,

`a | -1` == `-1`,

`a - a` == `0`,

`0 / a` == `0`,

`a ^ a` == `0`

### Safe elimination of parts

`a + 0` == `a`,

`a - 0` == `a`,

`a * 1` == `a`,

`a / 1` == `a`,

`a & -1` == `a`,

`a | 0` == `a`,

`a ^ 0` == `a`,

`a << 0` == `a`,

`a >> 0` == `a`

### Determine individual bits in expression
KEY:
```
0 == false (off)
1 == true (on)
? == undefined
{a, b, c} == 8-bit integral types
```

`a & 0b00001111` == `0b????1111`

`a << 4` == `0b????0000`

## Expression pipelining
This requires some basic knowledge of assembly semantics, but it isn't too terribly difficult.
Essentially, this section takes advantage of CPU pipelining (out-of-order execution), increasing parallelism in deceptively effective ways.
There's one catch: You can only perform out-of-order execution if the data does not *depend* on a previous expression.
In other words, if I modify X in instruction 1 and try to execute instruction 2 that needs the value stored in X, I will create a *dependency*, and they cannot be executed out-of-order.
To make an *immense* generalization, the less data dependencies you have in your generated assembly, the better.

(Just an interesting thing that I noticed) GCC and Clang both have this optimization for their C compilers, but for some odd reason I am unable to generate pipelined code for anything beyond 4 operands.
This is only when compiling for a generic microarchitecture (default).
This may be a very important fact to look into, in case the designers of GCC and Clang are aware of something I have yet to discover.

`r0 + r1 + r2 + r3`

Unoptimized:
```nasm
; Executes first instruction
add r0, r1

; Executes second instruction
add r0, r2

; Executes final instruction
add r0, r3
```

Optimized:
```nasm
; Executes the next two instructions in parallel
add r0, r1
add r2, r3

; Wait for those instructions to finish, then execute this final instruction
add r0, r2
```

Now, this obviously goes for all other kinds of arithmetic, but I need to finish this markdown file this year, so I'll leave it to the imagination. (Sarcasm aside -- I will finish this is people feel it is needed)
