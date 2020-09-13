#include <iostream>
#include <string>

#include "tokens.h"

namespace Tokens {
    Token::Token(TokenType type, double value) {
        this->type = type;
        this->value = value;
    }

    Token::operator std::string const() {
        std::string s;

        switch (type) {
            case NUMBER: s += "NUMBER"; break;
            case PLUS: s += "PLUS"; break;
            case MINUS: s += "MINUS"; break;
            case MULTIPLY: s += "MULTIPLY"; break;
            case DIVIDE: s += "DIVIDE"; break;
            case LPAREN: s += "LPAREN"; break;
            case RPAREN: s += "RPAREN"; break;
            case POWER: s += "POWER"; break;
            case EOF_: s += "EOF"; break;
        }

        if (type == NUMBER)
            s += ":" + std::to_string(value);

        return s;
    }

    void print_token(Token& token, bool newline) {
        std::cout << static_cast<std::string>(token);

        if (newline) std::cout << '\n';
    }
};