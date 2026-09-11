#pragma once

// Includes
#include "list.hpp" // Base Class
#include <iostream>
#include <cstddef>
#include <cassert>

// Constraints
#define DEFAULT_SIZE 10

/*
 * Array based list implementation
 */

template <typename E>
class Alist : public List<E>{
    private:
        int max_size;
        int curr_list_size;
        int curr_pos;
        E* list_arr;
    
    public:
        Alist(int size = DEFAULT_SIZE);
        ~Alist();

        void get_list() const {
            std::cout << "[";
            for (size_t i = 0; i < curr_list_size; i++)
               std::cout << list_arr[i] << (i == curr_list_size - 1 ? "" : ", ");
            
            std::cout << "]" << std::endl;
        }
        
        void clear() override;
        void insert(const E& item) override;
        void append(const E& item) override;
        E remove() override;

        // Essas funções movem a head da Alist
        void moveToStart() override;
        void moveToEnd() override;
        void prev() override;
        void next() override;
        
        int length() const override;
        int currPos() const override;
        void moveToPos(int pos) override;
        const E& getValue() const override;
        
};


template <typename E>
Alist<E>::Alist(int size){
    max_size = size;
    curr_list_size = curr_pos = 0;
    list_arr = new E[max_size];
}

template <typename E>
Alist<E>::~Alist(){
    delete[] list_arr;
}

template <typename E>
void Alist<E>::clear(){
    delete[] list_arr;
    curr_list_size = curr_pos = 0;
    list_arr = new E[max_size];
}

template <typename E>
void Alist<E>::insert(const E& item){
    assert(curr_list_size < max_size && "List is full");
    // A ideia é fazer uma regressão com base no tamanho atual da lista
    // até chegar na posição atual, de modo que todo elemento seja deslocado
    // para a direita para abrir espaço para o novo elemento
    for (size_t i = curr_list_size; i > curr_pos; i--)
        list_arr[i] = list_arr[i - 1];
    
    list_arr[curr_pos] = item;
    curr_list_size++;
    
}

template <typename E>
void Alist<E>::append(const E& item){
    assert(curr_list_size < max_size && "List is full");
    list_arr[curr_list_size++] = item;
}

// Remove and return current element
template <typename E>
E Alist<E>::remove(){
    assert((curr_pos >= 0) && (curr_pos < curr_list_size) && "No element");
    E it = list_arr[curr_pos];
    for (size_t i = curr_pos; i < curr_list_size; i++){
        list_arr[i] = list_arr[i + 1];
    }
    curr_list_size--;
    return it;
}

template <typename E>
void Alist<E>::moveToStart(){

    curr_pos = 0;    
    return;
}

template <typename E>
void Alist<E>::moveToEnd(){
    curr_pos = curr_list_size;
    return;
}

template <typename E>
void Alist<E>::prev(){
    if (curr_pos != 0) curr_pos--;
    return;
}

template <typename E>
void Alist<E>::next(){
    if (curr_pos != curr_list_size) curr_pos++;
    return;
}

template <typename E>
int Alist<E>::length() const{
    return curr_list_size;
}

template <typename E>
int Alist<E>::currPos() const{
    return curr_pos;
}

template <typename E>
void Alist<E>::moveToPos(int pos){
    if ((pos >= 0) && (pos <= curr_list_size)) curr_pos = pos;
    return;
}

template <typename E>
const E& Alist<E>::getValue() const{
    assert((curr_pos >= 0) && (curr_pos < curr_list_size));
    E& curr_value = list_arr[curr_pos];
    return curr_value;
}