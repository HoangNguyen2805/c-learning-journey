#include <stdio.h>

int main() {
    int x;
    int y;

    x = 5;
    y = 10;

    printf("Simple statements:\n");
    printf("x = %d\n", x);
    printf("y = %d\n", y);

    {
        int sum;

        sum = x + y;

        printf("\nInside a block:\n");
        printf("sum = %d\n", sum);
    }

    printf("\nBack in main block.\n");

    return 0;
}