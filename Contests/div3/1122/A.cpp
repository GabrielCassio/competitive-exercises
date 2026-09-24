#include <bits/stdc++.h>


#define endl '\n'
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;

        vector<int> a (3, 0);
        cin >> a[0] >> a[1] >> a[2];
        cout << n - *min_element(a.begin(), a.end()) <<  endl;
    }

    return 0;
}