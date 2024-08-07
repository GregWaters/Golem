# Overview
One of the killer features of the Golem language is the standardization of a 'module' system.
Modules are similar to libraries, but more extensible for both sides of the development process.

# Advantages over C-style includes

- Effective removal of identifier collisions within modules
if a collision occurs (a function is defined that has the same name as another), the `as` keyword allows you to effectively change the name of every function included.
For example, say you are writing a program that contains two math libraries, but they both define `sqrt()`. You can easily solve this collision using `as` as such.

- Compilation speed
Parsing function signatures is a lot faster for a compiler than including an entire file into source code.
Compilation speed may increase as a result of this.

- Less RAM usage
Because we can store an entire C header as a set of function signatures, it is much easier to reduce RAM usage by simply not including the file within our own.

```python
include <math.mod> as math
include <geometry.mod> as geo

func main -> int<32>
{
    int<32> n { 16 }
    if (math.sqrt n == geo.sqrt n)
        return 0
    else
        return 1
}
```



# Internals
All of Golem's modules will be treated as namespaces, as stated beforehand. The internals change things up a bit in semantics. When a compiler finds an identifier, it will first look for it in the current translation unit.
If it is not found, it results in an error, but if the identifier is followed by the `.` operator, the identifier will be considered a namespace invokation.
When namespaces are invoked, the compiler will then look at the set of currently imported modules to try and find which namespace matches the name of the imported module.
When this name is found, it opens the file to search for a valid declaration. If it is found, yay! If not, throw an error.

This simple system will greatly improve compilation times when refined. Using smart data structures, the complexity will also lessen.

# Syntax
To declare a file to be a module, the file's name should end with `.mod` to avoid confusion. When including any file with the `module` keyword (and optionally `as`), it is treated and interpreted as a module.
