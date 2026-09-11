#include <vector>
#include <random>
#include <iostream>

using namespace std;

const char* reservoir_sampling (int n, const char* arr) {
    vector<char> reservoir;
    vector<char*> indexes;
    int t = 0; int m = 0;

    while ( *arr != 0 ) {
        int k = rand() % (t + 1);
        if (k <= n) {
            reservoir.push_back(*arr);
            indexes[k] = &reservoir.back();
        }
        
        arr++;
    }
    return indexes[0];
}

int main () {

    const char* arr = new char[5]{'A', 'B', 'C', 'D', 'E'};
    const char* result = reservoir_sampling(2, arr);
    while (result) {
        cout << *result << endl;
        result++;
    }
    
    return 0;
}