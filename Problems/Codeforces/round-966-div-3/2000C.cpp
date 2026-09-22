#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    
    while (t--) {
        int n; cin >> n;
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++) cin >> a[i];

        int m; cin >> m; string s = "";
        for (int j = 0; j < m; j++) {
            map<char, int> cmp1;
            map<int, char> cmp2;
            cin >> s; int ls = s.size(); bool valid = true;

            if (ls != n) {
                cout << "NO" << endl;
                continue;
            }

            for (int k = 0; k < ls; k++) {
                if (!cmp1.count(s[k]) && !cmp2.count(a[k])) {
                    cmp1[s[k]] = a[k]; 
                    cmp2[a[k]] = s[k];
                }
                else if ((cmp1[s[k]] != a[k]) || (cmp2[a[k]] != s[k])) {
                    valid = false;
                    break;
                }
            }

            if (valid) { 
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}