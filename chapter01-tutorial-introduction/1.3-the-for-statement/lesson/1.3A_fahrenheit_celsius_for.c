#include <stdio.h>

int main() {
    int lower;
    int upper;
    int step;
    int fahr;

    lower = 0;
    upper = 300;
    step = 20;

    printf("--- while loop version ---\n");
    printf("Fahrenheit Celsius\n");

    fahr = lower;

    while (fahr <= upper) {
        printf("%3d %6d\n", fahr, 5 * (fahr - 32) / 9);
        fahr = fahr + step;
    }

    printf("\n--- for loop version ---\n");
    printf("Fahrenheit Celsius\n");

    for (fahr = lower; fahr <= upper; fahr = fahr + step) {
        printf("%3d %6d\n", fahr, 5 * (fahr - 32) / 9);
    }

    return 0;
}