#include "dep-acc.hpp"
#include "account.hpp"

DepAcc::DepAcc(double draft_num, double ir, std::string &name, unsigned long id,
               double st)
    : Account(name, id, st), draft_limit(draft_num), interest_rate(ir) {}

DepAcc::~DepAcc() {}

void DepAcc::display() const {
  Account::display();
  cout << "Draft limit:          " << draft_limit << endl
       << "Interest Rate:        " << interest_rate << endl
       << "----------------------------------\n"
       << endl
       << endl;
}
