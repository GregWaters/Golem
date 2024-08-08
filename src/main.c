#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "../inc/lexer.h"

static void token_dump(FILE *stream);

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        fputs("usage: golem <file>\n", stderr);
        exit(1);
    }

    FILE *stream = fopen(argv[1], "r");
        
    if (!stream)
    {
        fprintf(stderr, "fopen(): Could not open file '%s': %s", argv[1], strerror(errno));
        exit(1);
    }

    // Begin lexing file
    token_dump(stream);
}


static void token_dump(FILE *stream)
{
    struct Token tok;

    static const char map[TK_IDENT + 1][8] = 
    {
        [TK_END] = "<EOF>",
        [TK_LBRACE] = "{",
        [TK_RBRACE] = "}",
        [TK_LBRACK] = "[",
        [TK_RBRACK] = "]",
        [TK_LPAREN] = "(",
        [TK_RPAREN] = ")",
        [TK_PLUS] = "+",
        [TK_MINUS] = "-",
        [TK_ARROW] = "->",
        [TK_ASTERISK] = "*",
        [TK_SLASH] = "/",
        [TK_MODULO] = "%",
        [TK_NOT] = "~",
        [TK_AND] = "&",
        [TK_OR] = "|",
        [TK_XOR] = "^",
        [TK_LSHIFT] = "<<",
        [TK_RSHIFT] = ">>",
        [TK_EQUALS] = "=",
        [TK_GREATER] = ">",
        [TK_GREATER_EQ] = ">=",
        [TK_LESS] = "<",
        [TK_LESS_EQ] = "<=",
        [TK_HASHTAG] = "#",
        [TK_AT] = "@",
        [TK_COMMA] = ",",
        [TK_DOT] = ".",
        [TK_GRAVE] = "`",
        [TK_STRING] = "<STR>",
        [TK_CHAR] = "<CHAR>",
        [TK_NUMBER] = "<NUM>",
        [TK_IDENT] = "<IDENT>"
    };

    do
    {
        tok = tk_next(stream);
        printf("%s ", map[tok.type]);
    } while (tok.type != TK_END);
}
