#include <iostream>

double babylonian_sqrt (double n) {
    if (n < 0) {
        std::cerr << "Error: Cannot compute square root of a negative number." << std::endl;
        return -1;
    }

    double t = 0.00001;
    double x = n / 2;
    double y = 0;

    while (std::abs(x - y) > t) {
        y = n / x;
        x = (x + y) / 2;
    }
                                   
    return x;

}