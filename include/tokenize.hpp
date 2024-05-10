#include <string>
#include <vector>

// Declaration of token type
class token
{
    enum class description
    {
        // Parentheses, brackets, and braces
        //////////////////
        LEFT_PAREN    , // (
        RIGHT_PAREN   , // )
        LEFT_BRACKET  , // [
        RIGHT_BRACKET , // ]
        LEFT_BRACE    , // {
        RIGHT_BRACE   , // }
        //////////////////
        // Arithmetic
        //////////////////
        PLUS          , // +
        MINUS         , // -
        ASTERISK      , // *
        POWER         , // **
        SLASH         , // /
        MODULO        , // %
        RANGE         , // :
        //////////////////
        // Bitwise Arithmetic
        //////////////////
        BITAND        , // &
        BITOR         , // |
        XOR           , // ^
        LSHIFT        , // <<
        RSHIFT        , // >>
        BITNOT        , // ~
        //////////////////
        // Other
        //////////////////
        COMMA         , // ,
        DOT           , // .
        TILDE         , // ~
        AT            , // @
        COMMENT       , // #
        SCOPE         , // ::
        ARROW         , // ->
        //////////////////
        // Boolean
        //////////////////
        NOT           , // !
        NOT_EQUAL     , // !=
        EQUALS        , // =
        IS_EQUAL      , // ==
        AND           , // &&
        OR            , // ||
        GREATER       , // >
        GREATER_EQUAL , // >=
        LESS          , // <
        LESS_EQUAL    , // <=
        //////////////////
        // Literals
        //////////////////
        IDENTIFIER    , // Name for variables and functions
        STRING        , // String of characters; "Hello, world!"
        FLOAT         , // 3.14, 1.1e5
        //////////////////
        // Keywords
        //////////////////
        CLASS         , // Keyword used to define a class
        ELSE          , // Control-flow 'else' statement
        FALSE         , // Boolean type meaning 0
        FOR           , // Beginning of for-loop block
        IF            , // If-statement keyword
        RETURN        , // Return keyword used to return values from functions
        THIS          , // 'this' pointer; used to access the current object from within a class
        TRUE          , // Boolean type meaning 1
        WHILE         , // While-loop keyword
        MODULE        , // Use outside code in current source file
        IN            , // For use in range-based for loops (for <element> in <array>)
        VIEW          , // For use in constant variables that exist in static memory, or for constant function parameters passed as reference
        //////////////////
        // Qualifiers
        //////////////////
        DYNAMIC       , // Variable qualifier that allows it to automatically claim memory when its limits are reached
        CONST         , // Makes a variable immutable (gives a compile-time error when an assignment is attempted)
        //////////////////
    };

    description desc;
    std::string_view str;
};

std::vector<token> get_all_tokens(std::string_view str)
{
    std::vector<token> tokens;
    tokens.reserve(8); // "There will probably be around 8 tokens per line" Heuristic optimization

    for (unsigned i = 0; i < str.length(); ++i)
    {
        switch (expression)
        {
        case 
        
        default:
            break;
        }
    }

    return tokens;
}
