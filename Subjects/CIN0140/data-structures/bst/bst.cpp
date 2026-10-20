#include "bst.hpp"

BST::BST() : root(nullptr) {}
BST::~BST () {}


// Tree INSERT methods
void BST::insert(int value) {
    tree_insert(root, value);
    return;
}

void BST::tree_insert(Node* node, int value) {
    Node* y = nullptr;
    Node* x = root;

    while (x != nullptr) {
        y = x;
        if (value < x->value) x = x->left;
        else x = x->right;
    }

    Node* newNode = new Node(value);
    newNode->parent = y;

    if (y == nullptr) root = newNode;
    else if (value < y->value) y->left = newNode;
    else y->right = newNode;
}

void BST::tree_insert_subtree(Node* node, int value) {
    if (value < node->value) {
        if (node->left == nullptr) {
            Node* newNode = new Node(value);
            node->left = newNode;
            newNode->parent = node;
        } else {
            tree_insert_subtree(node->left, value);
        }
    } else {
        if (node->right == nullptr) {
            Node* newNode = new Node(value);
            node->right = newNode;
            newNode->parent = node;
        } else {
            tree_insert_subtree(node->right, value);
        }
    }
}

void BST::tree_insert_rec(Node* node, int value) {
    if (node == nullptr) {
        Node* newNode = new Node(value);
        if (root == nullptr) root = newNode;
        return;
    } else {
        tree_insert_subtree(node, value);
    }

    return;
}


// Tree SEARCH methods

Node* BST::search(int value) {
    tree_search(root, value);
    return;
}

Node* BST::tree_search(Node* node, int value) {

    if (node == nullptr || node->value == value) return node;
    if (value < node->value) return tree_search(node->left, value);
    else return tree_search(node->right, value);

}

Node* BST::iterative_tree_search(Node* node, int value) {
    while (node != nullptr && node->value != value) {
        if (value < node->value) node = node->left;
        else node = node->right;
    }
    return node;
}


// Tree Maximum and Minimum methods
Node* BST::tree_maximum(Node* node) {
    if (node == nullptr) return nullptr;
    while (node->right != nullptr) node = node->right;
    return node;
}

Node* BST::tree_minimum(Node* node) {
    if (node == nullptr) return nullptr;
    while (node->left != nullptr) node = node->left;
    return node;
}


// Tree Successor and Predecessor methods
Node* BST::tree_successor(Node* node) {
    if (node->right != nullptr) return tree_minimum(node->right);
    Node* y = node->parent;
    while (y != nullptr && node == y->right) {
        node = y;
        y = y->parent;
    }
    return y;
}

Node* BST::tree_predecessor(Node* node) {
    if (node->left != nullptr) return tree_maximum(node->left);
    Node* y = node->parent;
    while (y != nullptr && node == y->left) {
        node = y;
        y = y->parent;
    }
    return y;
}


// Tree REMOVE methods
void BST::remove(int value) {
    tree_delete(root, value);
    return;
}
void BST::tree_delete(Node* node, int value) {
    Node* z = tree_search(node, value);
    if (z != nullptr) {
        z->delete_node();
    }
    return;
}
void BST::tree_delete_inline(Node* node, int value) {
    if (node->left == nullptr && node->right == nullptr) {
        if (node->parent == nullptr) root = nullptr;
        else if (node == node->parent->left) node->parent->left = nullptr;
        else node->parent->right = nullptr;
    } 
    else if ((node->left == nullptr) || (node->left == nullptr)) {
        if (node->left == nullptr) {
            if (node->parent == nullptr) root = node->right;
            else if (node == node->parent->left) node->parent->left = node->right;
            else node->parent->right = node->parent;
            node->right->parent = node->parent;
        } 
        else {
            if (node->parent == nullptr) root = node->left;
            else if (node == node->parent->left) node->parent->left = node->left;
            else node->parent->right = node->left;
            node->left->parent = node->parent;
        }
    }
    else {
        Node* y = node->right;
        while (y->left != nullptr) y = y->left;
        node->value = y->value;
        if (y->parent = node) {
            node->right = y->right;
            if (y->right != nullptr) y->right->parent = node;
        } else {
            y->parent->left = y->right;
            if (y->right != nullptr) y->right->parent = y->parent;
        }
    }
}

void BST::tree_delete_transplant(Node* node, int value) {

    if (node->left == nullptr) transplant(node, node->right);
    else if (node->right == nullptr) transplant(node, node->left);
    else {
        Node* y = tree_minimum(node->right);
        if (y->parent != node) {
            transplant(y, y->right);
            y->right = node->right;
            y->right->parent = y;
        }
        transplant(node, y);
        y->left = node->left;
        y->left->parent = y;
    }
}
void BST::transplant(Node* u, Node* v) {
    if (u->parent == nullptr) root = v;
    else if (u == u->parent->left) u->parent->left = v;
    else u->parent->right = v;
    if (v != nullptr) v->parent = u->parent;
}
