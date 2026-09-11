#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

int main () {
    int n, count = 0; cin >> n;
    while (n--) {
        bool a; bool b; bool c;
        cin >> a >> b >> c;

        if (a && b || a && c || b && c) {
            count++;
        }
        
    }
    cout << count << endl;
}