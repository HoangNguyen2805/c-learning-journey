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

/*
## Lesson 04D - Assignment Shortcuts

Assignment shortcuts update the same variable.

x += 3 means x = x + 3
x -= 2 means x = x - 2
x *= 4 means x = x * 4
x /= 2 means x = x / 2
x %= 5 means x = x % 5

Example:

int x = 10;

x += 3;   x becomes 13
x -= 2;   x becomes 11
x *= 4;   x becomes 44
x /= 2;   x becomes 22
x %= 5;   x becomes 2

Important:
The value of x changes after every line.

So x %= 5 is not 10 % 5.
It is 22 % 5 because x already changed to 22.

22 % 5 = 2
*/