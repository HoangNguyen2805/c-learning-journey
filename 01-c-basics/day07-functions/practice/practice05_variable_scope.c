/*
Practice 05 — Variable Scope.
Goal

Practice understanding which variables belong to main and which variables belong inside functions.

Task

Make a program that asks user for:

price
quantity
taxRate

Use these functions:

double calculateSubtotal(double price, int quantity);
double calculateTax(double subtotal, double taxRate);
double calculateFinalTotal(double subtotal, double tax);
void printReceipt(double subtotal, double tax, double finalTotal);
Requirements

Use prototypes above main.

Inside main:

ask for price
ask for quantity
ask for taxRate
call the functions
store returned values in main variables
call printReceipt
Expected example

Input:

Enter price: 10
Enter quantity: 3
Enter tax rate: 0.0825

Output:

Subtotal: 30.00
Tax: 2.48
Final total: 32.48
Program finished.

Run:

cd ~/c-learning-journey/01-c-basics/day07-functions/practice
gcc practice05_variable_scope.c -o practice05_variable_scope
./practice05_variable_scope

*/