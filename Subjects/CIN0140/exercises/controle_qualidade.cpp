#include <iostream>
#include <vector>

#define endl '\n'
using namespace std;

vector<int> coutingsort(vector<int>& arr, int max) {
    int n = arr.size();

    vector<int> cnt_arr(max + 2, 0);
\
    for (int i = 0; i < n; i++) cnt_arr[arr[i]]++;

    for (int j = 1; j < max + 2; j++) cnt_arr[j] = cnt_arr[j] + cnt_arr[j - 1];

    vector<int> res (n, 0);

    for (int k = n - 1; k >= 0; k--) {
        res[cnt_arr[arr[k]] - 1] = arr[k];
        cnt_arr[arr[k]]--;
    }

    arr = res;

    return cnt_arr;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> v = coutingsort(a, k);

    for (int h = 1; h < k + 2; h++) cout << v[h] << " ";
    cout << endl;

    for (auto& i: a) cout << i << " ";
    cout << endl;

    return 0;
}