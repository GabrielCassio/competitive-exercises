#include <iostream>
#include <vector>

using namespace std;

int main () {

    int t; cin >> t;

    while(t--){
        int n; cin >> n;
        vector<int> vec_in, vec_out;
        
        for (size_t i = 0; i < n; i++) {
            int x; cin >> x;
            vec_in.push_back(x);
        }
        
        for (size_t i = 0; i < n; i++) {
            int x; cin >> x;
            vec_out.push_back(x);
        }

        if (vec_in[0] == vec_out[0] && vec_in[n-1] == vec_out[n-1] && vec_in[0] == vec_out[n-1]) {
            cout << "both" << endl;
        } else if (vec_in[0] == vec_out[0]  && vec_in[n-1] == vec_out[n-1]) {
            cout << "queue" << endl;
        } else if (vec_in[0] == vec_out[n-1] && vec_in[n-1] == vec_out[0]) {
            cout << "stack" << endl;
        } else {
            cout << "neither" << endl;
        }

    }
    
    return 0;
}