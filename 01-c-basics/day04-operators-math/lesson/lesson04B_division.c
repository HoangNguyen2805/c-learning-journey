#include <stdio.h>

int main() {
    int a = 10;
    int b = 3;

    double result1 = a / b;
    double result2 = 10.0 / 3;
    double result3 = (double)a / b;

    printf("--- Integer vs Decimal Division ---\n");

    printf("a = %d\n", a);
    printf("b = %d\n", b);

    printf("\nint / int stored in double:\n");
    printf("a / b = %.2f\n", result1);

    printf("\ndecimal / int:\n");
    printf("10.0 / 3 = %.2f\n", result2);

    printf("\ncasting int to double:\n");
    printf("(double)a / b = %.2f\n", result3);

    return 0;
}

/*
## Lesson 04B - Integer vs Decimal Division

If both values are integers, C does integer division.

Example:

10 / 3 = 3

C removes the decimal part.

Even if the answer is stored inside a double, the calculation already happened as integer division first.

Example:

double result = 10 / 3;

This gives:

3.00

To get decimal division, at least one value must be decimal.

Example:

double result = 10.0 / 3;

This gives:

3.33

Another way is casting:

int a = 10;
int b = 3;

double result = (double)a / b;

This temporarily treats a as a double, so the answer is decimal.

Important rules:

int / int = int
double / int = double
int / double = double
double / double = double

If I want decimal division from int variables, use casting:

(double)a / b
*/