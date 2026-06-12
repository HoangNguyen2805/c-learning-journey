#include <stdio.h>

int main() {

    int x = 5;
/*
    x++  adds 1
    ++x  adds 1
    x--  subtracts 1
    --x  subtracts 1

    a++ means use a first, then add 1
    ++c means add 1 first, then use c
*/
    printf("--- Increment and Decrement ---\n");

    printf("Staring x = %d\n", x);      // x = 5

    x++;                                // x Increase by 1
    printf("After x++, x = %d\n", x);   // x = 6

    ++x;                                // x Increase by 1
    printf("After ++x, x = %d\n", x);   // x = 7

    x--;                                // x Decrease by 1
    printf("After x--, x = %d\n", x);   // x = 6

    --x;                                // x Decrease by 1
    printf("After --x, x = %d\n", x);   // x = 5

    printf("\n--- Post-increment vs Pre-increment ---\n");

    int a = 5;         // a start at 5, then
    int b = a++;       // b = a++ mean:
                       //       1. put current a into b
                       //          b = 5 to displace

                       //       2. then increase a
                       //          a = 6 to displace at top where a = a + 1

    printf("Post-increment:\n");
    printf("int a = 5;\n");
    printf("int b = a++;\n");
    printf("a = %d\n", a); // print value of a before increasing by 1
    printf("b = %d\n", b); // print value of b that is a AFTER increasing by 1

    int c = 5;         // c starts as 5
    int d = ++c;       // d = ++c means:
                       //      1. increase c first
                       //         d=6

                       //      2. then put c into
                       //         d = 6

    printf("Pre-increment:\n");
    printf("int a = 5;\n");
    printf("int b = ++c;\n");
    printf("c = %d\n", c); // print value of c before increasing by 1
    printf("d = %d\n", d); // print value of d that is a AFTER increasing by 1



    return 0;
 }

 /*
## Lesson 04E - Increment and Decrement

x++ means add 1 to x.
++x means add 1 to x.
x-- means subtract 1 from x.
--x means subtract 1 from x.

If the line is by itself, x++ and ++x do almost the same thing.

Example:

int x = 5;
x++;
// x becomes 6

++x;
// x becomes 7

The difference matters when it is inside another assignment.

Post-increment:

int a = 5;
int b = a++;

a++ means use old value first, then add 1.

Step:
b = 5
a = 6

Final:
a = 6
b = 5

Pre-increment:

int c = 5;
int d = ++c;

++c means add 1 first, then use the new value.

Step:
c = 6
d = 6

Final:
c = 6
d = 6

Memory rule:

x++ = use first, then add
++x = add first, then use

x-- = use first, then subtract
--x = subtract first, then use
 */