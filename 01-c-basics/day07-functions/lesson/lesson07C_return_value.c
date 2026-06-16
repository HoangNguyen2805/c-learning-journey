#include <stdio.h>

int addNumbers(int a, int b) {
    int sum = a + b;
    return sum;
}

int main() {
    printf("--- Return Value Function ---\n");

    int result;

    result = addNumbers(5, 3);

    printf("Result: %d\n", result);
    printf("Program finished.\n");

    return 0;
}

/*
## Lesson 07C - Function That Returns a Value

A void function does not send back an answer.

Example:

void checkAge(int age)

But an int function returns an int answer.

Example:

int addNumbers(int a, int b) {
    int sum = a + b;
    return sum;
}

Breakdown:

int = return type
addNumbers = function name
int a, int b = parameters/input
return sum; = send sum back to main

When we call:

result = addNumbers(5, 3);

This means:

1. send 5 into a
2. send 3 into b
3. addNumbers calculates 5 + 3
4. return sum sends 8 back
5. result stores 8

Memory rule:

void function = does not return an answer
int function = returns an int answer
return = send value back

*/