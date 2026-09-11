/**
 * O objetivo da questão é implementar um algoritmo de prefix sum para substituir
 * um intervalo do array por um vetor de valores iguais a k.
 */

#include <iostream>
#include <vector>
#include <numeric>

#define endl '\n'

using namespace std;
using vi = vector<int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n, q; cin >> n >> q;

        vi arr(n, 0);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        vi prefix_sum(n + 1, 0);
        for (int i = 1; i <= n; i++)
            prefix_sum[i] = prefix_sum[i - 1] + arr[i - 1];

        while (q--) {
            int l, r, k; cin >> l >> r >> k;
            int final_sum = prefix_sum[n] + (prefix_sum[r] - prefix_sum[l - 1]) + (r - l + 1) * k;
            (final_sum % 2 == 0) ? cout << "NO" << endl : cout << "YES" << endl;
        }
    }
    return 0;
}