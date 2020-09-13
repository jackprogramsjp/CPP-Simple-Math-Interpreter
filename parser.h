#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>

#include "tokens.h"
#include "nodes.h"

namespace Parser {
    class Parser {
        public:
            std::vector<Tokens::Token> tokens;
            int index;

            Parser(std::vector<Tokens::Token>);
            void advance();
            Tokens::Token current();
            Nodes::Node *parse();
            Nodes::Node *expr();
            Nodes::Node *term();
            Nodes::Node *exponent();
            Nodes::Node *factor();
    };
}

#endif // PARSER_H