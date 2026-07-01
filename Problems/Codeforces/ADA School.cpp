#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(0); 

    // test cases
    int t = 0; cin >> t;
    while(t--){
        // length of the classroom
        int m = 0; int n = 0; cin >> n >> m;
        
        if (((m % 2 != 0) & (n % 2 != 0))){
            cout << "NO" << "\n";
        }
        else{
            cout << "YES" << "\n";
        }
    }

    return 0;
}