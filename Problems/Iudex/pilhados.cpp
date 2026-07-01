#include <iostream>
#include <cmath>

#define DEFAULT_SIZE 10000

template <typename E>
class Stack {
    private:
        int max_size;
        int curr_size;
        int top_pos;
        E* stack_arr;

    public: 
        Stack(int size = DEFAULT_SIZE) : max_size(size) {
            curr_size = 0; top_pos = 1;
            stack_arr = new E[max_size];
            stack_arr[0] = -1;
        }
        ~Stack() {
            curr_size = 0; top_pos = 1;
            delete [] stack_arr;
        }

        void push(const E& elem) {
            stack_arr[top_pos++] = elem;
            curr_size++;
        }

        E pop() {
            if (top_pos == 1) return E{};
            E element = stack_arr[--top_pos];
            curr_size--;
            return element;
        }

        E top_value () { return stack_arr[top_pos - 1]; }

        int length() { return curr_size; }

        bool is_empty() { return (curr_size == 0); }

};



Stack<int>* diff (int value, Stack<int>* pilha) {

    if (!value) return pilha;

    if (pilha->is_empty()) {
        pilha->push(value);
        return pilha;
    }
    
    if (value%2 == pilha->top_value()%2) {
        int top_value = pilha->pop();
        int abs_diff = abs(value - top_value);
        return diff(abs_diff, pilha);
    }

    pilha->push(value);    
    return pilha;
}


int main () {
    int t; std::cin >> t;
    for (int i = 0; i < t; i++){
        int n;
        Stack<int>* main_stk = new Stack<int>;
        while (std::cin >> n && n != 0) {
            main_stk = diff(n, main_stk);
        }

        std::cout << "Pilha " << i+1 << ": " << main_stk->length() << " " << main_stk->top_value() << std::endl;
    }
    return 0;
}