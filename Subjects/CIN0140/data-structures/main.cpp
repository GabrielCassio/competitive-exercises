#include "vector/vector.hpp"
#include "vector/singly_linked_list.hpp"
#include "queue/queue.hpp"
#include <string>

int main() {
    // Queue Test ===========================================
    Queue<int>* fila = new Queue<int>(5);
    // fila->enqueue(1);
    // fila->enqueue(2);
    // fila->enqueue(3);
    // fila->enqueue(4);
    // fila->enqueue(5);
    fila->dequeue();
    fila->print();

    // Simple Linked List Test ================================
    // SinglyLinkedList<int>* listinha_ligada = new SinglyLinkedList<int>;
    // listinha_ligada->append(1);
    // listinha_ligada->append(2);
    // listinha_ligada->append(3);
    // listinha_ligada->append(4);
    // listinha_ligada->append(5);
    // listinha_ligada->print();
    // listinha_ligada->insert(10, 4);
    // listinha_ligada->del(2);
    // listinha_ligada->print();
    // listinha_ligada->del(4);
    // listinha_ligada->print();
    // // listinha_ligada->get_head();
    // listinha_ligada->print();

 
    // Vector Teste ===========================================
    // Vector<std::string>* lista = new Vector<std::string>(10);
    // lista->append("Olá");
    // lista->append("mundo!");

    // lista->insert(1, "meu");

    // lista->print();
    return 0;
}