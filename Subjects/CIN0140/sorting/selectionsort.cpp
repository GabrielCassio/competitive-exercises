#include <iostream>
#include <vector>

#define endl '\n'
using namespace std;

void selectionsort(vector<int>& vec, int n) {

    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i + 1; j <= n - 1; j++) {
            if (vec[j] < vec[min]) {
                min = j;
            }
        }
        swap(vec[i], vec[min]);
    }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    return 0;
}