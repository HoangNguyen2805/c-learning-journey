#include <stdio.h>

void printNumber(int number) {
    printf("The number is: %d\n", number);
}

int main() {
    printf("--- Function Parameters ---\n");

    printNumber(5);
    printNumber(10);
    printNumber(25);

    printf("Program finished.\n");

    return 0;
}

/*
## Lesson 07B - Function With Parameters

A parameter means the function receives input from main.

Example:

void printNumber(int number) {
    printf("The number is: %d\n", number);
}

Breakdown:

void = this function does not return a value
printNumber = function name
int number = parameter/input

When we call:

printNumber(5);

The value 5 goes into the parameter called number.

So inside the function:

number = 5

Then this prints:

The number is: 5

## Parameter vs Argument

Parameter = variable inside the function.

Example:

int number

Argument = actual value sent into the function call.

Example:

printNumber(5);

5 is the argument.

## Memory rule

Parameter = the receiving variable
Argument = the value you send

*/