#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
using vi = vector<int>;

int main(){
    ios::sync_with_stdio(false); // Desativando sicronização buffer sync
    cin.tie(0); // Desativando sicronização buffer sync

    int t;
    cin >> t;
    while (t--)
    {
        int n, num;
        cin >> n;
        
        string s;
        cin.ignore();
        getline(cin, s);
        stringstream ss(s);
        
        vi vec;
        while (ss >> num){
            vec.push_back(num);
        }

        cout << vec[0] << "\n";

    }
    return 0;
}