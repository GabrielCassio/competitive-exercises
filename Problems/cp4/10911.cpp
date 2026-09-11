#include <bits/stdc++.h>

#define endl '\n'
#define vArrI vector<int[2]>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vArrI houses_list(n);

    for (int j = 0; j < n; j++) {
        int x, y; cin >> x >> y;
        houses_list[j][0] = x; houses_list[j][1] = y;
    }


    
    for (int i = 0; i < n; i++){
        cout << "Casa de numero: " << i + 1 << "º" << endl;
        cout << "X: " << houses_list[i][0] << endl << "Y: " << houses_list[i][1] << endl;
    }

    double minor_cost = 10.0;
    cout << minor_cost;
    return 0;

    /**
     * Agrupar 2N estuddantes em N pares
     * distancia entre a casa de 2 estudantes em um grupo i
     * custo minimo (lembro de derivar)
     */
}