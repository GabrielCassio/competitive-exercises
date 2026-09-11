#include "dep-acc.hpp"
#include "sev-acc.hpp"

int main(void) {
  string s;
  double db;
  SavAcc mickey("Mickey Mouse", 1234567, 2.40, 3.5);
  mickey.display();
  cout << "New name:          ";
  getline(cin, s);
  cout << "New interest rate: ";
  cin >> db;
  mickey.setName(s);
  mickey.setInterest(db);
  mickey.display();
  DepAcc dag("Donald Duck", 7654321, -1245.56, 10000, 12.9);
  dag.display();
  cout << "New limit:         ";
  cin >> db;
  dag.setLimit(db);
  dag.display();
}
