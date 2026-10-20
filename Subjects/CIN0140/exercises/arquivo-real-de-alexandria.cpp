#include <iostream>
#include <vector>
#include <string>

#define endl '\n'
using namespace std;

const int MAXN = 40005;
int K[MAXN][3], C[MAXN][4], n[MAXN];
int cnt = 0, root = 0;

int newNode() {
    ++cnt;
    n[cnt] = 0;
    return cnt;
}

int split(int c, int &m) {
    int r = newNode();
    K[r][0] = K[c][2];
    n[r] = 1;
    C[r][0] = C[c][2];
    C[r][1] = C[c][3];
    m = K[c][1];
    n[c] = 1;
    C[c][2] = C[c][3] = 0;
    return r;
}

bool insert(int t, int x) {
    if (!C[t][0]) {
        int i = n[t];
        while (i > 0 && K[t][i - 1] > x) {
            K[t][i] = K[t][i - 1];
            i--;
        }
        K[t][i] = x; 
        n[t]++;
        return n[t] == 3;
    }
    int i = 0;
    while (i < n[t] && x > K[t][i]) i++;
    if (insert(C[t][i], x)) {
        int m;
        int r = split(C[t][i], m);
        for (int j = n[t]; j > i; j--) K[t][j] = K[t][j - 1];
        for (int j = n[t] + 1; j > i + 1; j--) C[t][j] = C[t][j - 1];
        K[t][i] = m;
        C[t][i + 1] = r;
        n[t]++;
        return n[t] == 3;
    }
    return false;
}

bool find(int x, vector<int> &path) {
    int t = root;
    while (t) {
        for (int i = 0; i < n[t]; i++) path.push_back(K[t][i]);
        int i = 0;
        while (i < n[t] && x > K[t][i]) i++;
        if (i < n[t] && K[t][i] == x) return true;
        t = C[t][i];
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    string out;
    while (q--) {
        int t, x;
        cin >> t >> x;
        vector<int> path;
        bool f = find(x, path);
        if (t == 1) {
            if (f) continue;
            if (!root) {
                root = newNode();
                K[root][0] = x;
                n[root] = 1;
                continue;
            }
            if (insert(root, x)) {
                int m;
                int r = split(root, m);
                int nr = newNode();
                K[nr][0] = m;
                n[nr] = 1;
                C[nr][0] = root;
                C[nr][1] = r;
                root = nr;
            }
        } else {
            if (!f) {
                out += "-1\n";
            } else {
                for (int i = 0; i < path.size(); i++) {
                    if (i) out += ' ';
                    out += to_string(path[i]);
                }
                out += '\n';
            }
        }
    }
    cout << out;
    return 0;
}