#include "tokens.h"

enum token consume_numeric_literal(char **data)
{
    bool dot_found = false;
    
    while (1)
    {
        
    }
}

// Consume data (will modify pointer) to return a token
// Returns 0 if no match could be made (EOS)
enum token consume_token(char **data)
{
    switch (**data)
    {
        case '0':
        {
            
        }

        case '1' ... '9':
        {

        }
    }
}
