#ifndef STACK_HPP
#define STACK_HPP

template <typename T>
class Stack {
    private:
        T* stack;
        int top;
        int max_length;
    public:
        Stack(int size) : max_length(size), top(-1) {
            stack = new T[size];
        }
        ~Stack() {
            delete[] stack;
        }
        inline bool stack_empty() {
            return (top == -1);
        }
        inline void push(const T& elem) {
            stack[++top] = elem;
            return;
        }
        inline const T& pop() {
            if (stack_empty()) return;
            return stack[top--];
        }
};

#endif // STACK_HPP