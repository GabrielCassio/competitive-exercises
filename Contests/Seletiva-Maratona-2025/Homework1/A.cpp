#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
using vi = vector<int>;
using vll = vector<long long>;

int main(){
    ios::sync_with_stdio(false); // Desativando sicronização buffer sync
    cin.tie(0); // Desativando sicronização buffer sync

    int n; cin >> n;
    vi numVillagers(n), coordinates(n);
    for (int i = 0; i < n; i++) cin >> coordinates[i];
    for (int i = 0; i < n; i++) cin >> numVillagers[i];

    vll psum(n+1, 0); // psum.length = n+1
    for (int i = 0; i < n; i++) psum[i+1] = psum[i] + numVillagers[i];
    
    int q; cin >> q;
    for (int i = 0; i < q; i++){
        int l,r; cin >> l >> r;
        cout << psum[r + 1] - psum[l] << endl;
    }

    return 0;
}