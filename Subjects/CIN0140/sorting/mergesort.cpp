#include <iostream>
#include <vector>

#define endl '\n'
using namespace std;

void merge(vector<int>& v, vector<int>& v2, int p, vector<int>& v3, int q);

void mergesort(vector<int>& vec, int n) {

    if (n > 1) {
        int mid = n / 2;
        vector<int> vec2(vec.begin(), vec.begin()+ mid);
        vector<int> vec3(vec.begin() + mid, vec.end());

        mergesort(vec2, mid);
        mergesort(vec3, vec3.size());
        merge(vec, vec2, vec2.size(), vec3, vec3.size());
    }
    return;
}

void merge(vector<int>& v, vector<int>& v2, int p, vector<int>& v3, int q) {
    int i = 0; int j = 0; int k = 0;

    while ((i < p) && (j < q)) {
        if (v2[i] <= v3[j]) {
            v[k] = v2[i];
            i++;
        } else {
            v[k] = v3[j];
            j++;
        }
        k++;
    }

    while (i < p) { v[k] = v2[i]; i++; k++; }
    while (j < q) { v[k] = v3[j]; j++; k++; }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> list = {8, 1, 4, 7, 2};

    mergesort(list, list.size());  

    for (auto &a: list) {
        cout << a << " ";
    }
    cout << endl;


    return 0;
}