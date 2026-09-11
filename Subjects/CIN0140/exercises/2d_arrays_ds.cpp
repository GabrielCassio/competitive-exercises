#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'
using namespace std;
using vvi = vector<vector<int>>;
using vi = vector<int>;


int hourglassSum(vvi arr) {
    int n = arr.size();
    vi sums(0);
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            sums.push_back(arr[i][j] + arr[i-1][j] + arr[i + 1][j] + arr[i - 1][j - 1] + arr[i + 1][j - 1] + arr[i - 1][j + 1] + arr[i + 1][j + 1]);
        }
    }

    return *max_element(sums.begin(), sums.end());
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vvi test_arr = {
        {-9, -9, -9,  1, 1, 1},
        { 0, -9,  0,  4, 3, 2},
        {-9, -9, -9,  1, 2, 3},
        { 0,  0,  8,  6, 6, 0},
        { 0,  0,  0, -2, 0, 0},
        { 0,  0,  1,  2, 4, 0}
        // {1, 1, 1, 0, 0, 0},
        // {0, 1, 0, 0, 0, 0},
        // {1, 1, 1, 0, 0, 0},
        // {0, 0, 2, 4, 4, 0},
        // {0, 0, 0, 2, 0, 0},
        // {0, 0, 1, 2, 4, 0}
    };

    int result = hourglassSum(test_arr);
    cout << result << endl;


    return 0;
}