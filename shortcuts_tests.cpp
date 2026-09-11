#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

class ShortcutsTests {
    private:
        vector<int> list();

    public:
        ShortcutsTests() {}
        ~ShortcutsTests() {}

        static inline int rounding_test (const double& valuein) {
            /**
             * This rounding line, first converts the value in a double type 
             * (grater than the float type), and return a converted number in int
             */ 
            
            int ans = (int) ((double) valuein + 0.5); 
            return ans;
        }
        // static inline int index_test (const int* list) {
        //     return 
        // }
    };


int main () {

   cout << ShortcutsTests::rounding_test(1.5) << endl;
}