# Check your baggage at the door
There are many important issues with today's compiled languages. Go, Rust, C++, and even C come with their own 'ideology'.
Now, this idea of a central set of ideas that brings your developers together is flawed, but is it wrong?

Using Rust as an example, there is a very strict orientation towards *safety*, and it involves a completely different approach to programming.
I would personally say that a kind of 'ideology' is justified, as you must adjust to the language in any case.
Go is a bit more extreme, having their own unified formatting tool in `gofmt`.

However, our language does not hold any groundbreaking ideas, but rather small nudges that should keep you writing code that is easy to understand and document.
I don't feel that having a set of people who are expected to think the same way about any set of things is productive.
Writing good code involves a wise mind and creativity, not repetition and regurgitation.

# Scalability
A lot of these ideas are used for the sake of 'scalability'; the measurement of how easy it is to maintain as the project grows.
This is also a good thing to keep in mind, as things like Firefox could take you anywhere from an hour to an entire day to compile alone!
This is the reason that Java is widely used in corporate scenarios, you don't have to deal with the potentially massive wasted time compiling your code, and can simply test it at will.
(Additionally, you can change your code *as it is running*, which was revolutionary at the time.)

However, this scalability often sacrifices performant code, which is why (despite these clear advantages)
Firefox is primarily written in C++, which is typically used as a great compromise between the near-unmatched speed of C and the useful abstraction of a language like Java.

This exact scalability is highly cherished in large projects, and will not be overlooked in the language specification.
This entire language is built around solving problems we could not have forseen in 1970 at C's conception, and that means scalability is a high priority.
