#include <stdio.h>

int main() {
    int age = 20;                       // Since: age = 20

    printf("--- Basic if statement ---\n");
    printf("Age: %d\n", age);

    if (age >= 18) {  // If age is 18 or more, run the code inside { }.
        printf("You are an aldult.\n"); // 20 >= 18 is true
    }                                   //C prints: You are an adult.

    printf("Program finished.\n");

    return 0;
}