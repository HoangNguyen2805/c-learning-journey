/*
Practice 4.11.3 - Multi-file Calculator with Header Guards

Problem:
Create a multi-file C project with:
1. calculator.h - header file with function prototypes and macros
2. calculator.c - implementations of add, subtract, multiply, divide
3. main.c - uses functions and macros in a calculator program

This practices:
- Header guards (#ifndef, #define, #endif)
- #include with " "
- Function prototypes
- Function-like macros
*/

#ifndef CALCULATOR_H
#define CALCULATOR_H

// Function prototypes
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

// Function-like macros
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define square(x) ((x) * (x))

#endif