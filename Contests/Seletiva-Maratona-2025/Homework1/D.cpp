#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

using vi3 = vector<vector<vector<int>>>;
using vi2 = vector<vector<int>>;
using vi = vector<int>;

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(0); 

    int n, m, q;
    cin >> n >> m >> q;
    vi statsNumBooks(q + 1, 0);
    vi2 bookCase(n, vi(m, 0));
    // statsBookCase;

    int numBooks = 0;
    while (q--)
    {   
        //statsBookCase.push_back(bookCase);
        int op = 0; cin >> op;
        int row = 0, col = 0;
        switch (op){
            case 1:
                cin >> row >> col; 
                if (bookCase[row - 1][col - 1] == 0) {
                    numBooks ++;
                    bookCase[row - 1][col - 1] = 1;
                }
                break;

            case 2:
                cin >> row >> col;
                if (bookCase[row - 1][col - 1] == 1) {
                    numBooks --;
                    bookCase[row - 1][col - 1] = 0;
                }

                break;
            
            case 3:
                cin >> row;
                for (int j = 0; j < m; j++) {
                    if (bookCase[row - 1][j]) numBooks --;
                    else numBooks ++;
                    bookCase[row - 1][j] = !bookCase[row - 1][j];
                }
                break;
            
            case 4:
                int k; cin >> k;
                numBooks = statsNumBooks[k];
                //bookCase = statsBookCase[k];
                break;
        }
        statsNumBooks[statsNumBooks.size() - q - 1] = numBooks;
        cout << numBooks << endl;
    }
    
    return 0;
}