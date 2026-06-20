#include <stdio.h>

int main() {
    int age = 20;
    int score = 85;
    int a = 10;
    int b = 3;

    printf("Relational operators:\n");
    printf("a > b: %d\n", a > b);
    printf("a >= b: %d\n", a >= b);
    printf("a < b: %d\n", a < b);
    printf("a <= b: %d\n", a <= b);
    printf("a == b: %d\n", a == b);
    printf("a != b: %d\n", a != b);

    printf("\nLogical operators:\n");
    printf("age >= 18 && age <= 25: %d\n", age >= 18 && age <= 25);
    printf("score >= 90 || score >= 80: %d\n", score >= 90 || score >= 80);
    printf("!(age < 18): %d\n", !(age < 18));

    printf("\nZero and nonzero:\n");
    printf("!0: %d\n", !0);
    printf("!1: %d\n", !1);
    printf("!100: %d\n", !100);

    printf("\nPrecedence example:\n");
    printf("10 + 5 > 12: %d\n", 10 + 5 > 12);

    return 0;
}