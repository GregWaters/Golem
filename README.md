# Golem is a new kind of C++ library.

Golem is a set of highly specialized functions, algorithms, and containers. The one repeated notion in this project is that there is no point in sacrificing speed for abstraction that is needed to create a highly optimized, yet *readable* project.
This collection of headers will aid in solving problems before they appear. Each module (or header) has its own highly specialized use-case, where it should not just be used for convenience, but whenever it is possible to do so.
Here is an overview of the abstract use-cases of individual modules, and the problems that they solve. Oh, and everything that *can* be `constexpr`, ***is*** `constexpr`.  

There is a very small chance that this project evolves into its own separate language if it is decided that it would be worth the immense effort.

# The `string` Module

This adds a new class, an alternative to the ubiquitous `std::string` in standard C++. The string class allows for a universal representation of a series of human-readable characters without the overhead of successive `strlen()` calls,
as the length/size is always known. Currently, work is being done on the input and output modules to allow them to implicitly convert every primitive into a `string` for extremely (needlessly, even) fast console output.
***The string class is not a C string wrapper!*** Eventually, it will also be possible to efficiently convert the `string` class into a C string, allowing backwards compatiblity with C without the overhead of the null character be copied constantly.

# The `output` Module

This has a collection of overloads for one templated/generic function: `print()`. The print function does exactly what you think it does, it prints output to stdout. It is *not* a wrapper around `std::cout` or even `printf()`.
Both of these are problematic for their own respective reasons (printf requires you to pass a pointer and is by nature a **formatting** function, not a *print* function. Cout is different, but not good either. Cout relies on many nested function calls that can
be a lot of overhead depending on how many things you're printing.) The biggest difference between this function and the widely used alternatives is the internal conversion. By concatenating all the string classes together, 
we can minimize unneeded calls to the kernel and allow for expansion for developers wanting a function to print their own specialized custom containers.  

TLDR: Print is a function that internally converts things to strings, appends them to each other, and makes one call to print them to stdout.

# The `console` Module

This module is for all things console-related, so it implies the input/output modules as dependencies. 

# The `benchmark` Module

A fairly simple module, currently consisting of only one class; the `timer`. This allows for simple benchmarks that are accurate down to the microsecond. While the class is primarily used for benchmarking and debugging, it can very easily
be used in production code as a high-resolution clock (from the standard library `chrono`) without the boilerplate.

(Most of this is TODO)

# The `input` Module

It's quiet... too quiet...

# The `math` Module

Imagine a world where every C math function was a constant expression. Beautiful, I know, but we're still working on it.

# The `fast_math` module

Imagine a world where every C math function was a constant expression... but faster and less precise.

# The `precise_math` module

Imagine... okay we've done this bit like 4 times now. Everything is passed as a 128-bit float and is mainly for precise mathematical or scientific computation.

# The `memory` module

Mainly for internal use. This will contain the contiguous allocator: a deadly weapon for making efficient containers.

# The `utility` module

Mainly for internal use. This holds the base dynamic container that will serve as a basis for all other dynamic containers.

# The `system` module

The operating system macros and endian functions have been moved to this module, for general system-dependent things. It provides preprocessor macros (see `OS_WINDOWS`, `OS_LINUX`, and `OS_MAC`) to determine the user's operating system and change the code accordingly.
