#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

template <typename T>
class Vector {
    private:
        T* arr = nullptr;
        int size = 0;
        int curr_pos = 0;
        int max_size = 0;

    public:
        inline Vector(int size) : size(0), curr_pos(0), max_size(size) {
            arr = new T[size];
            return;
        }

        inline ~Vector() {
            delete[] arr;
            return;
        }

        inline void insert(int pos, const T& elem) {
            if (pos < 0 || pos > max_size - 1) return;

            size++;
            for (int i = size - 1; i > pos; i--) {
                arr[i] = arr[i - 1];
            }
            arr[pos] = elem;

            return;
        }
        inline void clear() {
            delete[] arr;
            size = 0;
            curr_pos = 0;
            arr = new T[max_size];
            return;
        }
        inline void append(const T& elem) {
            arr[curr_pos++] = elem;
            size++;
            return;
        }
        inline void del(int pos) {
            if (pos < 0 || pos > max_size - 1) return;
            for (int i = pos; i < size - 1; i++) {
                arr[i] = arr[i + 1];
            }
            return;
        }
        inline void print() {
            std::cout << "[";
            for (int i = 0; i < size ; i++) {
                std::cout   << arr[i];  
                (i + 1 == size) ? std::cout << "]" : std::cout << ", ";
            }
            std::cout << std::endl;
        }
        
};


#endif // VECTOR_HPP
