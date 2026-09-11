#include "truck.hpp"
#include <iostream>

Truck::Truck(int axles, double cap, long n, const std::string &prod)
    : Car(n, prod), num_axles(axles), load_capacity(cap) {
  std::cout << "Creating an object of type Truck... ." << std::endl;
}

Truck::~Truck() {
  std::cout << "Destroying an object of type Truck... ." << std::endl;
}

void Truck::display(void) const {
  Car::display();
  std::cout << "Axles:       " << num_axles
            << "\nCapacity:    " << load_capacity << " long tons\n";
}
