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

/*
## Lesson 05A - Basic if Statement

An if statement runs code only when a condition is true.

Example:

int age = 20;

if (age >= 18) {
    printf("You are an adult.\n");
}

The condition is:

age >= 18

This asks:

Is age greater than or equal to 18?

Since age is 20, the condition is true, so the code inside { } runs.

Code outside the if block always runs.

Important:

if (condition) {
    code runs if condition is true
}

The { } block belongs to the if statement.
*/