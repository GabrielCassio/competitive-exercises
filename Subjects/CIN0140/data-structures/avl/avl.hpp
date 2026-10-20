#ifndef AVL_HPP

#define AVL_HPP

#include "node.hpp"

class AVL {
    private:
        Node* root;
        int height();

        void tree_insert(Node* node, int value);
        void tree_insert_rec(Node* node, int value);
        void tree_insert_subtree(Node* node, int value);
        Node* tree_search(Node* node, int value);
        Node* iterative_tree_search(Node* node, int value); 
        void remove(Node* node, int value);
        void inorder_traversal(Node* node);
        void preorder_traversal(Node* node);
        void postorder_traversal(Node* node);

    public:
        AVL();
        ~AVL();

        void insert(int value);
        Node* search(int value);
        Node* tree_minimum(Node* node);
        Node* tree_maximum(Node* node);
        Node* tree_successor(Node* node);
        Node* tree_predecessor(Node* node);
        void remove(int value);
        void inorder_traversal();
        void preorder_traversal();
        void postorder_traversal();
};


#endif