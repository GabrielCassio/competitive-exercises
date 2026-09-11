#ifndef CAR_HPP
#define CAR_HPP

#include <string>

class Car {
private:
  long nr;              // Número do carro
  std::string producer; // Nome produtor do carro

public:
  // Constructor and Destructor
  Car(long n = 0L, const std::string &prod = "");
  ~Car(void);
  // Others publi methods
  long get_nr(void) const { return nr; }
  void set_nr(long n) { nr = n; }
  std::string get_prod(void) const { return producer; }
  void set_prod(const std::string &prod) { producer = prod; }
  void display() const;
};

#endif // CAR_HPP
