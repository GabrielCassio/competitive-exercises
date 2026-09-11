#include <iostream>
#include <vector>

#define endl '\n'
using namespace std;

vector<int> rotateLeft(int d, vector<int> arr)  {

    
    // int n = arr.size();
    // d %= n;
    // cout << d << endl;
    // vector<int> new_vec(n, 0);
    // for(int i = 0; i < n; i++) {
    //     new_vec[i] = arr[(i + d) % n];
    // }
    // return new_vec;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> v = {1, 2, 3, 4, 5};
    rotateLeft(4, v);

    return 0;
}