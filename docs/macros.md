# Overview
Macros are functions that are completely inlined.
Macros are unique in their ability to optimize each call for the task at hand,

That means the following actions are allowed:
- Using `sizeof()` on arguments
- Using `typeof()` on arguments
- Using function result in a constant expression (macro must be preceded by `@pure`)

Additionally, macros cannot have external linkage by definition.

Examples of macros:
```cpp
macro is_digit(char c) -> bool
{
    return (c >= '0' && c <= '9')
}
```

```cpp
macro to_lowercase(char c) -> char
{
    if (c >= 'A' && c <= 'Z')
        return c + 32
    else
        return c
}
```
