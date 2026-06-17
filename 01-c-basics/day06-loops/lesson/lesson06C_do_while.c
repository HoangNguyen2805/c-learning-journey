#include <stdio.h>

int main() {

    int i = 1;

    printf("--- Do While Loop ---\n");

    do {
        printf("%d\n", i);
        i++;
    } while (i <= 5);

    printf("Program finished.\n");

    return 0;
}