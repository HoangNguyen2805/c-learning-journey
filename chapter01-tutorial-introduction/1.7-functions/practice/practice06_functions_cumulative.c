/*
Practice 06 — Day 07 Cumulative Functions Challenge.

Create:

01-c-basics/day07-functions/practice/practice06_functions_cumulative.c
Goal

Make a small shopping checkout system using functions.

Requirements

Use prototypes above main.

Required functions:

double calculateSubtotal(double price, int quantity);
double calculateDiscount(double subtotal);
double calculateTax(double subtotalAfterDiscount, double taxRate);
double calculateFinalTotal(double subtotal, double discount, double tax);
void printReceipt(char itemName[], double subtotal, double discount, double tax, double finalTotal);

Program asks user for:
item name
price
quantity
tax rate
Rules
subtotal = price * quantity

if subtotal >= 100
    discount = subtotal * 0.10
else
    discount = 0

subtotalAfterDiscount = subtotal - discount

tax = subtotalAfterDiscount * taxRate

finalTotal = subtotalAfterDiscount + tax
Example input
Enter item name: Laptop
Enter price: 50
Enter quantity: 3
Enter tax rate: 0.0825
Expected output
--- Receipt ---
Item: Laptop
Subtotal: 150.00
Discount: 15.00
Tax: 11.14
Final total: 146.14
Program finished.
Must use
char itemName[50]
scanf
double
int
if / else
functions with parameters
return value functions
void function
function prototypes
scope

Run:

cd ~/Desktop/c-learning-journey/01-c-basics/day07-functions/practice
gcc practice06_functions_cumulative.c -o practice06_functions_cumulative
./practice06_functions_cumulative

*/