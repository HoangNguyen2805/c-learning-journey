/*
Practice 2.

Task: ask the user for a price, then print it with 2 decimals.

Use:

float price;

Expected:

Enter price: 9.99
Price is $9.99.

Compile/run:

gcc practice02_read_price.c -o practice02
./practice02

*/

#include <stdio.h>

int main() {
    float price;

    printf("Enter Your Price: ");

    scanf("%f", &price);

    printf("Your price is $%.2f.\n", price);

    return 0;
}