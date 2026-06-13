/*
Practice 06 — Precedence.

Expected output:

10 + 2 * 5 = 20
(10 + 2) * 5 = 60

30 / 3 * 2 = 20
30 / (3 * 2) = 5

50 - 10 - 5 = 35
50 - (10 - 5) = 45

Compile/run:

cd ~/c-learning-journey/01-c-basics/day04-operators-math/practice
gcc practice06_precedence.c -o practice06_precedence
./practice06_precedence
*/

#include <stdio.h>

int main() {

    int result1 = 10 + 2 * 5;
    int result2 = (10 + 2) * 5;

    int result3 = 30 / 3 * 2;
    int result4 = 30 / (3 * 2);

    int result5 = 50 - 10 - 5;
    int result6 = 50 - (10 - 5);

    printf("10 + 2 * 5 = %d\n", result1);
    printf("(10 + 2) * 5 = %d\n", result2);

    printf("\n30 / 3 * 2 = %d\n", result3);
    printf("30 / (3 * 2) = %d\n", result4);

    printf("\n50 - 10 - 5 = %d\n", result5);
    printf("50 - (10 - 5) = %d\n", result6);

    return 0;
}