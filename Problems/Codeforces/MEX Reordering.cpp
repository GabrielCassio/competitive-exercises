#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; // Length of the vector a
    cin >> n;
    vector<int> a(n); // declaring vector a
    for(auto &i : a) { // For each element of the vector a, insert thorught the pointer the respective value
        cin >> i;
    }

    vector<int> rptNum(n + 1); // Declaring vector of numbers in repetition
    for(auto i : a) rptNum[i]++;
    // for rptNum[0] = 1 -> Num of zeros equals 1

    if(rptNum[0] == 0) cout << "NO\n"; // If not exists zeros in the vector
    else if(rptNum[1] > 0) cout << "YES\n"; 
    else cout << (rptNum[0] == 1? "YES" : "NO") << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}