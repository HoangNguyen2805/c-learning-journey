/*
Practice 03 — Modulus.

Ask the user for two whole numbers:

a
b

Then print:

division result
remainder result
Expected output example

Input:

Enter a: 10
Enter b: 3

Output:

--- Modulus Result ---
10 / 3 = 3
10 % 3 = 1
Hints only
a and b are int

scanf for int:
scanf("%d", &a);

division:
a / b

remainder:
a % b

To print real % inside printf, use %%
Compile/run
cd ~/Desktop/c-learning-journey/01-c-basics/day04-operators-math/practice
gcc practice03_modulus.c -o practice03_modulus
./practice03_modulus

*/

#include <stdio.h>

int main() {

    int a;
    int b;

    printf("Enter a: ");
    scanf("%d", &a);

    printf("Enter b: ");
    scanf("%d", &b);
    
    printf("--- Modulus Result ---\n");
    printf("%d / %d = %d\n", a, b, a / b);
    printf("%d %% %d = %d\n", a, b, a % b);

    return 0;
}