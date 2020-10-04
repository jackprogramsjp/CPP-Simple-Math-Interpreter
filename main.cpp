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
            std::cout << "calc > " << std::flush;
            std::getline(std::cin, text);
            if (std::cin.bad()) {
                std::cerr << "IO error\n";
                break;
            } else if (std::cin.eof()) {
                std::cerr << "End of file\n";
                break;
            }
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
        } catch (std::string e) {
            std::cerr << e << '\n';
        }
    }
}
