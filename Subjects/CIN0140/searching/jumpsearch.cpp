#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define endl '\n'
using namespace std;

int jump_search(vector<int>&v, int n, int k) {
    int m = sqrt(n);
    int prev = 0;
    int step = m;
    while (v[min_element(step, n) - 1] < k) {
        prev = step;
        step += m;
        if (prev >= n) return -1;
    }

    while(v[prev] < k) {
        prev++;
        if (prev == min_element(step, n)) return -1;
    }

    if (v[prev] == k) return prev;
    return -1;
}


int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> v = {1, 2, 3, 4, 5};

    int val = 3;
    int index = jump_search(v, v.size(), val);
    if (index != -1) {
        cout << "Value " << val << " found at index: " << index << endl;
    } else {
        cout << "Value " << val << " not found in the vector." << endl;
    }

    return 0;
}