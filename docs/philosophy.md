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
Very important in the implementation of the above; the measurement of how easy it is to maintain as the project grows.
In essence, that means "How can I explain this code to myself in 6 months time?" and "If my project takes 20 minutes to build, how much time will be spent compiling for small changes?"

We *must* keep scalability in mind with these kinds of projects, as things like Firefox could take you anywhere from an hour to an entire day to compile alone!
This is the reason that Java is widely used in corporate scenarios, you don't have to deal with the potentially massive wasted time compiling your code, and can simply test it at will.
(Additionally, you can change your code *as it is running*, which was revolutionary at the time.)

However, this scalability often sacrifices performant code, which is why, despite these clear advantages, Firefox is primarily written in C++.
People understand that, despite the loss in development velocity, the performance is extremely valuable. That leads us to the next section.

# Performance
This language is built to approach hand-written assembly in speed. We employ a more strict 'zero-overhead principle' than C++, as exceptions are not built into the language.
This further emphasizes the *you don't pay for what you don't use* philosophy by allowing maximal control over your program's operation.

Additionally, processor-specific optimization and automatic vectorization is already in use in some places, such as compilation targeting a widely-used gaming console.
Because the specs of the device are known and you can safely assume that they won't change, you can target these devices and make the resulting software tuned exactly to the console's abilities.

However, we have yet to see optimization targeting a specific operating system. This is strange, as it is even safer to assume that the user will not try to run the software on a different OS than a different CPU architecture,
as executable formats are variable between operating systems regardless.
With the Linux kernel supporting the fastcall convention for syscalls, we could improve performance on systems that utilize these conventions.
Programs which rely on many kernel-based operations (IO-bound programs like GNU's `cat` utility come to mind) could benefit from this greatly.
