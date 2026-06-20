#include <stdio.h>

int main() {
    int result1 = 10 + 3 * 2;
    int result2 = (10 + 3) * 2;

    int result3 = 20 / 5 * 2;
    int result4 = 20 / (5 * 2);

    int result5 = 20 - 5 - 2;
    int result6 = 20 - (5 - 2);

    int result7 = 10 > 3 && 5 > 2;
    int result8 = 10 > 3 || 5 < 2;

    int x;
    int a;
    int b;
    int c;

    printf("Precedence and parentheses:\n");

    printf("10 + 3 * 2 = %d\n", result1);
    printf("(10 + 3) * 2 = %d\n", result2);

    printf("\n20 / 5 * 2 = %d\n", result3);
    printf("20 / (5 * 2) = %d\n", result4);

    printf("\n20 - 5 - 2 = %d\n", result5);
    printf("20 - (5 - 2) = %d\n", result6);

    printf("\nRelational and logical precedence:\n");
    printf("10 > 3 && 5 > 2 = %d\n", result7);
    printf("10 > 3 || 5 < 2 = %d\n", result8);

    x = 2 + 3 * 4;
    printf("\nx = 2 + 3 * 4 gives x = %d\n", x);

    a = b = c = 0;
    printf("\nChained assignment:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);

    return 0;
}