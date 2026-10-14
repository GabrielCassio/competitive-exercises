#include <iostream>
#include <vector>

#define endl '\n'
using namespace std;

/**
 * Melhor caso: elemento está no meio O(1).
 * Pior caso: log(n) comparações.
 * Complexidade: Θ(log(n)).
 */
int binary_search(vector<int>& v, int n, int k) {
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (v[mid] == k) {
            return mid;
        } else if (v[mid] < k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> v = {1, 2, 3, 4, 5};

    int val = 3;
    int index = binary_search(v, v.size(), val);
    if (index != -1) {
        cout << "Value " << val << " found at index: " << index << endl;
    } else {
        cout << "Value " << val << " not found in the vector." << endl;
    }


    return 0;
}