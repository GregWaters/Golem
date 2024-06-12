#pragma once

enum token
{
    // Braces
    LEFT_BRACE,  // {
    RIGHT_BRACE, // }
    LEFT_PAREN,  // (
    RIGHT_PAREN, // )
    LEFT_BRACK,  // [
    RIGHT_BRACK, // ]
    
    // Arithmetic
    PLUS,     // +
    MINUS,    // -
    ASTERISK, // *
    FWDSLASH, // /

    // Bitwise
    NOT,    // ~
    AND,    // &
    OR,     // |
    XOR,    // ^
    LSHIFT, // <<
    RSHIFT, // >>

    // Boolean
    EQUALS,     // =
    BOOL_AND,   // &&
    BOOL_OR,    // ||
    BOOL_NOT,   // !
    GREATER,    // >
    GREATER_EQ, // >=
    LESS,       // <
    LESS_EQ,    // <=
    NOT_EQ,     // !=
    
    // Syntax
    HASHTAG, // #
    AT,      // @
    IDENT,   // User-defined name
    COMMA,   // ,

    // Keywords
    INT,      // Integer variable declaration
    FLOAT,    // Floating-point variable declaration
    CLASS,    // Class declaration
    FUNC,     // Function declaration
}

bool is_keyword(enum token tok)
{
    return (tok >= INT && tok <= FUNC);
}

