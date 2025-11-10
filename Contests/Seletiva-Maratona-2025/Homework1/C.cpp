#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
using vi = vector<int>;
using vll = vector<long long>;

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(0); 

    int t; cin >> t;
    while (t--){
        // Num of months | Num of clients
        int n, m; cin >> n >> m;
        vi daysOfMonth(n, 0);
        vll sumDays(n + 1, 0);
        for (int i = 0; i < n; i++) {
            cin >> daysOfMonth[i];
            //sumDays[i + 1] = sumDays[i] + daysOfMonth[i]; 
        }
        for (int i = 0; i < n; i++){
            sumDays[i + 1] = sumDays[i] + daysOfMonth[i]; 
        }

        for (int i = 0; i < m; i++){
            int sd, sm, ed, em; cin >> sd >> sm >> ed >> em;
            if ((em < sm) || ((em == sm) && (sd > ed))) {
                cout << (abs(sumDays[em - 1] + sumDays[n] - sumDays[sm - 1]) + ed - sd + 1) << endl;
            }
            else {
                cout << (abs(sumDays[em - 1] - sumDays[sm - 1]) + ed - sd + 1) << endl;
            }
        }   
    } 

    return 0;
}