#pragma once
template <typename E>
class Queue {
    private:
        void operator = (const Queue&) {}
        Queue(const Queue&) {}

    public:
        Queue() {}
        virtual ~Queue() {}

        virtual void clear(void) = 0;
        virtual void enqueue(const E& elem) = 0;
        virtual E dequeue(void) = 0;
        virtual E front_value(void) = 0;
        virtual int length(void) = 0;

};