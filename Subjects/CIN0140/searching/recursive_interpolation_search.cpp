#include <iostream>
#include <vector>

#define endl '\n'
using namespace std;

int recursive_interpolation_search(vector<int>& v, int l, int r, int k) {
    if ((l > r) || (k < v[l]) || (k > v[r]))  return -1;

    if (v[l] == v[r]) {
        if (v[l] == k) return l;
        else return -1;
    }

    int x = l + ((double)(r - l)  / (v[r] - v[l])) * (k - v[l]);
    if(v[x] == k) return x;
    else if (v[x] < k) return recursive_interpolation_search(v, x + 1, r, l);
    else return recursive_interpolation_search(v, l, x - 1, k);

    return -1;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> v = {1, 2, 3, 4, 5};

    int val = 3;
    int index = recursive_interpolation_search(v, 0, v.size(), val);
    if (index != -1) {
        cout << "Value " << val << " found at index: " << index << endl;
    } else {
        cout << "Value " << val << " not found in the vector." << endl;
    }

    return 0;
}