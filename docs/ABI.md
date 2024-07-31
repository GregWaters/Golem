# Overview
Maintaining ABI stability with C is a very valuable thing, but Golem has a too many things that are fundamentally different to maintain this compatability for anything other than trivial examples. Here, we're defining calling conventions for everything.

## Calling conventions
Explicitly defined conventions that are designed around an architecture's limitations. The compiler may change the below conventions as long as the program's observable behavior is not changed.

## IA-32
#### TBA

## x86_64


| Register | Purpose |
| -------- | ------- |
| **RAX**  | return value & arg0 |
| **RDI**  | arg1    |
| **RSI**  | arg2    |
| **RDX**  | arg3    |
| **RCX**  | arg4    |
| **RBX**  | arg5    |

The rest of the arguments are pushed to the stack from right to left.