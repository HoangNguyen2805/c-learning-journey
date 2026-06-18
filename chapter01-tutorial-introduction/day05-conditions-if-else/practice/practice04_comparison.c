/*
Practice 04 — Comparison Operators Challenge

Task: Ask user for two integers, a and b.

Print:

a = __
b = __

Then use if statements to print all true comparisons.

Example 1:

Enter a: 10
Enter b: 5

a = 10
b = 5
a is not equal to b.
a is greater than b.
a is greater than or equal to b.

Example 2:

Enter a: 5
Enter b: 5

a = 5
b = 5
a is equal to b.
a is greater than or equal to b.
a is less than or equal to b.

Requirements:

scanf
printf
if
==
!=
>
<
>=
<=

Compile/run:

cd ~/c-learning-journey/01-c-basics/day05-conditions-if-else/practice
gcc practice04_comparison.c -o practice04_comparison
./practice04_comparison

*/

#include <stdio.h>

int main() {

    int a;
    int b;

    printf("Enter a: ");
    scanf("%d", &a);

    printf("Enter b: ");
    scanf("%d", &b);

    printf("\na = %d\n", a);
    printf("b = %d\n", b);

    if ( a == b ){
        printf("a is equal to b.\n");
    }

    if ( a != b ){
        printf("a is Not equal to b.\n");
    }

    if ( a > b ){
        printf("a is greater than b.\n");
    }

    if ( a < b ){
        printf("a is less than b.\n");
    }

    if ( a >= b ){
        printf("a is greater than or equal to b.\n");
    }

    if ( a <= b ){
        printf("a is less than or equal to b.\n");
    }

    return 0;
}