#include <stdio.h>

int main() {
    int result1 = 10 + 3 * 2;
    int result2 = (10 + 3) * 2;

    int result3 = 20 / 5 * 2;
    int result4 = 20 / (5 * 2);

    int result5 = 20 - 5 - 2;
    int result6 = 20 - (5 - 2);

    printf("--- Precedence and Parentheses ---\n");

    printf("10 + 3 * 2 = %d\n", result1);
    printf("(10 + 3) * 2 = %d\n", result2);

    printf("\n20 / 5 * 2 = %d\n", result3);
    printf("20 / (5 * 2) = %d\n", result4);

    printf("\n20 - 5 - 2 = %d\n", result5);
    printf("20 - (5 - 2) = %d\n", result6);

    return 0;
}