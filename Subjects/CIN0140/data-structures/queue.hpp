#ifndef QUEUE_HPP
#define QUEUE_HPP

template <typename T>
class Queue {
    private:
        int start;
        int end;
        int max_size;
        T* queue_list;

    public:

    inline void print() {
        for (int i = start; i < end; i++) {
            std::cout << queue_list[i] << (i+1 == end ? "" : ", ");
        }
        std::cout << std::endl;
    }

    Queue (int size) : max_size(size) {
        queue_list = new T[size];
        start = end = 0;
    }
    ~Queue () {
        delete[] queue_list;
    }

    inline void enqueue(const T& elem) {
        if (start == 0 && end == max_size - 1) {
            std::cout << "Queue is full!" << std::endl;
            return;
        }
        queue_list[end] = elem;
        if (end == max_size - 1) {
            end = 0;
        } else {
            end++;
        }

        return;
    }
    inline T dequeue() {
        if (start == end) {
            std::cout << "Queue is empty!" << std::endl;
            return T{};
        }
        T elem = queue_list[start];
        if (start == max_size - 1) {
            start = 0;
        } else {
            start++;
        }
        return elem;
    }
};

#endif // QUEUE_HPP