#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> num_list(n);
        
        for (int i = 0; i < n; i++) cin >> num_list[i];

        int freq[4] {0, 0, 0, 0};
        for (auto &x: num_list) freq[x%4]++;

        cout << max({freq[0], freq[1]+freq[3], freq[2]}) << endl;
    }

    return 0;
}