#include "car.hpp"
#include "pass-car.hpp"
#include "truck.hpp"
#include <iostream>
using namespace std;

int main(void) {
  Truck toy(5, 7.5, 1111, "Volvo");
  toy.display();
  char c;
  cout << "\nDo you want to create an object of type "
       << "PassCar? (y/n) ";
  cin >> c;
  if (c == 'y' || c == 'Y') {
    const PassCar beetle("Beetle", false, 3421, "VW");
    beetle.display();
  }
  cout << "\nDo you want to create an object "
       << " of type car? (y/n) ";
  cin >> c;
  if (c == 'y' || c == 'Y') {
    const Car oldy(3421, "Rolls Royce");
    oldy.display();
  }
  return 0;
}
