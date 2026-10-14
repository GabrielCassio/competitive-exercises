#include <iostream>
#include <vector>

#define endl '\n'
using namespace std;

/**
 * Caso Médio (dados uniformes): O(log(log n)) comparações — crescimento extremamente lento.
 * Pior Caso (dados exponencialmente distribuídos): O(n) — degenera para uma busca sequencial se a estimativa errar repetidamente 
 * 
 */
int interpolation_search(vector<int>& v, int n, int k) {

    int l = 0;
    int r = n - 1;

    while ((l <= r) && (k >= v[l]) && (v[r] >= k)) {
        if (v[l] == v[r]) {
            if (v[l] == k) return l;
            else return -1;
        }

        int x = l + ((double)(r - l)  / (v[r] - v[l])) * (k - v[l]);

        if (v[x] == k) return x;
        else if (v[x] < k) l = x++;
        else r = x--;
    }
    
    return -1;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> v = {1, 2, 3, 4, 5};

    int val = 3;
    int index = interpolation_search(v, v.size(), val);
    if (index != -1) {
        cout << "Value " << val << " found at index: " << index << endl;
    } else {
        cout << "Value " << val << " not found in the vector." << endl;
    }

    return 0;
}