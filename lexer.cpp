#include <iostream>
#include <vector>
#include <string>
#include <cstddef>

#include "tokens.h"
#include "lexer.h"

namespace Lexer {
    Lexer::Lexer(std::string text) {
        this->text = text;
        index = 0;
        advance();
    }

    void Lexer::advance() {
        current_char = text[index++];
    }

    std::vector<Tokens::Token> Lexer::get_tokens() {
        std::vector<Tokens::Token> tokens;

        while (index <= text.length()) {
            if (current_char.find_first_of(WHITESPACE) != std::string::npos) {
                advance();
            } else if (current_char == "." || current_char.find_first_of(DIGITS) != std::string::npos) {
                tokens.push_back(get_number());
            } else if (current_char == "+") {
                advance();
                tokens.push_back(Tokens::Token(Tokens::PLUS));
            } else if (current_char == "-") {
                advance();
                tokens.push_back(Tokens::Token(Tokens::MINUS));
            } else if (current_char == "*") {
                advance();
                if (current_char == "*") {
                    advance();
                    tokens.push_back(Tokens::Token(Tokens::POWER));
                } else
                    tokens.push_back(Tokens::Token(Tokens::MULTIPLY));
            } else if (current_char == "/") {
                advance();
                tokens.push_back(Tokens::Token(Tokens::DIVIDE));
            } else if (current_char == "(") {
                advance();
                tokens.push_back(Tokens::Token(Tokens::LPAREN));
            } else if (current_char == ")") {
                advance();
                tokens.push_back(Tokens::Token(Tokens::RPAREN));
            } else {
                throw "Illegal character '" + current_char + "'";
            }
        }

        return tokens;
    }

    Tokens::Token Lexer::get_number() {
        int decimal_point_count = 0;
        std::string number_str = current_char;
        advance();

        while (index <= text.length() && (current_char == "." || current_char.find_first_of(DIGITS) != std::string::npos)) {
            if (current_char == ".")
                if (++decimal_point_count > 1)
                    break;
            
            number_str += current_char;
            advance();
        }

        if (number_str[0] == '.')
            number_str = "0" + number_str;

        if (number_str[number_str.length() - 1] == '.')
            number_str += "0";
        
        return Tokens::Token(Tokens::NUMBER, std::stod(number_str));
    }

    void print_tokens(std::vector<Tokens::Token>& tokens) {
        for (auto& token : tokens)
            Tokens::print_token(token);
    }
}