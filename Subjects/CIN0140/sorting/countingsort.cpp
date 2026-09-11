#include <iostream>
#include <vector>

#define endl '\n'
using namespace std;


void countingsort(vector<int>& vec, vector<int>& res, int k, int n) {
    vector<int> counter(k, 0);

    for (int i = 0; i <= n - 1; i++) counter[vec[i]]++;
    
    for (int j = 1; j <= k; j++) counter[j] = counter[j] + counter[j - 1];

    for (int p = n - 1; p >= 0; p--) {
        res[counter[vec[p] - 1]] = vec[p];
        counter[vec[p]] = counter[vec[p]] - 1;
    }
    
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}