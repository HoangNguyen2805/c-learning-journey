#include <stdio.h>

double calculateSubtotal(double price, int quantity);
double calculateTax(double subtotal, double taxRate);
double calculateFinalTotal(double subtotal, double tax);
void printReceipt(double subtotal, double tax, double finalTotal);

int main() {
    double price = 10.00;
    int quantity = 3;
    double taxRate = 0.0825;

    double subtotal;
    double tax;
    double finalTotal;

    subtotal = calculateSubtotal(price, quantity);
    tax = calculateTax(subtotal, taxRate);
    finalTotal = calculateFinalTotal(subtotal, tax);

    printReceipt(subtotal, tax, finalTotal);

    return 0;
}

double calculateSubtotal(double price, int quantity) {
    return price * quantity;
}

double calculateTax(double subtotal, double taxRate) {
    return subtotal * taxRate;
}

double calculateFinalTotal(double subtotal, double tax) {
    return subtotal + tax;
}

void printReceipt(double subtotal, double tax, double finalTotal) {
    printf("--- Receipt ---\n");
    printf("Subtotal: %.2f\n", subtotal);
    printf("Tax: %.2f\n", tax);
    printf("Final total: %.2f\n", finalTotal);
    printf("Program finished.\n");
}