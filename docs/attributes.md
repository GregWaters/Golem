# Overview
Attributes are possibly the most important part of the language specification. Depending on the attribute, it can apply to a mixture of functions, variables, or types.
Ideally, we want the compiler to know exactly as much about our program as we do.

# Attribute Definitions
Format: `@name` (use when declaring...) - definition

`@pure` (functions) - Given the same parameters, this function will *always* return the same value. In other words, the function has no state.
The compiler will assert that the function does not read or write to any memory outside of its scope or call any impure functions, with the exception of reading `@view` values.

And will throw an error if they do not meet these requirements.

If a function **does** meet these requirements, the compiler can do a few valuable things:
- Assume that subsequent calls to the function with the same parameters are equal
- Replace a value in the generated machine code with the result of the evaluation

```python
@pure
func get_number() -> int<32>
{
    # (Code that is indeterminate at compile-time)
}

func main -> int<32>
{
    int<32> number1 { get_number() }
    int<32> number2 { get_number() }

    return number1 + number2
}
```

`@inline` (functions) Tell the compiler that the function call is to be eliminated entirely, and the function's code should replace it.
This allows for each call to be optimized to fit the current use case.

The inline attribute also allows for compile-time type information, as it is a guarantee, not a hint.
If a function cannot be inlined, a compile-time error will be thrown.


`@view` (variables) - Treat the variable as a constant value. The variable must be initialized with a value, and that value must known at compile-time.
If an attempt is made to assign to a `@view` variable, a compile-time error is thrown.

`@explicit` (types) - Do not allow this type to be implicitly casted to or from. If a cast is desired, it must be done explicitly.

`@atomic` (functions, types) - For functions, this means that it *must* not be run parallel to any other thread. For type, this means that a variable declared with the type must be accessed in a single instruction.

`@deprecated` (functions) - Raise a warning if the function is called (warning should include `@deprecated` attribute as reasoning).

`@hot` (functions) - Tell the compiler that this function is called often. Effect on code-generation is implementation-defined.

`@cold` (functions) - Tell the compiler that this function is ***not*** called often. Effect on code-generation is implementation-defined.
