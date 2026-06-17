#include <stdio.h>

int main() {
    int x = 10;

    printf("--- Assignment Shortcuts ---\n");

    printf("Starting x = %d\n", x);

    // x = 10 start here:
    x += 3;                               // 
    printf("After x += 3, x = %d\n", x);  // x = 10 + 3 
                                          // x = 13
    x -= 2;                               // then
    printf("After x -= 2, x = %d\n", x);  // x = 13 - 2
                                          // x = 11
    x *= 4;                               // then
    printf("After x *= 4, x = %d\n", x);  // x = 11 * 4
                                          // x = 44
    x /= 2;                               // then
    printf("After x /= 2, x = %d\n", x);  // x = 44 / 2
                                          // x = 22
    x %= 5;                               // then
    printf("After x %%= 5, x = %d\n", x); // x = 22 % 5
                                          // 20 / 5 = 4, so 22 - 20
                                          // then we have a
                                          // remainder of x = 2

    return 0;
}