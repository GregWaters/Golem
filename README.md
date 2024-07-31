# Golem is a strongly typed, modular programming language specification
It draws inspiration from the best parts of many different languages, and leverages these bits and pieces with *zero* overhead due to its compiled nature.

I am currently working on a compiler for this programming language, but it will likely take a few years if I want to do it alone.
This is mostly a proof of concept, of course, because I will have a tough time holding a torch to entire teams of people who work on compilers daily.

# Who is it for?
Golem is for programmers who want low-level control and high-level abstraction without compromise. If you write C/C++, it will most likely be incredibly simple to learn and understand.
It compiles directly to native machine code, so you don't have to deal with any bytecode or code compression like in higher level languages.

# Roadmap
- Create outline of language (can change dramatically, as we have not created an implementation)
  - Create the syntax (and shape it to be as intuitive as possible before we're too far in to change it)
  - Clearly state what should happen in a given scenario. Alternatively, state that a given scenario must *never* happen, as undefined behavior will be invoked.

- Create language implementation
  - Lexer
  - Parser
  - Semantic Analyzer
  - Generate LLVM IR

# Bugs
If you see any grammatical errors, inconsistencies, or things that just don't seem right within the documentation or code, feel free to create a pull request!
This project will only thrive if others feel it is worthy of their time.

## (No known bugs as of 7/31/24)

# More information
The `docs/` directory holds useful information on the specifics of this language. Read the specification [here](https://github.com/GregWaters/Golem/blob/master/docs/specification.md).
