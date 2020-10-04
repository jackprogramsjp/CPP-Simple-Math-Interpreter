#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>

#include "tokens.h"
#include "nodes.h"

#define PARSER_EMPTY_NODE node = new Nodes::Node(Nodes::EmptyNode)

namespace Parser {
    class Parser {
        public:
            std::vector<Tokens::Token> tokens;
            std::size_t index;
            Nodes::Node *node;

            Parser(std::vector<Tokens::Token>);
            ~Parser();
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