#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'
using namespace std;

void countingsort(vector<int>& vec, vector<int>& res, int k, int n) {
    vector<int> counter(k, 0);

    for (int i = 0; i <= n - 1; i++) counter[vec[i]]++;
    
    for (int j = 1; j <= k - 1; j++) counter[j] = counter[j] + counter[j - 1];

    for (int p = n - 1; p >= 0; p--) {
        res[counter[vec[p]] - 1] = vec[p];
        counter[vec[p]]--;
    }
    
    return;
}

vector<int>& coutingsort(vector<int>& arr) {
    int n = arr.size();

    vector<int> cnt_arr(n+1, 0);

    for (int i = 0; i < n; i++) cnt_arr[arr[i]]++; // Dado valor vec[i] mapea contagens

    for (int j = 1; j < n + 1; j++) cnt_arr[j] = cnt_arr[j] + cnt_arr[j - 1];

    vector<int> res (n, 0);

    for (int k = n - 1; k >= 0; k--) {
        res[cnt_arr[res[k]] - 1] = res[k];
        // cnt_arr[res[k]]--;
    }

    return cnt_arr;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> list = {8, 1, 4, 7, 2};
    int n = list.size();
    int maxVal = *max_element(list.begin(), list.end());
    vector<int> result(n, 0);

    countingsort(list, result, maxVal + 1, n);

    for (auto &a: result) {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}