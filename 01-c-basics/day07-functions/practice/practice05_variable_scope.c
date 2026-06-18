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

#include <stdio.h>

double calculateSubtotal(double price, int quantity);
double calculateTax(double subtotal, double taxRate);
double calculateFinalTotal(double subtotal, double tax);
void printReceipt(double subtotal, double tax, double finalTotal);

int main() {

    double price;
    int quantity;
    double taxRate;

    double subtotal;
    double tax;
    double finalTotal;

    printf("Enter price: ");
    scanf("%lf", &price);
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    printf("Enter tax rate: ");
    scanf("%lf", &taxRate);

    subtotal = calculateSubtotal(price,quantity);
    tax = calculateTax(subtotal,taxRate);
    finalTotal = calculateFinalTotal(subtotal,tax);
    
    printReceipt(subtotal,tax,finalTotal);

    return 0;
}

double calculateSubtotal(double price, int quantity) {
    double subTo = price * quantity;
    return subTo;
}

double calculateTax(double subtotal, double taxRate) {
    double tax = taxRate * subtotal;
    return tax;
}

double calculateFinalTotal(double subtotal, double tax) {
    double final = subtotal + tax;
    return final;
}

void printReceipt(double subtotal, double tax, double finalTotal) {
    printf("\nSubtotal: %.2lf\n", subtotal);
    printf("Tax: %.2lf\n", tax);
    printf("Final total: %.2lf\n", finalTotal);
    printf("Program finished.\n");
}
