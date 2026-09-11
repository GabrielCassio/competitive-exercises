#include "euro.hpp"
#include <iostream>

int main() {
  Euro salary(8800, 80);
  double x(0.0);
  salary += 1000;
  salary += 0.10;
  x = salary;
  x = (double)salary;
  x = salary.operator double();
  x = double(salary);
  int i = salary;
  std::cout << "O que há no X?\n" << x << std::endl;
  std::cout << salary.get_euro_cents() << std::endl;
  std::cout << "O que há no i?\n" << i << std::endl;
  return 0;
}
