/*
Practice 05 — Increment / Decrement.
Task:

Start with:

int x = 10;

Print each result:

Start: 10
After x++: 11
After ++x: 12
After x--: 11
After --x: 10

Then do this second part:

int a = 7;
int b = a++;

int c = 7;
int d = ++c;

Post-increment:
a = 8
b = 7

Pre-increment:
c = 8
d = 8

Compile/run:

cd ~/Desktop/c-learning-journey/01-c-basics/day04-operators-math/practice
gcc practice05_increment.c -o practice05_increment
./practice05_increment

*/

#include <stdio.h>

int main() {

    //First part:
    int x = 10;

    printf("Start: %d\n", x);

    x++;
    printf("After x++: %d\n", x);

    ++x;
    printf("After ++x: %d\n", x);

    x--;
    printf("After x--: %d\n", x);

    --x;
    printf("After --x: %d\n", x);

    // Second part:
    int a = 7;
    int b = a++;

    printf("\nPost-increment:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    int c = 7;
    int d = ++c;

    printf("\nPre-increment:\n");
    printf("c = %d\n", c);
    printf("d = %d\n", d);

    return 0;
}