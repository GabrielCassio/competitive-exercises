#ifndef NODE_HPP
#define NODE_HPP

class Node {
    public:
        int value;
        Node* parent;
        Node* left;
        Node* right;

        Node(int val) : value(val), left(nullptr), right(nullptr) {}
        Node(int val, Node* leftChild, Node* rightChild) : value(val), left(leftChild), right(rightChild) {}
        inline void delete_node() {
            if (left != nullptr) left->parent = parent;
            if (right != nullptr) right->parent = parent;
            if (parent != nullptr) {
                if (parent->left == this) parent->left = left != nullptr ? left : right;
                else parent->right = left != nullptr ? left : right;
            }
            delete this;
        }
};

#endif