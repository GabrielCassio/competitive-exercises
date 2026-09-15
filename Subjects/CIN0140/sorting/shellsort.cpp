#include <iostream>
#include <vector>
#include <cmath>

#define endl '\n'
using namespace std;

void shellsort(vector<int>& vec, int n) {
    int h = floor(n/2);

    while (h >= 1) {
        for (int i = h; i <= n - 1; i++) {
            int v = vec[i];
            int j = i;
            while ((j >= h) && (vec[j - h] > v)) {
                vec[j] = vec[j - h];
                j = j - h;
            }
            vec[j] = v;
        }
        h = floor(h/2);
    }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> list = {8, 1, 4, 7, 2};

    shellsort(list, list.size());

    for (auto &a: list) {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}