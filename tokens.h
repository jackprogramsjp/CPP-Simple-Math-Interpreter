#ifndef TOKENS_H
#define TOKENS_H

#include <string>

namespace Tokens {
    enum TokenType {
        NUMBER,
        PLUS,
        MINUS,
        MULTIPLY,
        DIVIDE,
        LPAREN,
        RPAREN,
        POWER,
        EOF_
    };

    class Token {
        public:
            TokenType type;
            double value;

            Token(TokenType, double = 0);

            operator std::string const();
    };

    void print_token(Token&, bool = true);
};

#endif // TOKENS_H