#include <cstdio>

union Variant {
    char string[10];
    int integer;
    double floating_pointer;
};

int main () {
    Variant v;
    v.integer = 42;
    printf("The ultimate answer:    %d\n", v.integer);
    v.floating_pointer = 2.7182818284;
    printf("Euler's number e:       %f\n", v.floating_pointer);
    printf("A dumpster fire:        %d\n", v.integer);
  
    return 0;  
}