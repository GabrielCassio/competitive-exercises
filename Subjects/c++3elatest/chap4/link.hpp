#pragma once

/*
 * O link é uma estrutura utilziada na implementação de lista encadeada,
 * stack e queue, por isso 2 constructors e membros públicos.
 */

template <typename E>
class Link {
    private:

    public:
        E element; // Elemento do link
        Link *next; // Endereço do próximo link

        // Construtores ===============================
        // Recebe o valor do elemento e o endereço do próximo link
        Link (const E& elem_val, Link* next_val = nullptr) : element(elem_val), next(next_val){}

        // Recebe o endereço do próximo link
        Link (Link* next_val = nullptr) : next(next_val) {}
};