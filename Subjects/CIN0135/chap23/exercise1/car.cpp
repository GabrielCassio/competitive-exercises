#include "car.hpp"
#include <iostream>

// Redefinindo o constructor da classe carro
Car::Car(long n, const std::string &prod) : nr(n), producer(prod) {
  std::cout << "Creating an object of type Car ... ." << std::endl;
}

// Definindo o destructor da classe carro
Car::~Car() {
  std::cout << "Destroying an object of type Car ...." << std::endl;
}

void Car::display(void) const {
  std::cout << "\n---------------------------- "
            << "\nCar number:   " << nr << "\nProducer:     " << producer
            << std::endl;
};
