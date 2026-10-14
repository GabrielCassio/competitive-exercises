#include <iostream>
#include <vector>

#define endl '\n'
using namespace std;


void build_max_heap(vector<int>& arr, int n) {
    return ;
}

void max_heapify(vector<int>& arr, int i, int l_heap) {
    return ;
}


void heapsort(vector<int>& arr) {
    int n = arr.size();

    if (n <= 1) return;

    build_max_heap(arr, n);

    int len_heap = n;
    int  i = n - 1;

    while (i >= 1) {
        swap(arr[0], arr[i]);
        len_heap--;
        
        max_heapify(arr, 0, len_heap);

        i--;
    }

    return;
}

int main() {
    return 0;
}
