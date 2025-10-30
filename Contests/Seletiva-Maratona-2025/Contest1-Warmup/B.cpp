#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){
    ios::sync_with_stdio(false); // Desativando sicronização buffer sync
    cin.tie(0); // Desativando sicronização buffer sync

    int t;
    cin >> t;

    while (t--){
        int a, b;
        cin >> a >> b;

        if (a > b){
            if (a%2 != b%2){cout << "2\n";}
            else {cout << "1\n";}
        }
        else if (a < b){
            if (a%2 != b%2){cout << "1\n";}
            else {cout << "2\n";}
        }
        else {cout << "0\n";}
    }
    return 0;
}