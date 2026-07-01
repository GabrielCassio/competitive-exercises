#pragma once

#define DEFAULT_LIST_SIZE 1

template <typename E>
class AList {
    private:
        int max_size;
        int list_size;
        int curr_pos;
        E* list_arr;

        void extend_list (){
            E* temp_arr = list_arr;
            max_size *= 2;
            delete [] list_arr;
            list_arr = new E[max_size];

            // Copy to new vector
            for (int i = 0; i < list_size; i++) list_arr[i] = temp_arr[i];
            delete [] temp_arr;
        }
        
    public:
        AList(int size = DEFAULT_LIST_SIZE) : max_size(2 * size) {
            list_size =  curr_pos = 0;
            list_arr = new E[max_size];
        }
        ~AList() { delete [] list_arr; }

        void clear() {
            list_size = curr_pos = 0;
            delete [] list_arr;
            list_arr = new E[max_size];
        }
        void append(const E& elem) {
            std::cout << "Tamanho máximo da lista: " << max_size << std::endl;
            if (list_size >= max_size) {
                extend_list();
                std::cout << "Novo tamanho máximo da lista: " << max_size << std::endl;
            }
            
        }
        void insert(int pos) {
            if (list_size >= max_size) extend_list();

            for (int i = 0; i < list_size; i++){
                
            }
        }
        void remove () {}
        E& pop () {
            return 
        }
};