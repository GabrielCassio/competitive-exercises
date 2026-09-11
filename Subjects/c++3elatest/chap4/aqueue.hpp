#pragma once
#include "queue.hpp"
#include <iostream>

#define DEFAULT_QUEUE_SIZE 10

// Implementação de uma fila baseada em array circular
template <typename E>
class AQueue : public Queue<E>{
    private:
        int max_size;
        int rear_pos;
        int front_pos;
        E* queue_list;

    public:

        AQueue(int size = DEFAULT_QUEUE_SIZE) : max_size(size+1) {
            rear_pos = 0; front_pos = 1;
            queue_list = new E[max_size];
        }
        ~AQueue() { delete [] queue_list; }

        // Para unma fila, o método clear indica o reset da posição de front e rear
        void clear(void) { rear_pos = 0; front_pos = 1; }
        void enqueue(const E& elem) {
            std::cout << "Posição front: " << front_pos << std::endl;
            std::cout << "Posição do rear: " << (rear_pos + 2) % max_size << std::endl; 
            if ((rear_pos+2) % max_size == front_pos) {
                std::cout << "Tivemos um problema: " << (rear_pos+2) % max_size << "é igual a " << front_pos << std::endl;
                return;}
            // Dado o tamanho máximo do array utilizado para implementar a fila, utiliza-se do (mod max_size para saber a posição)
            rear_pos = (rear_pos + 1) % max_size;
            queue_list[rear_pos] = elem;
        }
        E dequeue(void) {
            if (length() == 0) return E{};
            E elem = queue_list[front_pos];
            front_pos = (front_pos+1) % max_size;
            return elem;
        }
        E front_value(void) {
            if (length() == 0) return E{};
            return queue_list[front_pos];
        }
        int length(void) {
            return ((rear_pos + max_size) - front_pos + 1) % max_size;
        }

        void print_elements(void){
            int curr_queue_length = length();
            std::cout << "[";
            for (int i = 0; i < curr_queue_length; i++) {
                std::cout << queue_list[(front_pos + i) % max_size] << (i+1 == curr_queue_length ? "" : ", ");
            }
            std::cout << "]";
        }

        int get_max_size(){ return max_size; }
};