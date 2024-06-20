# Overview
This page is a collection of some concepts that should be explicitly defined within the realm of the Golem programming language.


## Equality
Golem defines ***equality*** in the most primitive sense. The bit representation of both operands are XOR'd together and, if the result is zero, they are considered to be equal.
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
Casting is the act of converting one type to another. There are two kinds of casts: explicit and implicit. Explicit casts are used by the programmer to say "I want to 

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
