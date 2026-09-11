#ifndef TRUCK_HPP
#define TRUCK_HPP

#include "car.hpp"

class Truck : public Car {
private:
  int num_axles;
  double load_capacity;

public:
  Truck(int axles, double cap, long n, const std::string &prod);
  ~Truck(void);
  void setAxles(int qtd_axles) { num_axles = qtd_axles; }
  int getAxles() const { return num_axles; }
  void setCapacity(double cp) { load_capacity = cp; }
  double getCapacity() const { return load_capacity; }

  void display(void) const;
};

#endif // TRUCK_HPP
