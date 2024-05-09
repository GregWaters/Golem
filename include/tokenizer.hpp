#include <fstream>
#include <string>
#include <vector>

class file_tokenizer
{
    // Declaration of token type
    enum class token
    {
        // Parentheses, brackets, and braces
        //////////////////
        LEFT_PAREN,     // (
        RIGHT_PAREN,    // )
        LEFT_BRACKET,   // [
        RIGHT_BRACKET,  // ]
        LEFT_BRACE,     // {
        RIGHT_BRACE,    // }
        //////////////////

        // Arithmetic
        //////////////////
        PLUS,           // +
        MINUS,          // -
        ASTERISK,       // *
        SLASH,          // /
        PERCENT,        // %
        //////////////////

        // Other
        //////////////////
        COMMA,          // ,
        DOT,            // .
        SEMICOLON,      // ;
        TILDE,          // ~
        AT,             // @
        HASHTAG,        // #
        //////////////////

        // Boolean
        //////////////////
        NOT,            // !
        NOT_EQUAL,      // !=
        EQUALS,         // =
        IS_EQUAL,       // ==
        GREATER,        // >
        GREATER_EQUAL,  // >=
        LESS,           // <
        LESS_EQUAL,     // <=
        //////////////////

        // Literals
        //////////////////
        IDENTIFIER,     // Name for variables and functions
        STRING,         // String of characters; "Hello, world!"
        NUMBER,         // Numeric literal; 42, 3.14, 0xDEAFDEED
        //////////////////

        // Keywords
        //////////////////
        CLASS,          // Keyword used to define a class
        ELSE,           // Control-flow 'else' statement
        FALSE,          // Boolean type meaning 0
        FOR,            // Beginning of for-loop block
        IF,             // If-statement keyword
        RETURN,         // Return keyword used to return values from functions
        THIS,           // 'this' pointer; used to access the current object from within a class
        TRUE,           // Boolean type meaning 1
        WHILE,          // While-loop keyword
        MODULE,         // Use outside code in current source file
        //////////////////

        // Qualifiers
        //////////////////
        DYNAMIC,        // Variable qualifier that allows it to automatically claim memory when its limits are reached
        CONST,          // Makes a variable immutable (gives a compile-time error when an assignment is attempted)
        //////////////////
    };

    // File to read from
    std::fstream file;

    file_tokenizer(std::string_view filename)
    {
        file.open(filename.data(), std::fstream::in);
    }

    std::vector<token> get_all_tokens()
    {
        std::vector<token> tokens;

        return tokens;
    }
};
