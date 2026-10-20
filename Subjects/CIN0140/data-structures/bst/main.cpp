#include "bst.hpp"

#include <initializer_list>
#include <iostream>
#include <string>

namespace {

int failures = 0;

void check(bool condition, const std::string& description) {
    if (condition) {
        std::cout << "[OK]   " << description << '\n';
    } else {
        std::cout << "[FAIL] " << description << '\n';
        ++failures;
    }
}

void insert_all(BST& tree, std::initializer_list<int> values) {
    for (int value : values) {
        tree.insert(value);
    }
}

void test_search_and_extremes() {
    BST tree;
    insert_all(tree, {50, 30, 70, 20, 40, 60, 80, 65});

    Node* found = tree.search(40);
    check(found != nullptr && found->value == 40,
          "search encontra um valor existente");
    check(tree.search(999) == nullptr,
          "search retorna nullptr para valor inexistente");

    Node* root = tree.search(50);
    check(root != nullptr && tree.tree_minimum(root)->value == 20,
          "tree_minimum encontra o menor valor");
    check(root != nullptr && tree.tree_maximum(root)->value == 80,
          "tree_maximum encontra o maior valor");
}

void test_successor_and_predecessor() {
    BST tree;
    insert_all(tree, {50, 30, 70, 20, 40, 60, 80, 65});

    Node* node20 = tree.search(20);
    Node* node50 = tree.search(50);
    Node* node80 = tree.search(80);
    Node* node60 = tree.search(60);

    Node* successor20 = node20 == nullptr ? nullptr : tree.tree_successor(node20);
    Node* successor50 = node50 == nullptr ? nullptr : tree.tree_successor(node50);
    Node* predecessor80 = node80 == nullptr ? nullptr : tree.tree_predecessor(node80);
    Node* predecessor60 = node60 == nullptr ? nullptr : tree.tree_predecessor(node60);

    check(successor20 != nullptr && successor20->value == 30,
          "tree_successor percorre a subida da árvore");
    check(successor50 != nullptr && successor50->value == 60,
          "tree_successor usa o mínimo da subárvore direita");
    check(predecessor80 != nullptr && predecessor80->value == 70,
          "tree_predecessor percorre a subida da árvore");
    check(predecessor60 != nullptr && predecessor60->value == 50,
          "tree_predecessor usa o máximo da subárvore esquerda");
}

void test_remove_leaf_and_single_child() {
    BST tree;
    insert_all(tree, {50, 30, 70, 20, 40, 60, 80, 65});

    tree.remove(20);
    check(tree.search(20) == nullptr,
          "remove exclui uma folha");

    tree.remove(60);
    Node* promoted = tree.search(65);
    check(promoted != nullptr && promoted->parent != nullptr &&
              promoted->parent->value == 70,
          "remove promove o filho único de um nó não-raiz");

    tree.remove(999);
    check(tree.search(40) != nullptr,
          "remove de valor inexistente preserva a árvore");
}

void test_remove_with_two_children() {
    BST tree;
    insert_all(tree, {50, 30, 70, 20, 40, 60, 80});

    tree.remove(70);

    check(tree.search(70) == nullptr,
          "remove exclui o nó solicitado quando ele possui dois filhos");
    check(tree.search(60) != nullptr,
          "remove preserva o filho esquerdo do nó com dois filhos");
    check(tree.search(80) != nullptr,
          "remove preserva o filho direito do nó com dois filhos");
}

void test_empty_and_duplicate_values() {
    BST empty;
    check(empty.search(1) == nullptr,
          "search em uma árvore vazia retorna nullptr");

    BST tree;
    tree.insert(10);
    tree.insert(10);
    Node* first = tree.search(10);
    check(first != nullptr && first->right != nullptr &&
              first->right->value == 10,
          "insert coloca duplicatas na subárvore direita");
}

}  // namespace

int main() {
    std::cout << "Testes da BST\n\n";

    test_search_and_extremes();
    test_successor_and_predecessor();
    test_remove_leaf_and_single_child();
    test_remove_with_two_children();
    test_empty_and_duplicate_values();

    std::cout << "\nResultado: " << failures << " falha(s)\n";
    return failures == 0 ? 0 : 1;
}
