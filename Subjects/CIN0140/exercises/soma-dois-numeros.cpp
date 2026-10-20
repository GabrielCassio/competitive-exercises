#include <iostream>
#include <string>

#define endl '\n'
using namespace std;

const int MAXN = 200005;
int a[MAXN];

void heapify(int n, int i) {
    while (true) {
        int left = 2 * i + 1; int right = 2 * i + 2; int mid = i;
        if (left < n && a[left] > a[mid]) mid = left;
        if (right < n && a[right] > a[mid]) mid = right;
        if (mid == i) break;
        swap(a[i], a[mid]);
        i = mid;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = n / 2 - 1; i >= 0; i--) heapify(n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(i, 0);
    }

    string out;
    for (int i = 0; i < n; i++) {
        if (i) out += ' ';
        out += to_string(a[i]);
    }
    out += '\n';
    cout << out;
    return 0;
}