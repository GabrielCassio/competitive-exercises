#ifndef ADT_LINKED_LIST_HPP
#define ADT_LINKED_LIST_HPP

#include "node.hpp"

template <typename T>
class AdtLinkedList {
    protected:
        Node<T>* curr_node = nullptr;
        int list_size = 0;

    public:
        AdtLinkedList () {}
        ~AdtLinkedList() {}

        virtual void append(const T& elem) = 0;
        virtual void insert(int pos, const T& elem) = 0;
        virtual int find() = 0;
        virtual void del(int pos) = 0;
        virtual void clear() = 0;
};

#endif // ADT_LINKED_LIST_HPP