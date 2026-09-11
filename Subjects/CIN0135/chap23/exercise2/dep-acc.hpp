#ifndef DEP_ACC_HPP
#define DEP_ACC_HPP

#include "account.hpp"

class DepAcc : public Account {
private:
  double draft_limit;
  double interest_rate;

public:
  DepAcc(double draft_num, double ir, std::string &name, unsigned long id,
         double st);
  ~DepAcc();
  double get_draft_limit() const { return draft_limit; }
  void set_limit(double limit);
  double get_interest_rate() const { return interest_rate; }
  void set_rate(double rate);
  void display(void) const;
};

#endif // DEP_ACC_HPP
