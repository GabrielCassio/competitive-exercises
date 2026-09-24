/**
 * Verifica a regra de assento
 */
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> seats (n, 0);
        bool valid = true;
        for (int i = 0; i < n; i++) {
            int num_seat; cin >> num_seat;

            if (!i) {
                seats[num_seat - 1] = 1;
                continue;
            }

            if (1 < num_seat && num_seat < n) {
                if (!seats[num_seat - 2] && !seats[num_seat]) valid = false; 
            } else if (num_seat == n){
                if (num_seat == n && !seats[num_seat - 2]) valid = false;
            } else if (num_seat == 1) {
                if (num_seat == 1 && !seats[num_seat]) valid = false;
            }
            seats[num_seat - 1] = 1;
        }

        if (valid) cout << "YES" << endl;
        else cout << "NO" << endl;

    }

    return 0;
}