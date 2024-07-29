#pragma once

enum token
{
    // Signal tokens
    EOS, // End of token stream

    // Braces
    LEFT_BRACE,  // {
    RIGHT_BRACE, // }
    LEFT_BRACK,  // [
    RIGHT_BRACK, // ]
    LEFT_PAREN,  // (
    RIGHT_PAREN, // )

    // Arithmetic
    PLUS,     // +
    MINUS,    // -
    ASTERISK, // *
    FWDSLASH, // /
    MODULUS,  // %

    // Bitwise
    NOT,    // ~
    AND,    // &
    OR,     // |
    XOR,    // ^
    LSHIFT, // <<
    RSHIFT, // >>

    // Boolean
    EQUALS,     // =
    GREATER,    // >
    GREATER_EQ, // >=
    LESS,       // <
    LESS_EQ,    // <=
    
    // Syntax
    HASHTAG, // #
    AT,      // @
    IDENT,   // User-defined
    COMMA,   // ,
    DOT,     // .

    // Literals
    INTEGER_LIT, // 42
    FLOAT_LIT,   // 3.14
    STRING_LIT,  // "Hello, world!"
    CHAR_LIT,    // '!'

    // Keywords
    K_INT,      // Integer variable declaration
    K_FLOAT,    // Floating-point variable declaration
    K_CLASS,    // Class declaration
    K_FUNC,     // Function declaration
    K_NULL,     // Representation of 'nothing'
};

