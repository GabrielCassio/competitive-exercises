#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'
using namespace std;

int fibonacci_search(vector<int>& v, int n, int k) {

    int fib2 = 0;
    int fib1 = 1;
    int fib = fib1 + fib2;

    while ( fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }

    int offset = -1;
    while (fib > 1) {
        int i = min_element(offset + fib2, n - 1);

        if (v[i] < k) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        } else if (v[i] > k) {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        } else {
            return i;
        }
    }

    if ((fib1 == 1) && (offset + 1 < n) && (v[offset + 1] == k)) return offset + 1;

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> v = {1, 2, 3, 4, 5};

    int val = 3;
    int index  = fibonacci_search(v, v.size(), val);
    if (index != -1) {
        cout << "Value " << val << " found at index: " << index << endl;
    } else {
        cout << "Value " << val << " not found in the vector." << endl;
    }

    return 0;
}