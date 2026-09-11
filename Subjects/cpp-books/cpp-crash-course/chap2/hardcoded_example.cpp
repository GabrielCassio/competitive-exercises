#include <cstdio>

int main() {
    unsigned short a = 0b10101010;
    // O especificador para short sem sinal é hu
    printf("%hu\n", a);
    int b = 0123;
    // O especificador para inteiros com sinal é d
    printf("%d\n", b);
    unsigned long long d = 0xFFFFFFFFFFFFFFFF;
    // O especificador para inteiros long long é ll, sem sinal é llu
    printf("%llu\n", d);
    unsigned int e = 3669732608;
    // O especificador x é de decimal para hexadecimal
    printf("Yabba %x!\n", e);
    unsigned int f = 69;
    // O especificador o é de decimal para octal
    printf("There are %u,%o leaves here.\n", f, f);


    double an = 6.0221409e23;
    printf("Avogadro's Number: %le %lf %lg\n", an, an, an);
    float hp = 9.75;
    printf("Hogwarts' Plataform: %e %f %g\n", hp, hp, hp);

    char x = 'M';
    wint_t y = L'Z';
    printf("Windows binaries start with %c%lc.\n", x, y);

    bool b1 = false;
    bool b2 = true;
    printf("%d %d\n", b1, b2);
      
    return 0;
}