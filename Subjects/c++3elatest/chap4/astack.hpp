#pragma once
#include "stack.hpp"

template <typename E>
class AStack : public Stack<E> {
    private:
        int max_size;
        int size_stack;
        int top_pos;
        E* stack_list;

    public:
        AStack(int size) : max_size(size) {
            top_pos = size_stack = 0;
            stack_list = new E[size];
        };
        ~AStack() { delete[] stack; };

        void clear(void) { 
            top_pos = size_stack = 0;
            delete [] stack_list;
            stack_list = new E[max_size];
        }

        void push(const E& elem){
            if (size_stack == max_size) return;
            stack_list[top_pos++] = elem;
            size_stack++;
            return;
        }
        E pop(void){ 
            size_stack--;
            return stack_list[--top_pos]; 
        }
        const E& top_value(void) { return stack_list[top_pos - 1]; }
        int length() { return size_stack; }
        bool is_empty() { return (size_stack == 0);}
};