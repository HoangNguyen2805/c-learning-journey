#include <stdio.h>

int main() {

    int a;
    int b;

    printf("Enter a: ");
    scanf("%d", &a);

    printf("Enter b: ");
    scanf("%d", &b);

    printf("\n--- Comparison Results ---\n");

    if (a == b) {
        printf("a is equal to b.\n");
    }

    if (a != b) {
        printf("a is not equal to b.\n");
    }

    if (a > b) {
        printf("a is greater than b.\n");
    }

    if (a < b) {
        printf("a is less than b.\n");
    }

    if (a >= b) {
        printf("a is greater than or equal to b.\n");
    }

    if (a <= b) {
        printf("a is less than or equal to b.\n");
    }

    printf("Program finished.\n");

    return 0;
}