/*
Practice 1 — arithmetic operators

Task:

Use these variables:

int x = 20;
int y = 6;

Print:

x = 20
y = 6

--- Practice Arithmetic ---
Addition: 26
Subtraction: 14
Multiplication: 120
Division: 3
Remainder: 2

Hints only:

addition uses +
subtraction uses -
multiplication uses *
division uses /
remainder uses %
inside printf, print real % using %%

Compile/run:

cd ~/c-learning-journey/01-c-basics/day04-operators-math/practice
gcc practice01_arithmetic.c -o practice01
./practice01

*/

#include <stdio.h>

int main() {

    int x = 20;
    int y = 6;

    printf("x = %d\n", x);
    printf("y = %d\n", y);

    int w = x * y;
    int v = x / y;
    int z = x % y;

    printf("--- Practice Arithmethic ---\n\n");
    printf("Addition: %d\n", x + y);
    printf("Subtraction: %d\n", x - y);
    printf("Multiplication: %d\n", w);
    printf("Division: %d\n", v);
    printf("Remainder: %d\n", z);


    return 0;
}