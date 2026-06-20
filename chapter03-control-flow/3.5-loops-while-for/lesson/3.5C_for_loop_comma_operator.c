#include <stdio.h>

int main() {
    int i;
    int j;

    printf("For loop with comma operator:\n");

    for (i = 0, j = 5; i < j; i++, j--) {
        printf("i = %d, j = %d\n", i, j);
    }

    printf("Program finished.\n");

    return 0;
}