# Overview
This is a glossary of all tokens in the Golem language and their formal definitions -- it may change if new keywords (or even operators) are added.
All operations are shown in C-adjacent pseudo-code.

# Braces
`{` - Left brace:
- Begins a scope and is used for assignment.

`}` - Right brace:
- End of scope
- End of assignment statement

`[` - Left bracket:
- Dereferences pointers with an optional offset value when used immediately to the right of a pointer expression. Any integer literal within this symbol and `]` is implicitly multiplied by the size, in bytes, of the type being pointed to.

`]` - Right bracket:
- End of a pointer dereference

`(` - Left parenthesis:
- Beginning of expression separator.
- When used immediately to the right of a function's identifier, it calls that function with the parameters listed within the parentheses separated by `,`.

`)` - Right parenthesis:
- End of expression separator
- End of function call parameters

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
- Shift all bits in the left operand to the left by the number specified in the right-hand operand
  
`>>` - Shift right:
- Shift all bits in the left operand to the right by the number specified in the right-hand operand

# Comparison
*All comparison operations return a value of type `bool`. `bool` is equivalent to `uint<1>`, but may give a warning if a cast/zero-extension is attempted. Apart from this, the rules of standard arithmetic still hold true.*
*For the sake of consistency, true is always equal to 1, and false is always equal to 0.*

`=` - Equals:
- Returns a true value if two expressions surrounding it have equal values.

`<` - Less than:
- Returns true if the left operand is less than the right operand, otherwise returning false.
- Beginning of a separator for integer bit-specifiers

`<=` - Less than or equal to:
- Returns true if the left operand is less than or equal to the right operand, otherwise returning false.

`>` - Greater than:
- Returns true if the left operand is greater than the right operand, otherwise returning false.
- Beginning of a separator for integer bit-specifiers

`>=` - Greater than or equal to:
- Returns true if the left operand is greater than or equal to the right operand, otherwise returning false.


# TBA: Keywords, Literals, Syntactical tokens

