#include <string>
#include <vector>

// Declaration of token type
struct token
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
        HASHTAG       , // #
        SCOPE         , // ::
        ARROW         , // ->
        QUESTION      , // ?
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
        INCLUDE       , // Include a module file
        IN            , // For use in range-based for loops (for <element> in <range>)
        AS            , // Alias files (currently only used in `include <MODULE> as <ALIAS>)
        //////////////////
        // Types
        //////////////////
        INTEGER       , // Integer type
        FLOAT         , // Single-precision floating point type
        DOUBLE        , // Double-precision floating point type
        STRING        , // String of characters (byte pointer)
        ARRAY         , // Array type - decays to pointer
        // Other
        //////////////////
        INVALID       , //
        //////////////////
    };

    char* data; // char pointer to the beginning of the data the value was extracted from
    void* value; // void pointer to underlying value
    size_t value_len;
    description desc;
};

