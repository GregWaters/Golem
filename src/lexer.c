#include "../inc/lexer.h"

// All of this needs to be rewritten to adapt to file changes!
struct Token tk_next(struct File *file)
{
    struct Token token;
    char c = *file->contents;

    // Skip whitespace and keep track of position
    while (1)
    {
        if (c == ' ')
            ++file->column;
        else if (c == '\t')
            ++file->column;
	else if (c == '\n')
	{
	    file->column = 0;
	    ++file->line;
	}
	else
	    break;
	
	c = *++file->contents;

	if (file->contents == file->end)
	{
	    token.type = TK_END;
            return token;
	}
    }

    // Run switch on first significant character in stream
    switch (c)
    {
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
	    c = *++file->contents;
            if (c == '>')
            {
                token.type = TK_ARROW;
                break;
            }

            --file->contents;
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
	    c = *++file->contents;

            if (c == '=')
                token.type = TK_LESS_EQ;
            else if (c == '<')
                token.type = TK_LSHIFT;
            else
            {
                token.type = TK_LESS;
                --file->contents;
            }
            break;
        }
        case '>':
        {
	    c = *++file->contents;

            if (c == '=')
                token.type = TK_GREATER_EQ;
            else if (c == '>')
                token.type = TK_RSHIFT;
            else
            {
                token.type = TK_GREATER;
                --file->contents;
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
                c = *++file->contents;
            } while (isdigit(c));
            --file->contents;
            break;
        }

        case '\'':
        {
            token.type = TK_CHAR;
            do
            {
                c = *++file->contents;
                if (file->contents == file->end)
                {
                    fputs("Error: Unterminated character literal\n", stderr);
                    exit(1);
                }
            } while (c != '\'');
            break;
        }

        case '"':
        {
            token.type = TK_STRING;
            do
            {
                if (++file->contents == file->end)
                {
		    c = *file->contents;
                    fputs("Error: unterminated string literal\n", stderr);
                    exit(1);
                }
            } while (c != '"');
            break;
        }

        // Assume identifier or keyword if no other match
        default:
        {
            token.type = TK_IDENT;
            do
            {
                c = *++file->contents;
            } while ((isalpha(c) || c == '_') && file->contents != file->end);
	    --file->contents;
        }
    }
    
    token.end = file->contents;
    
    // Make sure the contents pointer is pointing to the character immediately after the token
    ++file->contents;
    return token;
}

struct Token tk_prev(struct File *file)
{
    struct Token token;

   	// To be implemented

    return token;
}
