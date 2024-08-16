#pragma once

struct Expression
{
    char *data;
    size_t len;
    enum
    {
        EXP_INT,
        EXP_FLOAT,
        EXP_CHAR,
        EXP_STRING
    } type;
};

struct Token
{
    struct Expression exp;
    enum
    {
        EXPRESSION,
        PLUS, MINUS, TIMES, SLASH,
        LESS, LESS_EQ, GREAT, GREAT_EQ
    } kind;        
};

struct Token tk_next(FILE *stream);
