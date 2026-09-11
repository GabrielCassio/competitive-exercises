#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

vector<int> pow_list = {1, 10, 100, 1000, 10000};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int num1, num2; cin >> num1;
        num2 = num1;
        int dec_part = 0; int qd = 0;
            
        while (num1 >= 100) {
            num1/=10; qd++;
        }

        dec_part = num2 % pow_list[qd];

        if (num1 == 10 && pow_list[qd - 1] <= dec_part && dec_part > 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}