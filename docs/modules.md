# Overview
One of the killer features of the Golem language is the standardization of a 'module' system.
Modules are similar to libraries, but more extensible for both sides of the development process.

# Advantages over C-style includes

- Effective removal of identifier collisions within modules

  if a collision occurs (a function is defined that has the same name as another), the `as` keyword allows you to effectively change the name of every function included.
For example, say you are writing a program that contains two math libraries, but they both define `sqrt()`. You can easily solve this collision using `as` as such.

```python
include <math.mod> as math
include <geometry.mod> as geo

func main() -> int
{
    int<32> n { 16 }
    if (math.sqrt(n) == geo.sqrt(n))
        return 0
    else
        return 1
}
```



# Internals
(To be decided)
