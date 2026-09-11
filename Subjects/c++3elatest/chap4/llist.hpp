#pragma once
#include "list.hpp"
#include "link.hpp"

#include <iostream>

#define DEFAULT_LIST_SIZE 10
/*
 * Implemeentação de uma LikedList que estruturalmente equivale a um
 * conjunto de nodes encadeados unidirecionalmente
 */
template <typename E>
class LList : public List<E> {
    private:
        Link<E>* head_node;
        Link<E>* tail_node;
        Link<E>* curr_node;
        int list_size;

        void init() {
            curr_node = head_node = tail_node = new Link<E>;
            list_size = 0;
            return;
        }

        void remove_all(){
            while (head_node != nullptr){
                curr_node = head_node;
                head_node = head_node -> next;
                delete curr_node;
                // std::cout << "O tamanho da lista ligada atual é: " << list_size << std::endl;
            }
            return;
        }
    
    public:
        LList(int size = DEFAULT_LIST_SIZE) : list_size(size) {
            init();
        }
        ~LList() { remove_all(); }
        
        void clear() override {
            remove_all();
            init();
            return;
        }
        void insert(const E& item) override {
            // Pega o ponteiro do próximo node que o node atual carrega e atribui um novo nó com conteúdo
            curr_node -> next = new Link<E>(item, curr_node -> next);
            // Se ponteiro do nó atual for igual o da cauda da lista, então faz com tail aponte para o próximo nó
            // o que foi criado
            if (curr_node == tail_node) tail_node = curr_node -> next;
            list_size++;
            return;
        }   
        void append(const E& item) override {
            // Para adicionar um elmento ao final de uma lista ligada, utiliza-se o endereço do último nó,
            // mais conhecido como tail para pegar o enreço que ela apontando (null_ptr) e atribuir um novo link_node
            tail_node = tail_node -> next = new Link<E>(item, tail_node -> next);
            list_size++;
            return;
        }
        E remove() override {
            // Remover um  elemento nessa implemntação significa pegar o elemento do próximo nó e substituí-lo pelo próximo
            if (curr_node -> next == nullptr) return E{};
            // Captura o elemento que será removido
            E item = curr_node -> next -> element;
            // Guarda temporariamente o node que será removido (o próximo)
            Link<E>* temp_node = curr_node->next;
            // Caso o node que for removido seja o tail, então atribui ao tail node atual e não o próximo
            if (curr_node->next == tail_node) tail_node = curr_node;
            // Pega o nó apontado (que será removido) de node atual e substitui por aquele que o suscede
            curr_node->next = curr_node -> next -> next;
            // Deleta o node 
            delete temp_node;
            // Atualiza o tamanho da lista
            list_size--;
            return item;
        }
        void moveToStart() override { curr_node = head_node; }
        void moveToEnd() override { curr_node = tail_node; }
        void prev() override { 
            if (curr_node == head_node) return;
            Link<E>* temp_node = head_node;
            // Procura do início até o fim, ou seja, leva O(n) no worst case
            while (temp_node -> next != curr_node) temp_node = temp_node -> next;
            curr_node = temp_node;
            return;
        }
        void next() override {
            if (curr_node != tail_node) curr_node = curr_node -> next;
        }
        int length() const override {
            return list_size;
        }
        int currPos() const override {
            Link<E>* temp_node = head_node;
            for (int i = 0; i < list_size; i++){
                temp_node = temp_node -> next;
                if (curr_node == temp_node) return i;
            }
        }
        void moveToPos(int pos) override {
            if (pos < 0 && pos > list_size) return;
            curr_node = head_node;
            int i = 0;
            while (i++ < pos) curr_node = curr_node -> next;
        }
        const E& getValue() const override {
            if (curr_node -> next == nullptr) return E{};
            return curr_node -> next -> element;
        }

        void print_elements() {
            Link<E>* temp_node = head_node;
            std::cout << "[";
            for (int i = 0; i < list_size; i++)
            {   
                if (temp_node -> next == nullptr) return;
                temp_node = temp_node -> next;
                std::cout << temp_node -> element << (i+1 == list_size ? "" : ", ");
            }
            std::cout << "]" << std::endl;
        }
};