#include "alist.hpp"
#include "llist.hpp"
#include "aqueue.hpp"
// #include <iostream>

int main () {

    LList<int> lista(10);

    for (int i = 0; i < 10; i++){
        lista.append(i);
        lista.print_elements();
    }

    return 0;
}