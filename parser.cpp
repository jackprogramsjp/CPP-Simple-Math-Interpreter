#include <string>
#include <vector>
#include <iostream>

#include "parser.h"
#include "tokens.h"
#include "nodes.h"

namespace Parser {
    Parser::Parser(std::vector<Tokens::Token> tokens) {
        tokens.push_back(Tokens::Token(Tokens::EOF_));
        this->tokens = tokens;
        index = 0;
    }

    Parser::~Parser() {
        Nodes::free_node(node);
    }

    void Parser::advance() {
        index++;
    }

    Tokens::Token Parser::current() {
        return tokens[index];
    }

    Nodes::Node *Parser::parse() {
        if (current().type == Tokens::EOF_) {
            PARSER_EMPTY_NODE;
            return node;
        }
        
        node = expr();

        if (current().type != Tokens::EOF_) {
            PARSER_EMPTY_NODE;
            throw std::string("Invalid syntax");
        }
                        
        return node;
    }

    Nodes::Node *Parser::expr() {
        Nodes::Node *result = term();

        while (current().type != Tokens::EOF_ && (current().type == Tokens::PLUS || current().type == Tokens::MINUS)) {
            if (current().type == Tokens::PLUS) {
                advance();
                result = new Nodes::Node(Nodes::AddNode, result, term());
            } else if (current().type == Tokens::MINUS) {
                advance();
                result = new Nodes::Node(Nodes::SubtractNode, result, term());
            }
        }

        return result;
    }

    Nodes::Node *Parser::term() {
        Nodes::Node *result = exponent();

        while (current().type != Tokens::EOF_ && (current().type == Tokens::MULTIPLY || current().type == Tokens::DIVIDE)) {
            if (current().type == Tokens::MULTIPLY) {
                advance();
                result = new Nodes::Node(Nodes::MultiplyNode, result, exponent());
            } else if (current().type == Tokens::DIVIDE) {
                advance();
                result = new Nodes::Node(Nodes::DivideNode, result, exponent());
            }
        }

        return result;
    }

    Nodes::Node *Parser::exponent() {
        Nodes::Node *result = factor();

        while (current().type != Tokens::EOF_ && current().type == Tokens::POWER) {
            if (current().type == Tokens::POWER) {
                advance();
                result = new Nodes::Node(Nodes::PowerNode, result, factor());
            }
        }

        return result;
    }

    Nodes::Node *Parser::factor() {
        Tokens::Token current_token = current();

        if (current_token.type == Tokens::LPAREN) {
            advance();
            Nodes::Node *result = expr();

            if (current().type != Tokens::RPAREN) {
                PARSER_EMPTY_NODE;
                throw std::string("Syntax error");
            }

            advance();
            return result;
        } else if (current_token.type == Tokens::NUMBER) {
            advance();
            return new Nodes::Node(Nodes::NumberNode, current_token.value);
        } else if (current_token.type == Tokens::PLUS) {
            advance();
            return new Nodes::Node(Nodes::PlusNode, factor());
        } else if (current_token.type == Tokens::MINUS) {
            advance();
            return new Nodes::Node(Nodes::MinusNode, factor());
        }

        PARSER_EMPTY_NODE;
        
        throw std::string("Syntax error");
    }
}