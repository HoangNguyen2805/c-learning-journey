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

#include <stdio.h>

double add (double a ,double b);
double subtract (double a , double b);
double multiply (double a , double b);
double divided (double a , double b);

int main () {

    double a;
    double b;

    printf("Enter first number: ");
    scanf("%lf", &a);

    printf("Enter second number: ");
    scanf("%lf", &b);

    printf("Sum: %.2lf\n", add(a,b));
    printf("Difference: %.2lf\n", subtract(a,b));
    printf("Product: %.2lf\n", multiply(a,b));
    printf("Quotient: %.2lf\n", divided(a,b));


    return 0;
}

double add (double a , double b) {
    double sum = a + b;
    return sum;
}

double subtract (double a , double b) {
    double difference = a - b;
    return difference;
}

double multiply (double a , double b) {
    double product = a * b;
    return product;
}

double divided (double a , double b) {
    double quotient = a / b;
    return quotient;
}