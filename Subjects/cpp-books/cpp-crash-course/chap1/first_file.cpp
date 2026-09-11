#include <cstdio>

// Functions
int step_function(int x) {
  int result = 0;
  if (x < 0) {
    result = -1;
  } else if (x > 0) {
    result = 1;
  }
  return result;
}

int main(){
    // First Hello, world in c++
    printf("Hello, world!\n");
    
    // Declaring variables
    int the_answer = 42;
    int lucky_number = the_answer / 6;
    
    // Conditional statements
    int x = 0;
    if (x > 0) printf("Positive.\n");
    else if (x < 0) printf("Negative.\n");
    else printf("Zero.\n");
    // 42  == x;  // Equality
    // 42  != x;  // Inequality
    // 100 >  x;  // Greater than
    // 123 >= x;  // Greater than or equal to
    // -10 <  x;  // Less than
    // -99 <= x;  // Less than or equal to

    // Functions
    int value1 = step_function(100);
    int value2 = step_function(0);
    int value3 = step_function(-10);

    // printf format specifiers
    printf("Ten %d, Twenty %d, Thirty %d \n", 10, 20, 30);

    // Using all basic concepts
    int num1 = the_answer;
    int result1 = step_function(num1);

    int num2 = 0;
    int result2 = step_function(num2);

    int num3 = -32767;
    int result3 = step_function(num3);

    printf("Num: %d, Step: %d", num1, result1);
    printf("Num: %d, Step: %d", num2, result2);
    printf("Num: %d, Step: %d", num3, result3);
    
    
    return 0;
}