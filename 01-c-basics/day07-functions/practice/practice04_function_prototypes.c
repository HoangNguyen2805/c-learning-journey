/*
Practice 04 — Function Prototypes.

Goal

Make a small calculator using function prototypes.

Required prototypes at the top

Put these above main:

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
double divide(int a, int b);
Program requirements

Ask user for 2 numbers:

Enter first number:
Enter second number:

Then print:

Sum:
Difference:
Product:
Quotient:
Important rules

main() must come before the real function definitions.

Structure should be:

#include <stdio.h>

// prototypes here

int main() {
    // scanf
    // call functions
    // print answers
}

// real function definitions here
Example input
Enter first number: 10
Enter second number: 2
Expected output
Sum: 12
Difference: 8
Product: 20
Quotient: 5.00

Run on PC:

cd ~/c-learning-journey/01-c-basics/day07-functions/practice
gcc practice04_function_prototypes.c -o practice04_function_prototypes
./practice04_function_prototypes

*/