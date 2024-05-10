#include <string>
#include "tokenizer.hpp"

namespace parse
{
    /// @brief String as number
    /// @param num 
    /// @return Parsed/cleaned string of number in decimal
    std::string int_literal(std::string_view num)
    {
        // Assume that the first element is a digit, because that's what caused it to be parsed in the first place.
        [[assume(num[0] <= '9' && num[0] >= '0')]];

        constexpr const char* map = "0123456789abcdef";
        unsigned base = 10;
        unsigned index = 0;
        
        if (num[i] == '0')
        {
            ++index;
            // Ordered by likelihood - hexadecimal, binary, and octal literal specifiers
            if (num[index] == 'x')
                base = 16;
            else if (num[index] == 'b')
                base = 2;
            else if (num[index] == 'c')
                base = 8;
        }

        
    }

    std::string_view float_literal(std::string_view num)
    {
        // Assume that the first element is a digit, because that's what caused it to be parsed in the first place.
        [[assume(num[0] <= '9' && num[0] >= '0')]];


    }

    std::stirng_view string_literal(std::string_view str)
    {
        // Assume that string literal begins with double-quotes
        [[assume(num[0] == '"')]];
    }
}