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