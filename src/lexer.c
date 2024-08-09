#include "../inc/lexer.h"

// All of this needs to be rewritten to adapt to file changes!

struct Token tk_next(struct File *file)
{
    // Skip whitespace and keep track of position
    const char *start = file->contents;
    struct Token token;

    while (1)
    {
        char cur = *file->contents;

        if (cur == ' ')
            ++file->column;
        else if (cur == '\t')
            ++file->column;
    }

    switch (c)
    {
        case EOF:
            return (struct Token) {ftell(stream), 0, TK_END};
        case '{':
            token.type = TK_LBRACE;
            break;
        case '}':
            token.type = TK_RBRACE;
            break;
        case '(':
            token.type = TK_LPAREN;
            break;
        case ')':
            token.type = TK_RPAREN;
            break;
        case '[':
            token.type = TK_LBRACK;
            break;
        case ']':
            token.type = TK_RBRACK;
            break;
        case '#':
            token.type = TK_HASHTAG;
            break;
        case '@':
            token.type = TK_AT;
            break;
        case ',':
            token.type = TK_COMMA;
            break;
        case '.':
            token.type = TK_DOT;
            break;
        case '+':
            token.type = TK_PLUS;
            break;
        case '-':
        {
            c = getc(stream);
            if (c == '>')
            {
                token.type = TK_ARROW;
                break;
            }

            ungetc(c, stream);
            token.type = TK_MINUS;
            break;
        }
        case '*':
            token.type = TK_ASTERISK;
            break;
        case '/':
            token.type = TK_SLASH;
            break;
        case '%':
            token.type = TK_MODULO;
            break;
        case '~':
            token.type = TK_NOT;
            break;
        case '&':
            token.type = TK_AND;
            break;
        case '|':
            token.type = TK_OR;
            break;
        case '^':
            token.type = TK_XOR;
            break;
        case '=':
            token.type = TK_EQUALS;
            break;
        case '<':
        {
            c = getc(stream);

            if (c == '=')
                token.type = TK_LESS_EQ;
            else if (c == '<')
                token.type = TK_LSHIFT;
            else
            {
                token.type = TK_LESS;
                ungetc(c, stream);
            }
            break;
        }
        case '>':
        {
            c = getc(stream);
            if (c == '=')
                token.type = TK_GREATER_EQ;
            else if (c == '>')
                token.type = TK_RSHIFT;
            else
            {
                token.type = TK_GREATER;
                ungetc(c, stream);
            }
            break;
        }

        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        {
            token.type = TK_NUMBER;
            do
            {
                c = getc(stream);
            } while (isdigit(c));
            ungetc(c, stream);
            break;
        }

        case '\'':
        {
            token.type = TK_CHAR;
            do
            {
                c = getc(stream);
                if (c == EOF)
                {
                    fputs("Error: Unterminated character literal\n", stderr);
                    exit(1);
                }
            } while (c != '\'');
            ungetc(c, stream);
            break;
        }

        case '"':
        {
            token.type = TK_STRING;
            do
            {
                c = getc(stream);
                if (c == EOF)
                {
                    fputs("Error: unterminated string literal\n", stderr);
                    exit(1);
                }
            } while (c != '"');
            ungetc(c, stream);
            break;
        }

        // Assume identifier or keyword if no other match
        default:
        {
            token.type = TK_IDENT;
            do
            {
                c = getc(stream);
            } while ((isalpha(c) || c == '_') && c != EOF);
            ungetc(c, stream);
        }
    }

    token.len = (ftell(stream) - token.offset) + 1;
    return token;
}

struct Token tk_prev(FILE *stream)
{
    struct Token token;

   	// To be implemented

    return token;
}