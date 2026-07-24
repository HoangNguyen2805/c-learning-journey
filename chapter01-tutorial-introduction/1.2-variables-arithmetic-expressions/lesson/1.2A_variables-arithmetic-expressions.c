/*
Section 1.2 - Variables and Arithmetic Expressions
Worked examples.

Everything here uses only Section 1.1 and 1.2 material:
comments, declarations, int and float, assignment, arithmetic,
while loops, and printf conversion specifications.

No for loops (1.3), no #define (1.4), no getchar (1.5), no functions (1.7).

Compile:  gcc 1.2A_variables-arithmetic-expressions.c -o 1.2A
Run:      ./1.2A
*/

#include <stdio.h>

int main()
{
    /* ---- Example 1: declare, assign, print ---- */
    int age;

    age = 25;
    printf("Example 1: declaration and assignment\n");
    printf("age = %d\n\n", age);


    /* ---- Example 2: several variables in one declaration ---- */
    int year, month, day;

    year = 2024;
    month = 7;
    day = 24;
    printf("Example 2: one declaration, three variables\n");
    printf("%d/%d/%d\n\n", month, day, year);


    /* ---- Example 3: arithmetic operators ---- */
    int a, b;

    a = 12;
    b = 8;
    printf("Example 3: arithmetic on integers\n");
    printf("%d + %d = %d\n", a, b, a + b);
    printf("%d - %d = %d\n", a, b, a - b);
    printf("%d * %d = %d\n", a, b, a * b);
    printf("%d / %d = %d\n\n", a, b, a / b);


    /* ---- Example 4: integer division truncates ---- */
    printf("Example 4: integer division discards the fraction\n");
    printf("5 / 9   = %d\n", 5 / 9);
    printf("9 / 5   = %d\n", 9 / 5);
    printf("This is why 5/9 cannot be used in the conversion formula.\n\n");


    /* ---- Example 5: float division keeps the fraction ---- */
    float x, y;

    x = 5.0;
    y = 9.0;
    printf("Example 5: floating point division\n");
    printf("5.0 / 9.0 = %f\n", x / y);
    printf("Mixed 5.0 / 9 = %f  (the 9 is converted to float)\n\n", 5.0 / 9);


    /* ---- Example 6: width in a conversion specification ---- */
    printf("Example 6: field widths right-justify the output\n");
    printf("[%d]\n", 7);
    printf("[%3d]\n", 7);
    printf("[%6d]\n", 7);
    printf("[%6d]\n\n", 1234);


    /* ---- Example 7: precision on floating point ---- */
    printf("Example 7: precision\n");
    printf("%%f     gives %f\n", 3.14159);
    printf("%%.2f   gives %.2f\n", 3.14159);
    printf("%%8.2f  gives %8.2f\n", 3.14159);
    printf("%%.0f   gives %.0f\n\n", 3.14159);


    /* ---- Example 8: a while loop ---- */
    int i;

    printf("Example 8: while loop, 1 through 5\n");
    i = 1;
    while (i <= 5) {
        printf("%d ", i);
        i = i + 1;
    }
    printf("\n\n");


    /* ---- Example 9: a while loop whose step is not 1 ---- */
    int n;

    printf("Example 9: doubling inside a while loop\n");
    n = 1;
    while (n <= 64) {
        printf("%3d", n);
        n = n * 2;
    }
    printf("\n\n");


    /* ---- Example 10: the K&R table, integer version ---- */
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature scale */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    printf("Example 10: Fahrenheit-Celsius table, int arithmetic\n");
    fahr = lower;
    while (fahr <= upper) {
        celsius = 5 * (fahr - 32) / 9;
        printf("%3d %6d\n", fahr, celsius);
        fahr = fahr + step;
    }
    printf("\n");


    /* ---- Example 11: the same table in floating point ---- */
    float ffahr, fcelsius;
    float flower, fupper, fstep;

    flower = 0;
    fupper = 300;
    fstep = 20;

    printf("Example 11: same table, float arithmetic (more accurate)\n");
    ffahr = flower;
    while (ffahr <= fupper) {
        fcelsius = (5.0 / 9.0) * (ffahr - 32.0);
        printf("%3.0f %6.1f\n", ffahr, fcelsius);
        ffahr = ffahr + fstep;
    }

    return 0;
}
