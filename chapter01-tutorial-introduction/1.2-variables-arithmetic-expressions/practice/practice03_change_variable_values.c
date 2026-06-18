/*
Practice 3 task

Write a program that creates these variables:

char item[] = "Laptop";
int quantity = 2;
float price = 799.99;
double total = 1599.98;
char currency = '$';
bool inStock = true;

Print exactly this output:

Item: Laptop
Quantity: 2
Price: $799.99
Total: $1599.98
In stock: 1

Remember:

%s = string
%d = int or bool
%c = char
%.2f = decimal with 2 digits

Compile and run:

cd ~/c-learning-journey/01-c-basics/day02-variables-data-types/practice
gcc practice03_change_values.c -o practice03
./practice03
*/

#include <stdio.h>
#include <stdbool.h>

int main(){

    char item[] = "Laptop";
    int quantity = 2;
    float price = 799.99;
    double total = 1599.98;
    bool inStock = true;


    printf("Item: %s\n", item);
    printf("Quantity: %d\n", quantity);
    printf("Price: $%.2f\n", price);
    printf("Total: $%.2f\n", total);
    printf("In stock: %d\n", inStock);

    return 0;
}