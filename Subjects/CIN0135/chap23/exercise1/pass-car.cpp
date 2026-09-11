#include "pass-car.hpp"

#include <iostream>

PassCar::PassCar(const std::string &tp, bool sr, int n, const std::string &hs)
    : Car(n, hs), passCartype(tp), sunRoof(sr) {

  std::cout << "Creating an object of type PassCar ... ." << std::endl;
}

PassCar::~PassCar() {
  std::cout << "Destroying an object of type PassCar ... ." << std::endl;
}

void PassCar::display(void) const {
  Car::display();
  std::cout << "Type: " << passCartype << std::endl;
  std::cout << "Sun Roof: " << (sunRoof ? "Yes" : "No") << std::endl;
}

// // Redefining the constructor
// PassCar::PassCar(const std::string &tp, bool sr, int n, const std::string
// &hs) {
//   setNr(n);
//   setProd(hs);
//   passCartype = "";
//   sunRoof = sr;
// }

// PassCar::PassCar(const std::string &tp, bool sr, int n, const std::string
// &hs)
//     : Car(n, hs) {
//   passCartype = tp;
//   sunRoof = sr;
// }
