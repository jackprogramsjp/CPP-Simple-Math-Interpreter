#include <string>
#include <cmath>

#include "nodes.h"
#include "values.h"
#include "interpreter.h"

namespace Interpreter {
    Values::Number Interpreter::visit(Nodes::Node *node) {
        switch (node->node_type) {
            case Nodes::NumberNode:
                return Values::Number(node->value);
            case Nodes::AddNode:
                return visit_add_node(node);
            case Nodes::SubtractNode:
                return visit_subtract_node(node);
            case Nodes::MultiplyNode:
                return visit_multiply_node(node);
            case Nodes::DivideNode:
                return visit_divide_node(node);
            case Nodes::PowerNode:
                return visit_power_node(node);
            case Nodes::PlusNode:
                return visit_plus_node(node);
            case Nodes::MinusNode:
                return visit_minus_node(node);
            default:
                throw std::string("Invalid node");
        }
    }

    Values::Number Interpreter::visit_add_node(Nodes::Node *node) {
        return Values::Number(visit(node->node_a).value + visit(node->node_b).value);
    }

    Values::Number Interpreter::visit_subtract_node(Nodes::Node *node) {
        return Values::Number(visit(node->node_a).value - visit(node->node_b).value);
    }

    Values::Number Interpreter::visit_multiply_node(Nodes::Node *node) {
        return Values::Number(visit(node->node_a).value * visit(node->node_b).value);
    }

    Values::Number Interpreter::visit_divide_node(Nodes::Node *node) {
        double value = visit(node->node_b).value;

        if (value == 0.0)
            throw std::string("Zero division error");

        return Values::Number(visit(node->node_a).value / value);
    }

    Values::Number Interpreter::visit_power_node(Nodes::Node *node) {
        return Values::Number(std::pow(visit(node->node_a).value, visit(node->node_b).value));
    }

    Values::Number Interpreter::visit_plus_node(Nodes::Node *node) {
        return visit(node->node_a);
    }

    Values::Number Interpreter::visit_minus_node(Nodes::Node *node) {
        return Values::Number(-1 * visit(node->node_a).value);
    }
}