#include <iostream>
#include <vector>

#define endl '\n'
using namespace std;

void insertionsort(vector<int>& vec, int n) {
    for (int i = 0; i <= n -1; i++) {
        int v = vec[i];
        int j = i;
        while((j >= 1) && (vec[j - 1] > v)) {
            vec[j] = vec[j - 1];
            j--;
        }
        vec[j] = v;
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    return 0;
}