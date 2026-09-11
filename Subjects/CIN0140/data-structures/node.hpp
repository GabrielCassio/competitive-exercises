#ifndef NODE_HPP
#define NODE_HPP

template<typename T>
class Node {
    public: 
        T data;
        Node* next;
        Node* previous;

        Node(const T& data, Node* next_node = nullptr, Node* previous_node = nullptr) : data(data), next(next_node), previous(previous_node)  {}
        Node( Node* next_node = nullptr, Node* previous_node = nullptr) : data(T{}), next(next_node), previous(previous_node) {}
};


#endif