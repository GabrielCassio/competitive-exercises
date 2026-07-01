#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

using vec_2d_int = vector<vector<int>>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int m, n; // rows, cols
  cin >> m >> n;

  int k, st; // people, stamina for each person
  cin >> k;
  while (k--) {
    cin >> st;
  }
  vec_2d_int coord_seats = vec_2d_int(m, vector<int>(n));

  return 0;
}
