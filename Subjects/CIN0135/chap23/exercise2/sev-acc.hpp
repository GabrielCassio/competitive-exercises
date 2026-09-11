#ifndef SEV_ACC_HPP
#define SEV_ACC_HPP

#include "account.hpp"

class SevAcc : public Account {
private:
  double interest_rate;

public:
  SevAcc(double ir, std::string &name, unsigned long id, double st);
  ~SevAcc();
  double get_interest_rate() const { return interest_rate; }
  void set_limit(double limit);
  void display(void) const;
};

#endif // SEV_ACC_HPP
