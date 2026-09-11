#pragma once
template <typename E>
class Stack {
    private:
        void operator = (const Stack&) {}
        Stack(const Stack&) {}

    public:
        Stack() {}
        virtual ~Stack() {}

        virtual void clear(void) = 0;
        virtual void push(const E& elem) = 0;
        virtual E pop(void) = 0;
        virtual const E& top_value(void) = 0;
        void int length(void) = 0;
};