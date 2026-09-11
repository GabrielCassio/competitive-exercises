#ifndef SINGLY_LINKED_LIST_HPP
#define SINGLY_LINKED_LIST_HPP


/**
 * Eu preferi por não utilizar o argumento de passar um 
 * ponteiro next ou previous como argumento para os nodes
 */
#include <iostream>
#include "node.hpp"

template<typename T>
class SinglyLinkedList {
    private:
        Node<T>* curr_node;
        Node<T>* head;
        int list_size;

        inline void init() {
            head = curr_node = new Node<T>;
            list_size = 0;
            return;
        }

        inline void remove_all() {
            curr_node = head;
            while (curr_node -> next != nullptr) {
                Node<T>* rm_node = curr_node;
                curr_node = curr_node -> next;
                delete rm_node;
            }
            list_size = 0;
            return;
        }

    public:

        inline void print () {
            if (list_size == 0) {
                std::cout << "[]";
                return;
            }
            std::cout << "[";
            curr_node = head;
            while (curr_node != nullptr) {
                (curr_node -> next != nullptr) ? std::cout << curr_node -> data << ", " : std::cout << curr_node -> data;
                curr_node = curr_node -> next;
            }
            std::cout << "]" << std::endl;
            return;
        }

        SinglyLinkedList () {
            init();
        }
        ~SinglyLinkedList() {
            remove_all();
        }


        inline void append(const T& elem) {
            if (list_size == 0) {
                curr_node -> next = head;
                curr_node = new Node<T>(elem);
                head = curr_node;
                list_size++;
                return;
            }
            curr_node = curr_node->next = new Node<T>(elem);
            list_size++;
            return;
        }
        void insert(const T& elem, int pos) {
            if (pos < 0 || pos > list_size - 1) {
                std::cout << "A lista precisa de pelo menos um elmento" << std::endl;
                return;
            }

            if (pos == 0) {
                Node<T>* new_node = new Node<T>(elem);
                new_node -> next = head;
                head = new_node; new_node = nullptr;
                list_size++;
                return;
            }

            curr_node = head; int curr_pos = 0;
            while (curr_pos++ < pos - 1) {
                curr_node = curr_node -> next;                
            }
            
            Node<T>* new_node = new Node<T>(elem);
            new_node -> next = curr_node -> next;
            curr_node -> next = new_node; curr_node = new_node;
            new_node = nullptr;
            list_size++;

            return;
        }
        int find(int pos) {
            if (pos > 0 || pos < list_size - 1) return int{};
            curr_node = head; int curr_pos = 0;
            while (curr_pos++ < pos) {
                curr_node = curr_node -> next;
            }
            return curr_node -> data;
        }
        void del(int pos) {
            if (pos < 0 || pos > list_size - 1) return;

            if (pos == 0) {
                Node<T>* rm_node = head;
                head = head -> next;
                delete rm_node;
                list_size--;
                return;
            }

            curr_node = head; Node<T>* curr_prev = nullptr; int curr_pos = 0;
            while (curr_pos++ < pos) {
                curr_prev = curr_node;
                curr_node = curr_node -> next;
            }

            std::cout << curr_node -> data;

            if (curr_node -> next == nullptr) {
                curr_node = curr_prev; 
                curr_prev -> next = nullptr;
                curr_prev = nullptr;
                delete curr_prev;
                list_size--;
                return;
            }

            curr_prev -> next = curr_node -> next;      
            curr_node = curr_prev; curr_prev = nullptr;    
            list_size--;
            return;
        }
        void clear() {
            remove_all();
            init();
            return;
        }

        inline void get_head () const {
            std::cout << "The Linked List Head: " << head->data << std::endl;
            return;
        }

};

#endif // SINGLY_LINKED_LIST