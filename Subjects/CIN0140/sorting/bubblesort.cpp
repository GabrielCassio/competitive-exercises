#include <iostream>
#include <vector>

#define endl '\n'
using namespace std;


void bubblesort(vector<int>& vec, int n) {
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 2 - i; j++) {
            if (vec[j + 1] < vec[j]) {
                swap(vec[j + 1], vec[j]);
            }
        }
    }

    return;
}

void bubblesort_otimized(vector<int>& vec, int n) {
    for (int i = 0; i < n; i++) {
        bool exchange = false;
        for (int j = 0; j < n - 2 - i; j++) {
            if (vec[j + 1] < vec[j]) {
                swap(vec[j + 1], vec[j]);
                exchange = true;
            }
        }
        if (!exchange) break;
    }
    
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> list = {8, 2, 1, 5, 6};
    


    return 0;
}