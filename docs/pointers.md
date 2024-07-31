# Overview
Pointers are a big part of any language, and often times those who don't know what pointers are [use them the most](https://en.wikipedia.org/wiki/Python_(programming_language)).
Pointers aren't black magic, however, they're just a way of storing a location in a variable so you can read/write at a specified location.
We need pointers in C because we have no other way to represent strings or arrays, so we must embrace this amazing tool to write better code.

For those of you who haven't used pointers, they are typically stored using the same size as the system's long bit. That means 8 bytes for 64-bit systems, 4 bytes for 32-bit systems, etc.

# Small Issues
A lot of C programmers are perfectly content with the syntax of C-style pointers, but when you need to actually declare something as such,
```cpp
// A pointer to the function "square" that squares an integer before returning it
int (*funptr)(int) = square;

```
It is quite a hostile sight to many programmers, to the point of complete avoidance of this great feature!
Function pointers enable great design patterns, but it's hard to get behind that fact with the subpar syntax.

And, of course, there's always the 10000 year war over where you should put that asterisk in the mess of it all.
```cpp
// C-style (aligned to the right)
int *make_array(int n);

// C++ style (aligned to the left)
int* make_array(int n);

// "I just want to grill" style (aligned to the center)
int * make_array(int n);
```
(C-style alignment is just better in some areas)
```cpp
// Declare two integers a and b
int x, y;

// Declares an integer pointer and a regular integer.
int* x, y;

// How to actually declare two pointers
int *x, *y;
```

# Golem's Pointers
Within the Golem language, you are given nasm-style brackets and an optional byte offset to dereference pointers.
For visualization, that looks like this.

```cpp
func get_first_char([char] str) -> char
{
    return [str]
}

func byte_at -> char
; type does not matter here, we can use a data pointer with the same size as a byte
[data] arr
int<64> offset
{
    return [ arr + offset ]
}
```

In C, this is a bit less optimal, but still entirely passable
```C
unsigned char byte_at(void *arr, int64_t offset)
{
    return *(char *) arr + offset; 
}
```

This syntax encourages dynamic thinking with pointers.
Not only can you add an offset, but you can *subtract* an offset as well.
You cannot multiply pointers, nor can you divide them. It is nigh impossible to get any use out of pointer multiplication, division, or most mathematical operations outside of adding/subtracting an offset.

With all this in mind, lets revisit that first example in Golem.

```nasm
; Declare a function that holds the address of a function named 'square' which has its return value interpreted as an integer
func funptr { square -> int }
```
It is entirely subjective whether or not you prefer the previous syntax, but I believe that it's preferable if only due to the fact that `func` is a dedicated keyword for function declarations.
That's pretty much it in regards to pointers in Golem!
