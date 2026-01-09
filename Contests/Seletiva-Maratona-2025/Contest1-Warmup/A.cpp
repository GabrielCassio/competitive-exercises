#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){
    ios::sync_with_stdio(false); // Desativando sicronização buffer sync
    cin.tie(0);

    int t;
    cin >> t;

    while (t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        
        bool suspcious = false;

        string letters;
        for (int i = 0; i < n; i++){
            if (s[i] != s[i+1]){
                auto finded = letters.find(s[i+1]);
                if (finded == string::npos){
                    letters += s[i];
                }
                else{
                    suspcious = true;
                    break;
                }
            }
        }

        if (suspcious){cout << "NO\n";}
        else{cout << "YES\n";}
    }
    return 0;
}