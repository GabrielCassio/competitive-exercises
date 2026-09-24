/**
 * Problemática: Identificar as trocas adjacentes
 */
#include <iostream>
#include <vector>


#define endl '\n'
using namespace std;


void merge(vector<int>& l, vector<int>& r, vector<int>& res, long long& exch) {
    int i = 0; int j = 0; int k = 0; // índice para nortear a varredura sobre os 3 vetores
    int ll = l.size(); int lr = r.size();// tamanho dos vetores percorridos

    while (i < ll && j < lr) {
        if (l[i] <= r[j]) {
            res[k] = l[i];
            i++; 
        } else {
            res[k] = r[j];
            j++;
            exch = exch + ll - i;
        }

        k++;
    }

    while (i < ll) {res[k] = l[i]; i++; k++;}
    while (j < lr) {res[k] = r[j]; j++; k++;}

    return;
}

void mergesort(vector<int>& vec, int n, long long& e) { //Vector reference, length of vector

    if (n > 1) {
        int mid = n/2;

        vector<int> vl(vec.begin(), vec.begin() + mid);
        vector<int> vr(vec.begin() + mid, vec.end());
 
        mergesort(vl, vl.size(), e);
        mergesort(vr, vr.size(), e);
        merge(vl, vr, vec, e);
    }

    return;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = 0; long long e = 0; cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) cin >> v[i];

    mergesort(v, v.size(), e);

    for (auto& el: v) cout << el << " ";
    cout << endl;
    cout << e << endl;

    return 0;
}