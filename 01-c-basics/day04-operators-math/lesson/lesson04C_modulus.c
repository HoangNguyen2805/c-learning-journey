#include <stdio.h>

int main(){
    int a = 10;
    int b = 3;

    printf("--- Modulus / Remainder ---\n");

    printf("a = %d\n", a);
    printf("b = %d\n", b);

    printf("\nDivision:\n");
    printf("%d / %d = %d\n", a, b, a / b);

    printf("\nRemainder:\n");
    printf("%d %% %d = %d\n", a, b, a % b);

    printf("\nMore examples:\n");
    printf("10 %% 2 = %d\n", 10 % 2);
    printf("10 %% 3 = %d\n", 10 % 3);
    printf("10 %% 4 = %d\n", 10 % 4);
    printf("10 %% 5 = %d\n", 10 % 5);

    printf("\nEven or odd idea:\n");
    printf("10 %% 2 = %d\n", 10 % 2);
    printf("11 %% 2 = %d\n", 11 % 2);

    return 0;
}

/*
## Lesson 04C - Modulus / Remainder

The % operator gives the remainder after division.

Example:

10 / 3 = 3
10 % 3 = 1

Meaning:

10 divided by 3 = 3 remainder 1.

The / operator gives the quotient.
The % operator gives the remainder.

More examples:

10 % 2 = 0
10 % 3 = 1
10 % 4 = 2
10 % 5 = 0

% is useful for checking even or odd.

10 % 2 = 0 means even.
11 % 2 = 1 means odd.

Important:

% only works with integer types.

Do not use % with float or double.
Do not use % 0.

*/