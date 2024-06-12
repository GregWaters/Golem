# Overview
There is an art to knowing exactly when to inline functions. In some cases, it can make code larger, smaller, faster, and slower. The only variable is knowing *when* to correctly use it.
Smaller executables tend to stay within the code cache much easier, which will result in a program that is simply faster than otherwise.
Understanding these low-level details will help you create a program that doesn't just *work*, but works excellently.

# Inline a function when...
- The function is called many times
- The function is only a few lines long, and the function call itself is most of the overhead
- You want the function's code to stay in the cache

Examples of functions that would be good to inline:
```cpp
@inline
is_digit(char c) -> bool
{
    return (c >= '0' && c <= '9')
}
```

```cpp
@inline 
to_lowercase(char c) -> char
{
    if (c >= 'A' && c <= 'Z')
        return c + 32
    else
        return c
}
```

# Avoid inlining a function when...
- The function takes up several lines of complex logic
- It may break binary compatibility
- The function's main overhead is IO operations (as an aside, you should avoid using IO outside of the `main()` function)

Examples of functions that should definitely *not* be inlined
```cpp
complex_hash(str hash_string) -> int<64>
{
    int<64> hashval{ 0 }
    # (500-step hash process)
    return hashval
}
```

```cpp
linux_print_hex(int<64> num) -> null
{
    @view
    str hexmap = "0123456789ABCDEF"

    # Missing values (all values) are zero-initialized
    byte arr<32> buffer { }
    uint<32> iterator { 32 }

    do
    {
        iterator { iterator - 1 }
        buffer[i] { hexmap[num & 0b1111] }
        num { num >> 4 }
    }
    while (num != 0)

    # write output to stdout file-descriptor
    linux.write(1, buffer + iterator, 32 - iterator)
}
```

# Conclusion
Most of the time, the compiler will know when to inline a given function. However, understanding when and why you should, you may be able to tune the generated machine code to do whatever you need it to do.
Alternatively, you may just want to experiment with the performance of inlining a function rather than calling it, and want to make sure it's inlined to test it.

Good luck using this tool effectively!
