#include <iostream>
#include <vector>
#include <string>

#include "tokens.h"
#include "lexer.h"
#include "nodes.h"
#include "parser.h"
#include "interpreter.h"
#include "values.h"

int main() {
    std::string text;
    std::vector<Tokens::Token> tokens;

    while (true) {
        try {
            std::cout << "calc > ";
            std::getline(std::cin, text);
            Lexer::Lexer lexer(text);
            tokens = lexer.get_tokens();
            //Lexer::print_tokens(tokens);
            Parser::Parser parser(tokens);
            Nodes::Node *tree = parser.parse();
            //Nodes::print_node(tree);
            if (tree->node_type != Nodes::EmptyNode) {
                Interpreter::Interpreter interpreter;
                Values::Number result = interpreter.visit(tree);
                Values::print_number(result);
            }
            Nodes::free_node(tree);
            tree = nullptr;
        } catch (std::string e) {
            std::cerr << e << '\n';
        }
    }
}
