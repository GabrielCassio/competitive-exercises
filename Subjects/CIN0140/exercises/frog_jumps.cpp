/**
 * Calcular o valor mínimo possível de d
 */

#include <iostream>
#include <string>
#include <vector>

#define endl '\n'
using namespace std;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vi vec(100);
    /**
     * 6
        LRLRRLL
        gap = 2
        last = 1
        gap = 2
        last = 3
        gap = 1
        last = 4
        gap = 3
        last = n

        L
        LLR
        RRRR
        LLLLLL
        R
        n + 2
     */
    int t = 0; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.size();
        int last = 0;
        int gap = 0;

        for (int i = 0; i <= n - 1; i++){
            if (s[i] == 'R' ) {
                gap = max(gap, i - last + 1); 
                /**Pegando a maior diferença entre o pulo anterior e o pulo atual com base na posição
                 * anterior (o +1 normaliza o loop)
                */
                last = i + 1;
            } 
        }
        gap = max(gap, (n+1) - last);
        
        cout << gap << endl;
    }

    return 0;
}