# Overview
Attributes allow you to verify assumptions or create assumptions about your code.
In order to allow the compiler to use code that it cannot see, you can use an attribute.
Additional attributes may be defined by an implementation.

# Attribute Definitions
Format: `@name` (use when declaring...) - definition

`@pure` (functions) - Given the same parameters, this function will *always* return the same value. In other words, the function has no state.
The compiler will assert that the function does not read or write to any memory outside of its scope or call any impure functions, with the exception of reading `@view` values.

And will throw an error if they do not meet these requirements.

If a function **does** meet these requirements, the compiler is allowed to do a few valuable things:
- Assume that subsequent calls to the function with the same parameters are equal
- Replace a value in the generated machine code with the result of the evaluation
- Evaluate the function at compile-time

```cpp
@pure
func low_byte(int<32> n) -> int<32>
{
    ; Zero all bytes except lowest
    return n & 0x000000FF
}

func main() -> int<32>
{
    ; Unavoidable impure function call
    int<32> num = getnum("Input number: ")

    ; Pure function calls
    int<32> number1 { low_byte(num) }
    int<32> number2 { low_byte(num) }

    return number1 + number2
}
```
As you may have guessed, `main` can automatically be optimized to
```cpp
@pure
func low_byte(int<32> n) -> int<32>
{
    ; Zero all bytes except lowest
    return n & 0x000000FF
}

func main() -> int<32>
{
    return low_byte(getnum("Input number: ")) * 2
}
```
and only one call to the indeterminate function is made.

`@const` (variables) - Treat the variable as a constant value. The variable must be initialized with a value, and if that value can be evaluated at compile-time, the variable may be optimized away entirely.
If an attempt is made to assign to a `@const` variable, a compile-time error is thrown.

`@constexpr` (variables) - Force the variable to be a constant expression. If the variable's value cannot be discerned at compile-time, the compiler should throw an error.

`@explicit` (variables, types) - Do not allow this type to be implicitly casted to or from. If a cast is desired, it must be done explicitly.
Can also be specified for a singular variable declaration rather than a type.

`@atomic` (functions, variables, types) - Atomic operations are operations are absolutely indivisible. For functions, this means that the function **must** be called sequentially, as opposed to in parallel.
For variables, this also means accesses are also to be done sequentially, and cannot be done in parallel.
For types, this means that all variable declared with the type have the `@atomic` attribute applied to them automatically.

`@deprecated` (functions) - Raise a warning if the function is called (warning should include `@deprecated` attribute as reasoning). Typically used alongside `@cold` in library source code.

`@hot` (functions) - Tell the compiler that this function is called often. Effect on code generation is entirely implementation-defined.

`@cold` (functions) - Tell the compiler that this function is **not** called often. Effect on code generation is entirely implementation-defined.

`@local` (functions) - Keep this function within the bounds of this source file (translation unit).

`@cdecl` (functions) - Use the C calling convention (used for interfacing with C libraries).

`@fastcall` (functions) - Use the fastcall calling convention (used for interfacing with certain APIs).

