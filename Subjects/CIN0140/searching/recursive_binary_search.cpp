#include <iostream>
#include <vector>

#define endl '\n'
using namespace std;


int recursive_binary_search(vector<int>&v, int l, int r, int k) {
    if (l > r) return -1;

    int m = (l + r) / 2;

    if (v[m] == k) return m;
    else if (v[m] > k) return recursive_binary_search(v, l, m - 1, k);
    else if (v[m] < k) return recursive_binary_search(v, m + 1, r, k);
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);


    vector<int> v = {1, 2, 3, 4, 5};

    int val = 3;
    int index = recursive_binary_search(v, 0, v.size() - 1, val);
    if (index != -1) {
        cout << "Value " << val << " found at index: " << index << endl;
    } else {
        cout << "Value " << val << " not found in the vector." << endl;
    }
    
    return 0;
}