#include <stdio.h>

void sayHello() {
    printf("Hello from a function!\n");
}

int main() {
    printf("--- Basic Function ---\n");

    sayHello();

    printf("Program finished.\n");

    return 0;
}

/*
## Lesson 07A - Basic Function

A function is a reusable block of code.

Example:

void sayHello() {
    printf("Hello from a function!\n");
}

This creates the function.

To use the function, call it inside main:

sayHello();

main() runs first.
When C sees sayHello(); it jumps to the sayHello function, runs it, then comes back to main.

void means this function does not return a value.

Memory rule:

Create function:

void functionName() {
    code here
}

Call function:

functionName(); 

*/