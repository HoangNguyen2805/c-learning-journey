/*
Practice 11 — printf Placeholders

Make a program that creates these variables:

int number = 255;
int id = 7;
double price = 12.5;
char grade = 'A';
char name[] = "Hoang";

Print output using placeholders.

Required output
--- printf Placeholder Practice ---

Name: Hoang
Grade: A
Number decimal: 255
Number octal: 377
Number hex: ff
Price normal: 12.500000
Price two decimals: 12.50
Percent example: 90%

--- Width Practice ---
ID normal: 7
ID width 5:     7
ID left align: 7    
ID zero padded: 00007

--- Decimal Width Practice ---
Price width 8 two decimals:    12.50
Price left align: 12.50   
Must use
%s
%c
%d
%o
%x
%f
%.2f
%%
%5d
%-5d
%05d
%8.2f
%-8.2f

Run:

cd ~/c-learning-journey/chapter01-tutorial-introduction/1.2-variables-arithmetic-expressions/practice
gcc practice11_printf_placeholders.c -o practice11_printf_placeholders
./practice11_printf_placeholders

*/

#include <stdio.h>

int main() {

    int number = 255;
    int id = 7;
    double price = 12.5;
    char grade = 'A';
    char name[] = "Hoang";

    printf("--- printf Placeholder Practice ---\n");
    printf("\nName: %s\n", name);
    printf("Grade: %c\n", grade);
    printf("Number decimal: %d\n", number);
    printf("Number octal: %o\n",number);
    printf("Number hex: %x\n", number);
    printf("Price normal: %f\n", price);
    printf("Price two decimals: %.2f\n", price);
    printf("Percent example: 90%%\n");

    printf("\n--- Width Practice ---\n");
    printf("ID normal: %d\n", id);
    printf("ID width: %5d\n", id);
    printf("ID left align: %-5d\n", id);
    printf("ID zero padded: %05d\n", id);

    printf("\n--- Decimal Width Practice ---\n");
    printf("Price width 8 two decimals: |%8.2f|\n", price);
    printf("Price left align: |%-8.2f|\n", price);

    return 0;
}