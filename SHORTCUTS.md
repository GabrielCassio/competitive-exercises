// Shortcuts for "common" constants
const int INF = 1e9;                    // 10^9 = 1B is < 2^31-1
const int LLINF = 4e    18;                 // 4*10^18 is < 2^63-1
const double EPS = 1e-9;                // a very small number
++i;                                    // to simplify: i = i+1;
ans = a ? b : c;                        // ternary operator
ans += val;                             // from ans = ans+val;
index = (index+1) % n;                  // to right or back to 0
index = (index+n-1) % n;                // to left or back to n-1
int ans = (int)((double)d + 0.5);       // for rounding
ans = min(ans, new_computation);        // min/max shortcut

// some code use short circuit && (AND) and || (OR)
// some code use structured bindings of C++17 for dealing with pairs/tuples
// we don’t use braces for 1 liner selection/repetition body
// we use pass by reference (&) as far as possible