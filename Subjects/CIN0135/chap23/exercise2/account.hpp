#ifndef _ACCOUNT_
#define _ACCOUNT_

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

class Account {
private:
  string name;
  unsigned long nr;
  double balance;

public:
  Account(const string &s = "X", unsigned long n = 1111111L, double st = 0.0)
      : name(s), nr(n), balance(st) {}
  const string &getName() const { return name; }
  void setName(const string &n) { name = n; }
  unsigned long getNr() const { return nr; }
  void setNr(unsigned long n) { nr = n; }
  double getBalance() const { return balance; }
  void setBalance(double st) { balance = st; }
  void display() const {
    cout << fixed << setprecision(2)
         << "----------------------------------------\n"
         << "Account holder:        " << name << endl
         << "Account number:        " << nr << endl
         << "Balance of the account:" << balance << endl;
  }
};
#endif //  _ACCOUNT
