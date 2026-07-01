#define DEFAULT_LIST_SIZE 0

template <typename E>
class List {
    private:
        int max_size;
        int curr_size;
        int pos;
        E* list_arr;

        Queue(const Queue&) {}

    public:
        Queue(int size = DEFAULT_LIST_SIZE) : max_size(size) {
            curr_size = pos = 0;
            list_arr = new E[size];
        }
        ~Queue() { delete [] list_arr; }


        void append(const E&) {

            
        }
        void clear() {}

};

int main(){
    return 0;
}