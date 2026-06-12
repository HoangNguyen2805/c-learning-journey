/*
Practice 04 — Assignment Shortcuts.
Task:

Start with:

int x = 20;

Then use shortcuts to make this happen:

Start: 20
After += 5: 25
After -= 10: 15
After *= 2: 30
After /= 3: 10
After %= 4: 2

Compile/run:

cd ~/Desktop/c-learning-journey/01-c-basics/day04-operators-math/practice
gcc practice04_assignment.c -o practice04_assignment
./practice04_assignment

*/

#include <stdio.h>

int main() {

    int x = 20;

    printf("Start: %d\n", x);

    x += 5;
    printf("After += 5: %d\n", x);

    x -= 10;
    printf("After -= 10: %d\n", x);

    x *= 2;
    printf("After *= 2: %d\n", x);

    x /= 3;
    printf("After /= 3: %d\n", x);

    x %= 4;
    printf("After %%= 4: %d\n", x);

    return 0;
}