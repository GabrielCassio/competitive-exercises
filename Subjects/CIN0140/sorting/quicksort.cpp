#include <iostream>
#include <vector>
#include <cmath>

#define endl '\n'
using namespace std;

int hoare_partition(vector<int>& vec, int l, int r);

void quicksort(vector<int>& vec, int l, int r) {
    
    if (l < r) {
        int s = hoare_partition(vec, l, r);
        quicksort(vec, l, s);
        quicksort(vec, s + 1, r);
    }

    return;
}

int hoare_partition (vector<int>& vec, int l, int r) {
    int p = vec[l];
    int i = l - 1;
    int j = r + 1;

    while (i < j) {
        i++;
        while (vec[i] < p) i++;
        j--;
        while (vec[j] > p) j--;

        if (i < j) swap(vec[i], vec[j]);
    }

    swap(vec[l], vec[j]);

    return j;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> list = {8, 1, 4, 7, 2};

    quicksort(list, 0, list.size() - 1);

    for (auto &a: list) {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}