#ifndef BST_HPP

#define BST_HPP

#include "node.hpp"

class BST {
    private:
        Node* root;
        int height();

        void tree_insert(Node* node, int value);
        void tree_insert_rec(Node* node, int value);
        void tree_insert_subtree(Node* node, int value);
        Node* tree_search(Node* node, int value);
        Node* iterative_tree_search(Node* node, int value); 
        void tree_delete(Node* node, int value);
        void tree_delete_inline(Node* nod, int value);
        void tree_delete_transplant(Node* node, int value);
        void transplant(Node* u, Node* v);
        void inorder_traversal(Node* node);
        void preorder_traversal(Node* node);
        void postorder_traversal(Node* node);

    public:
        BST();
        ~BST();

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