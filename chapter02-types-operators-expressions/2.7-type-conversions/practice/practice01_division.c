/*
Practice 02 - Division.

Task

Ask the user for two whole numbers:

a
b

Then print:

integer division
decimal division using casting
Expected output example

User input:

Enter a: 10
Enter b: 3

Output:

--- Division Result ---
Integer division: 10 / 3 = 3
Decimal division: 10 / 3 = 3.33
Hints only
a and b should be int

scanf for int uses %d

integer division:
a / b

decimal division:
(double)a / b

print integer result with %d
print decimal result with %.2f
Compile/run
cd ~/Desktop/c-learning-journey/01-c-basics/day04-operators-math/practice
gcc practice02_division.c -o practice02_division
./practice02_division

*/

#include <stdio.h>

int main(){

    int a;
    int b;

    printf("Enter a: ");
    scanf("%d", &a);

    printf("Enter b: ");
    scanf("%d", &b);

    printf("\n--- Division Result ---\n");
    printf("Integer division: %d / %d = %d\n", a, b, a/b);
    printf("Decimal division: %d / %d = %.2f\n",a , b, (double)a/b );

    return 0;
}