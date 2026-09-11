#ifndef EURO_HPP
#define EURO_HPP

class Euro {
private:
  long data;

public:
  Euro(int euro = 0, int cents = 0) { data = euro * 100 + cents; };
  Euro(double x) { data = x * 100; }
  /*  Overload double conversion
   *  This a function to only read, but in the middle has a conversion of the
   * data in a double value
   * */
  operator double() const { return (double)data / 100.0; }
  void operator+=(double inc_val) { data += (inc_val * 100); }

  long get_euro_cents() const { return data; }
};

#endif // EURO_HPP
