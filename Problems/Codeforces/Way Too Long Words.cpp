#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = 0; cin >> n;
    while(n--){
        string word; cin >> word;
        int length = word.length(); 

        if (length > 10) cout << word[0] << length - 2 << word[length - 1] << endl;
        else cout << word << endl;
    }

    return 0;
}