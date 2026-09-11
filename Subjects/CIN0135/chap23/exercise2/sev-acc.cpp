#include "sev-acc.hpp"
#include "account.hpp"

SevAcc::SevAcc(double ir, std::string &name, unsigned long id, double st)
    : Account(name, id, st), interest_rate(ir) {}

SevAcc::~SevAcc() {}

void SevAcc::display() const {
  Account::display();
  cout << "Interest Rate:        " << interest_rate << endl
       << "----------------------------------\n"
       << endl
       << endl;
}
