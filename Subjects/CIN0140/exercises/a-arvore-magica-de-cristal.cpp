#include <iostream>
#include <algorithm>
#include <string>

#define endl '\n'
using namespace std;

const int MAXN = 200005;
int key[MAXN], h[MAXN], L[MAXN], R[MAXN];
int cnt = 0, root = 0, total = 0;
string out;

inline void update(int t) { 
    int range[2] = {h[L[t]], h[R[t]]};
    h[t] = 1 + *max_element(range, range+2);
}

int rotR(int y) {
    int x = L[y];
    L[y] = R[x];
    R[x] = y;
    update(y);
    update(x);
    return x;
}

int rotL(int x) {
    int y = R[x];
    R[x] = L[y];
    L[y] = x;
    update(x);
    update(y);
    return y;
}

void pre(int t, bool &first) {
    if (!t) return;
    if (!first) out += ' ';
    first = false;
    out += to_string(key[t]);
    pre(L[t], first);
    pre(R[t], first);
}

void balance(int &t) {
    update(t);
    int b = h[L[t]] - h[R[t]];
    if (b > 1 || b < -1) {
        out += to_string(b) + " " + to_string(key[t]) + "\n";
        if (b > 1) {
            if (h[L[L[t]]] < h[R[L[t]]]) L[t] = rotL(L[t]);
            t = rotR(t);
        } else {
            if (h[R[R[t]]] < h[L[R[t]]]) R[t] = rotR(R[t]);
            t = rotL(t);
        }
        total++;
        bool first = true;
        pre(root, first);
        out += '\n';
    }
}

void insert(int &t, int k) {
    if (!t) {
        t = ++cnt;
        key[t] = k;
        h[t] = 1;
        L[t] = R[t] = 0;
        return;
    }
    if (k < key[t]) insert(L[t], k);
    else insert(R[t], k);
    balance(t);
}

void remove(int &t, int k) {
    if (!t) return;
    if (k < key[t]) remove(L[t], k);
    else if (k > key[t]) remove(R[t], k);
    else {
        if (!L[t] || !R[t]) {
            t = L[t] ? L[t] : R[t];
            return;
        }
        int m = R[t];
        while (L[m]) m = L[m];
        key[t] = key[m];
        remove(R[t], key[m]);
    }
    if (t) balance(t);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    while (n--) {
        int x, y;
        cin >> x >> y;
        if (x == 1) insert(root, y);
        else remove(root, y);
    }

    cout << out;
    if (total == 0) cout << "A arvore magica cresceu perfeitamente\n";
    else cout << total << '\n';
    return 0;
}