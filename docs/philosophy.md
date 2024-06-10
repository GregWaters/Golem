# Source-based installation
Golem presents an extremely far-reaching goal in the ability for any end-user to compile a project from source with minimal hassle.

The advantages of open-source software is that you have access to this source code, meaning you can modify it freely.
However, the vast majority of users much prefer to install a precompiled binary package as opposed to building from source.
This means that the only way to make use of vectorized code on new processors is by compiling for every architecture and potentially confusing people trying to download the software.

However, what if we could make better use of our new processors and their respective extensions?
It's actually pretty simple.

1. Write software with an open source license (GPL, MIT, BSD, etc.)
2. Supply end-users with the source code along with a build script that invokes the native compiler
3. The user builds the software

That's all, really! The biggest caveats are that we require a user to have a native compiler, and that it is simply unfamiliar to most users.
These steps are intentionally vague, as the 'script' in question could be anything from a Windows installer to a standard GNU makefile.
Either way, the result is the same - smaller, faster executables with the same, simple installation process.

This holds very large implications on extremely important pieces of software such as a kernel or a utility that is part of a large chain of commands, such as in a Bash script.
When speeding up things like text-processing utilities, your PC will be more responsive as a whole.

# Scalability
A lot of these ideas are used for the sake of 'scalability'; the measurement of how easy it is to maintain as the project grows.
This is also a good thing to keep in mind, as things like Firefox could take you anywhere from an hour to an entire day to compile alone!
This is the reason that Java is widely used in corporate scenarios, you don't have to deal with the potentially massive wasted time compiling your code, and can simply test it at will.
(Additionally, you can change your code *as it is running*, which was revolutionary at the time.)

However, this scalability often sacrifices performant code, which is why (despite these clear advantages)
Firefox is primarily written in C++, which is typically used as a great compromise between the near-unmatched speed of C and the useful abstraction of a language like Java.

This exact scalability is highly cherished in large projects, and will not be overlooked in the language specification.
This entire language is built around solving problems we could not have forseen in 1970 at C's conception, and that means scalability is a high priority.
