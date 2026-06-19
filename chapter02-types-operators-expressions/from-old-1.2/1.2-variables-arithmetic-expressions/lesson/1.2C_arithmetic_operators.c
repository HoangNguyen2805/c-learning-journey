#include <stdio.h>

int main() {
    int a = 10;
    int b = 3;

    printf("a = %d\n", a);
    printf("b = %d\n", b);

    printf("\n--- Arithmetic Operators ---\n");

    printf("Addition: %d + %d = %d\n", a, b, a + b);
    printf("Subtraction: %d - %d = %d\n", a, b, a - b);
    printf("Multiplication: %d * %d = %d\n", a, b, a * b);
    printf("Division: %d / %d = %d\n", a, b, a / b);
    printf("Remainder: %d %% %d = %d\n", a, b, a % b);

    return 0;
}