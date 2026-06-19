#include <stdio.h>

#define LOWER 0
#define UPPER 100
#define STEP 10

int main() {
    int celsius;
    int fahr;

    printf("Celsius Fahrenheit\n");

    for (celsius = LOWER; celsius <= UPPER; celsius = celsius + STEP) {
        fahr = (celsius * 9 / 5) + 32;
        printf("%3d %8d\n", celsius, fahr);
    }

    return 0;
}