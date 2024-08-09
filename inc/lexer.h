#pragma once

#include <ctype.h>
#include <stdio.h>

#include "file.h"

enum token_desc
{
    // Signal tokens
    TK_END, // End of token stream

    // Punctuation
    TK_LBRACE, // {
    TK_RBRACE, // }
    TK_LBRACK, // [
    TK_RBRACK, // ]
    TK_LPAREN, // (
    TK_RPAREN, // )
    TK_PLUS,     // +
    TK_MINUS,    // -
    TK_ARROW,    // ->
    TK_ASTERISK, // *
    TK_SLASH,    // /
    TK_MODULO,   // %
    TK_NOT,    // ~
    TK_AND,    // &
    TK_OR,     // |
    TK_XOR,    // ^
    TK_LSHIFT, // <<
    TK_RSHIFT, // >>
    TK_EQUALS,     // =
    TK_GREATER,    // >
    TK_GREATER_EQ, // >=
    TK_LESS,       // <
    TK_LESS_EQ,    // <=
    TK_HASHTAG, // #
    TK_AT,      // @
    TK_COMMA,   // ,
    TK_DOT,     // .
    TK_GRAVE,   // `

    // Literals
    TK_STRING,  // "
    TK_CHAR,    // '
    TK_NUMBER,  // 0123456789

    // Keywords
    KW_IF,
    KW_INT,     // Integer variable declaration
    KW_FLOAT,   // Floating-point variable declaration
    KW_CLASS,   // Class declaration
    KW_FUNC,    // Function declaration
    KW_MACRO,   // Macro declaration
    KW_TYPE,    // Type definition
    KW_NULL,    // Representation of 'nothing'

    // Identifiers
    TK_IDENT,    // User-defined
};

struct Token
{
    char *literal, *end;
    enum token_desc type;
};

struct Token tk_next(struct File *file);
struct Token tk_prev(struct File *file);
