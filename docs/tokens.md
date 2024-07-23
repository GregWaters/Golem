# Overview
This is a glossary of all tokens in the Golem language and their formal definitions -- it may change if new keywords (or even operators) are added.

# Braces
`{` - Left brace:
- Beginning of scope.
- Marks beginning of assignment value.

`}` - Right brace:
- End of scope.
- End of assignment value.

`[` - Left bracket:
- Dereferences pointers with an optional offset value when used immediately to the right of a pointer expression.

`]` - Right bracket:
- End of a pointer dereference.

`(` - Left parenthesis:
- Beginning of expression separator.
- When used immediately to the right of a function's identifier, it calls that function with the parameters listed within the parentheses separated by `,`.

`)` - Right parenthesis:
- End of expression separator.
- End of function call parameters.

# Arithmetic
`+` - Add:
- Produces sum of an augend and an addend and replaces the augend with the sum.
The type of the augend determines the type of the difference.

`-` - Subtract:
- Produces difference of a subtrahend and minuend and replaces the subtrahend with the difference.
The type of the subtrahend determines the type of the difference.

- If used in unary form, the operation produces a two's complement negation on the operand and returns it.

`*` - Multiply:
- Produces product of a multiplier and a multiplicand and replaces the multiplier with the product.
The type of the multiplier determines the type of the product.

`/` - Divide:
- Produces quotient of a dividend and a divisor and replaces the dividend with the quotient.
The type of the dividend determines the type of the quotient.

`%` - Modulus:
- Produces remainder of division between left and right operands, respectively.
Both operands must be of integral types.

# Bitwise
`~` - Not:
- Produces the operand with all bits inverted.

`&` - And:
- Performs an AND gate operation on every bit of the left and right operands.

`|` - Or:
- Performs an OR gate operation on every bit of the left and right operands.

`^` - Xor:
- Performs an XOR gate operation on every bit of the left and right operands.

`<<` - Shift left:
- Shift all bits in the left operand to the left by the number specified in the right-hand operand.
  
`>>` - Shift right:
- Shift all bits in the left operand to the right by the number specified in the right-hand operand.

# Comparison
*All comparison operations return a value of type `bool`. `bool` is equivalent to `uint<1>`, but may give a warning if a cast/zero-extension is attempted. Apart from this, the rules of standard arithmetic still hold true.*

*For the sake of consistency, true is always equal to 1, and false is always equal to 0.*

`=` - Equals:
- Returns a true value if two expressions surrounding it have equal values.

`<` - Less than:
- Returns true if the left operand is less than the right operand, otherwise returning false.
- Beginning of a separator for integer bit-specifiers.

`<=` - Less than or equal to:
- Returns true if the left operand is less than or equal to the right operand, otherwise returning false.

`>` - Greater than:
- Returns true if the left operand is greater than the right operand, otherwise returning false.
- Beginning of a separator for integer bit-specifiers.

`>=` - Greater than or equal to:
- Returns true if the left operand is greater than or equal to the right operand, otherwise returning false.

# Literals
`42` - Integer literal:
- Used as a raw expression that has no address. The limit for the size of an integer literal is at least 512 bits, but can be larger depending on the implementation.

`3.14` - Floating-point literal:
- Used as a raw expression that has no address. A standard floating-point literal is 64-bits in length. Due to the nature of IEEE 754 floating point numbers, the bit length cannot be implied.

`"Hello!"` - String literal:
- Used as a raw expression with an address. Stored as a pointer (64-bits in length) to a series of bytes in read-only memory. Cannot be modified through any normal means. Implicitly terminated by a NUL character.

`'!'` - Character literal:
- Used as a raw expression that has no address. Stored in a single byte by definition. 

# Keywords
`int`:
- Used to declare an integer variable. May be used with angled brackets to specify the number of bits the variable has the potential to hold.

`uint`:
- Used to declare an unsigned integer variable. May be used with angled brackets to specify the number of bits the variable has the potential to hold.

`float`:
- Used to declare a floating-point variable. May be used with angled brackets to specify the precision, but this precision specifier must be a power of two.

`func`:
- Used to declare a function.

`null`
- Can be specified in the place of a type in function return values to tell the compiler that the function does not return a value.

`extern`
- Used directly before the `func` keyword to tell the compiler that there is no code block beneath the parameter list (this must be done due to the lack of semicolons for explicit statement-termination), and that the linker will find the function and link it to the definition.
  
# Other
`,` - Comma:
- Used as a separator in various places.

`;` - Semicolon:
- Tell the compiler to ignore all characters from this point until a newline is reached. If the newline is preceded by a backslash character (`\`), the newline will not terminate the statement.

`@` - Attribute:
- Used to turn an attribute specified immediately after the `@` symbol.

`->` - Arrowhead:
- Used immediately after a function declaration to specify the return value.
