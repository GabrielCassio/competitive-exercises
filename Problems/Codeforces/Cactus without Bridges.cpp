#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

using vi = vector<int>;

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);
    
    int n = 0; int m = 0; // n - num of vertices, m - num of edges
    cin >> n >> m;

    // Verify the parity of the graph
    if (n % 2 != 0){
        cout << "NO";
    }
    else{
        vi sequence(); // Create a empty vector to keep the sequence of numbers
        while(m--){
            int v = 0; int u = 0;   
            cin >> v >> u;

            // Verify the difference by each vertex
            if (abs(v - u) > 1){
                cout << "NO";
                return 0;
            }
            else{
                

            }
        }
    }

    return 0;
}