#include <iostream>
#include <string>
#include <cstdlib>

#include "nodes.h"

namespace Nodes {
    Node::Node(NodeType node_type, double value) {
        this->node_type = node_type;
        this->value = value;
        node_a = nullptr;
        node_b = nullptr;
    }

    Node::Node(NodeType node_type, Node *node_a, Node *node_b) {
        this->node_type = node_type;
        this->node_a = node_a;
        this->node_b = node_b;
    }

    Node::Node(NodeType node_type) {
        this->node_type = node_type;
        node_a = nullptr;
        node_b = nullptr;
    }

    Node::Node(NodeType node_type, Node *node_a) {
        this->node_type = node_type;
        this->node_a = node_a;
        node_b = nullptr;
    }

    Node::operator std::string const() {
        switch (node_type) {
            case NumberNode: return std::to_string(value);
            case PlusNode: return "(+" + static_cast<std::string>(*node_a) + ")";
            case MinusNode: return "(-" + static_cast<std::string>(*node_a) + ")";
            case AddNode: return "(" + static_cast<std::string>(*node_a) + " + " + static_cast<std::string>(*node_b) + ")";
            case SubtractNode: return "(" + static_cast<std::string>(*node_a) + " - " + static_cast<std::string>(*node_b) + ")";
            case MultiplyNode: return "(" + static_cast<std::string>(*node_a) + " * " + static_cast<std::string>(*node_b) + ")";
            case DivideNode: return "(" + static_cast<std::string>(*node_a) + " / " + static_cast<std::string>(*node_b) + ")";
            case PowerNode: return "(" + static_cast<std::string>(*node_a) + " ** " + static_cast<std::string>(*node_b) + ")";
            default: return "()";
        }
    }

    void print_node(Node *node) {
        std::cout << static_cast<std::string>(*node) << '\n';
    }

    void free_node(Node *node) {
        if (node->node_a != nullptr) {
            free_node(node->node_a);
            node->node_a = nullptr;
        }

        if (node->node_b != nullptr) {
            free_node(node->node_b);
            node->node_b = nullptr;
        }

        std::free(node);
    }
}