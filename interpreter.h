#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <string>

#include "nodes.h"
#include "values.h"

namespace Interpreter {
    class Interpreter {
        public:
            Values::Number visit(Nodes::Node *);
            Values::Number visit_add_node(Nodes::Node *);
            Values::Number visit_subtract_node(Nodes::Node *);
            Values::Number visit_multiply_node(Nodes::Node *);
            Values::Number visit_divide_node(Nodes::Node *);
            Values::Number visit_power_node(Nodes::Node *);
            Values::Number visit_plus_node(Nodes::Node *);
            Values::Number visit_minus_node(Nodes::Node *);
    };
}

#endif // INTERPRETER_H