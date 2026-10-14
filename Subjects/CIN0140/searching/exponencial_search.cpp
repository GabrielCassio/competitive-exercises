#include <iostream>
#include <vector>
#include <algorithm>


#define endl '\n'
using namespace std;

int exponencial_search(vector<int>&v, int n, int k) {
    if (n == 0) return -1;
    if (v[0] == k) return 0;

    int i = 0;
    while (i < n && v[i] <= k) i *= 2;

    int l = i / 2;
    int r = min_element(i, n - 1);

    while (l <= r) {
        int m = (l + r) / 2;
        if (k == v[m]) return m;
        else if (k < v[m]) r = m - 1;
        else l = m + 1;
    }
    return -1;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> v = {1, 2, 3, 4, 5};

    int val = 3;
    int index = exponencial_search(v, v.size(), val);
    if (index != -1) {
        cout << "Value " << val << " found at index: " << index << endl;
    } else {
        cout << "Value " << val << " not found in the vector." << endl;
    }

    return 0;
}