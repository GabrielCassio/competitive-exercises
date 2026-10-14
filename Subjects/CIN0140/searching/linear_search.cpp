#include <iostream>
#include <vector>

#define endl '\n'
using namespace std;

/**
 * Complexidade: Melhor O(1).
 * Médio e Pior caso Θ(n).
 */
int linear_search(vector<int>& v, int n , int k) {
    int i = 0;
    while (i < n && v[i] != k) i++;

    if (i < n) return i;
    else return -1;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> v = {1, 2, 3, 4, 5};

    int val = 3;
    int index = linear_search(v, v.size(), val);
    if (index != -1) {
        cout << "Value " << val << " found at index: " << index << endl;
    } else {
        cout << "Value " << val << " not found in the vector." << endl;
    }

    return 0;
}