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

# TBA
Merge this with the other ideas central to the language. 
