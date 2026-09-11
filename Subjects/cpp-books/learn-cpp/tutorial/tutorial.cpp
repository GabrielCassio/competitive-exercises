#include <iostream>
#include <limits>

using namespace std;

int main(){
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
    cout << "Hello, world!";

    return 0;
}