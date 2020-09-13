#ifndef NODES_H
#define NODES_H

#include <string>

namespace Nodes {
    enum NodeType {
        PlusNode,
        MinusNode,
        EmptyNode,
        NumberNode,
        AddNode,
        SubtractNode,
        MultiplyNode,
        DivideNode,
        PowerNode
    };

    class Node {
        public:
            NodeType node_type;
            double value;
            Node *node_a;
            Node *node_b;

            Node(NodeType, double value);
            Node(NodeType, Node *, Node *);
            Node(NodeType);
            Node(NodeType, Node *);

            operator std::string const();
    };

    void print_node(Node *);
    void free_node(Node *);
}

#endif // NODES_H