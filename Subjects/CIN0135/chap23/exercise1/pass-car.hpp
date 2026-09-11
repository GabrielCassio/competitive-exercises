#ifndef PASS_CAR_HPP
#define PASS_CAR_HPP

#include "car.hpp"

class PassCar : public Car {
private:
  std::string passCartype;
  bool sunRoof;

public:
  // Constructor
  PassCar(const std::string &tp, bool sd, int n = 0, const std::string &h = "");
  ~PassCar();
  // Aceess methods
  const std::string get_type() const { return passCartype; }
  void set_type(const std::string &s) { passCartype = s; }
  bool get_sun_roof() const { return sunRoof; }
  void set_sun_roof(bool b) { sunRoof = b; }
  void display(void) const;
};

#endif // PASS_CAR_HPP
