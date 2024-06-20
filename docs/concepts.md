# Overview
This page is a collection of some concepts that readers should be familiar with, defined within the realm of the Golem programming language. A lot of concepts are borrowed from C, others not so much.

# Tokens
Due to the inefficiency of parsing raw characters, it is preferred that a collection of integer values with explicit meaning is used.

For example, a simple calculator could use a series of words 'Number, Plus, and Minus' mapped to integers '0, 1, 2' to represent what is on screen in a compact format.
Tokenization allows the calculator to convert the expression `412408 + 581842 - 99999`, with a size of 23 bytes to `Number, Plus, Number, Minus, Number`, with a size of 5 bytes.

Golem's token system is much more complex than this simple example, but can still store a token in a single byte!
For a list of Golem's recognized tokens, see the [documentation](https://github.com/GregWaters/Golem/blob/master/docs/tokens.md).

# Literals
Literals are values explicitly written by the programmer. In each of the following examples, we assign a *literal* value to a variable.
```cpp
int<32>   a { 42 }
[char]    b { "Hello, world!" }
float<32> c { 3.14 }
```

# Expressions
Expressions are parsed in very specific ways to preserve intuitive design patterns.
Examples of expressions include
  - Literal values, such as `42`, `'!'`, and `"Hi mom"`. Variables that can be determined at compile-time are also within this constraint.
  - Explicitly declared identifiers, like `main` or `n`. These are *not* evaluated at compile-time.

**All** expressions are evaluated in pairs. `1 + 2 * 3` is evaluated with the order of operations in mind, converting the expression to a tree-expression like so (ignore the programmer art skills):

![AST](https://github.com/GregWaters/Golem/assets/145311515/4e60a7db-c2c6-41db-aa17-9f820c223eb5)

This design allows for incremental evaluation of expressions, with *zero* dynamic memory allocation overhead.

Additional rules for expression evaluation:
- TBA

## Equality
Golem defines ***equality*** in the most primitive sense. The bit representation of both expressions are XOR'd together and, if the result is zero, they are considered to be equal.
This does, however, pose a few issues with floating point numbers with their integral counterparts. For example,
```cpp
func main -> int<32>
{
    float<32> float_num { 5 }
    uint<32> uint_num { 5 }

    if ( float_num = uint_num )
    {
        return 0
    }

    else
    {
        ; Error!
        return -1
    }
}
```

The above comparison will always evaluate to false under these rules, as the types simply do not store data in the same mechanism.
To adjust for this, when floating point numbers are in a comparison, the other type should be cast to the floating-point type.
Of course, the size rules apply afterwards - If both types are floating-point types, the smaller type is cast to the larger type.

For example, the above expression should evaluate to true, because a floating-point 5 can be semantically evaluated using a cast.

## Casting
Casting is the act of converting one type to another. There are two kinds of casts: explicit and implicit. Explicit casts are used by the programmer to say "I want to cast type x to type y".
Implicit casts happen in expressions like `4.3 + 5`, where an integer is added to a floating-point number. The integer is cast to a float 

Casting semantics are complex. If a one type is larger than another type, it is converted to that type before evaluation. However, there are exceptions to this rule.
Most notably, floating-point types must be compared to other floating point types. In an expression with a smaller-sized float (eg: 32 bits) and a larger-sized integer (eg: 64 bits),
the integer will be cast to the 32-bit floating-point type.

Casting syntax is relatively simple to both read and parse. Similar to the function call syntax, parentheses immediately following a type name will convert an expression to that type as in the following code.
```cpp
func int_to_float -> float<32>
int<32> num
{
    return float<32>(num)
}
```
This function is notably overcomplicated, as you could simply return `num` and it would be an *implicit* cast, but it demonstrates the syntax well.

# Type-punning
Type-punning is the act of reinterpreting the bits of a type to mean something else. For example, if you wanted to represent a floating point number in raw bits, you could reinterpret it as an unsigned integer and read the bits that way.
Type-punning is commonly achieved through the use of pointers as in `[ [char](int<32>) ]`. See the documentation on pointers [here](https://github.com/GregWaters/Golem/edit/master/docs/pointers.md).
