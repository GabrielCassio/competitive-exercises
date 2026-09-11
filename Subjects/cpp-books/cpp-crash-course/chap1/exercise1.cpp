#include <cstdio>

int absolute_value(int val){
    if (val < 0) return -val;
    return val;
}

int sum (int val1, int val2) {
    return val1 + val2;
}

int main () {
    int my_num = -10;
    printf("The absolute value of %d is %d.\n", my_num, absolute_value(my_num));

    int my_num1 = 0;
    printf("The absolute value of %d is %d.\n", my_num1, absolute_value(my_num1));

    int my_num2 = 10;
    printf("The absolute value of %d is %d.\n", my_num2, absolute_value(my_num2));
}