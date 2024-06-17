# Overview
Pointers are a big part of any langauge, and often times those who don't know what pointers are [use them the most](https://en.wikipedia.org/wiki/Python_(programming_language)).
Pointers aren't black magic, however, they're just a way of storing a location in a variable so you can read/write at a specified location.
We need pointers in C because we have no other way to represent strings or arrays, so we must embrace this amazing tool to write better code.

For those of you who haven't used pointers, they are typically stored using the same size as the system's long bit. That means 8 bytes for 64-bit systems, 4 bytes for 32-bit systems, etc.

# Small Issues
A lot of C programmers are perfectly content with the syntax of C-style pointers, but when you need to actually declare something as such,
```cpp
// A pointer to the function "square" that squares an integer before returning it
int (*funptr)(int) = &square;

```
It is quite a hostile sight to many programmers, to the point of complete avoidance of this great feature!
Function pointers enable great design patterns, but it's hard to get behind that fact with the subpar syntax.

And, of course, there's always the 10000 year war over where you should put that asterisk in the mess of it all. I use C++ style, personally,
but I believe that C-style is objectively correct given the potentially complex pointer syntax.

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
In Golem, you are given brackets and an optional offset value that is multiplied by the size (in bytes) of the operand.
For visualization, that looks like this.

```cpp
func get_first_char -> char
[char] str
{
    return [str]
}

func get_offset_char -> char
[char] str
int<64> offset
{
    return [str + offset]
}
```
This syntax encourages dynamic thinking with pointers. Not only can you add an offset, but you can *subtract* an offset as well. Subtraction with pointers in play may seem dangerous, but it comes in handy with certain algorithms.
You cannot multiply pointers, nor can you divide them. It is nigh impossible to get any use out of pointer multiplication, division, or most mathematical operations outside of adding/subtracting an offset.

With all this in mind, lets revisit that first example in Golem.

```cpp
# A pointer to the function "square" that squares an integer before returning it
[func] funptr { square -> int }
```
It is entirely subjective whether or not you prefer the previous syntax, but I believe that it's preferable if only due to the fact that `func` is a dedicated keyword for function declarations.
That's pretty much it in regards to pointers in Golem!
