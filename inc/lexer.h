#pragma once

enum token_desc
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
    LITERAL, // Literals

    // Keywords
    K_INT,      // Integer variable declaration
    K_FLOAT,    // Floating-point variable declaration
    K_CLASS,    // Class declaration
    K_FUNC,     // Function declaration
    K_MACRO,    // Macro declaration
    K_TYPE,     // Type definition
    K_NULL,     // Representation of 'nothing'
};

struct
{
    // Token description
    const char *literal_start;
    const char *literal_end;

    // Location
    size_t line;
    size_t column;

    // Actual token type
    enum token_desc type;
} token;
