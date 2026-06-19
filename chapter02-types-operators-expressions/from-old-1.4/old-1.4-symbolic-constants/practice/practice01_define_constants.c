/*
1.4 Symbolic Constants should have:

lesson/1.4A_constant_variables.c
lesson/1.4B_define_symbolic_constants.c
practice/practice01_const_variables.c

Next practice should be:

practice02_define_constants.c

Task:

Use #define for:

#define LOWER 0
#define UPPER 100
#define STEP 10

Print Celsius to Fahrenheit table.

Formula:

fahr = (celsius * 9 / 5) + 32;

Expected:

Celsius Fahrenheit
  0       32
 10       50
 20       68
...
100      212

Use:

printf("%3d %8d\n", celsius, fahr);

*/

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