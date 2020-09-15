#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>
#include <cstddef>

#define WHITESPACE " \n\t"
#define DIGITS "0123456789"

namespace Lexer {
    class Lexer {
        public:
            std::string text;
            std::size_t index;
            std::string current_char;

            Lexer(std::string);

            void advance();
            std::vector<Tokens::Token> get_tokens();
            Tokens::Token get_number();
    };

    void print_tokens(std::vector<Tokens::Token>&);
}

#endif // LEXER_H