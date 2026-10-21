#include <iostream>
#include <vector>

#define endl '\n'
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> arr(n);
    for (int &v : arr) cin >> v;
    int x; cin >> x;

    int low = 0, high = n - 1;
    while (low <= high && x >= arr[low] && x <= arr[high]) {
        if (arr[low] == arr[high]) {
            if (arr[low] == x) {
                cout << low << endl;
                return 0;
            }
            break;
        }
        int pos = low + (long long)(x - arr[low]) * (high - low) / (arr[high] - arr[low]);
        if (arr[pos] == x) {
            cout << pos << endl;
            return 0;
        }
        if (arr[pos] < x) low = pos + 1;
        else high = pos - 1;
    }

    if (low <= high && x > arr[high]) cout << high + 1 << endl;
    else cout << low << endl;
    return 0;
}