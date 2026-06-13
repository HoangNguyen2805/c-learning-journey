#include <stdio.h>

int main() {
    int result1 = 10 + 3 * 2;
    int result2 = (10 + 3) * 2;

    int result3 = 20 / 5 * 2;
    int result4 = 20 / (5 * 2);

    int result5 = 20 - 5 - 2;
    int result6 = 20 - (5 - 2);

    printf("--- Precedence and Parentheses ---\n");

    printf("10 + 3 * 2 = %d\n", result1);
    printf("(10 + 3) * 2 = %d\n", result2);

    printf("\n20 / 5 * 2 = %d\n", result3);
    printf("20 / (5 * 2) = %d\n", result4);

    printf("\n20 - 5 - 2 = %d\n", result5);
    printf("20 - (5 - 2) = %d\n", result6);

    return 0;
}

/*
## Lesson 04F - Precedence and Parentheses

Precedence means the order C does math.

C does:

1. Parentheses first: ()
2. Multiplication, division, modulus next: * / %
3. Addition and subtraction next: + -
4. Assignment last: =

Example:

10 + 3 * 2 = 16

C does 3 * 2 first, then adds 10.

But:

(10 + 3) * 2 = 26

Parentheses force 10 + 3 to happen first.

If operators have the same precedence, C usually goes left to right.

Example:

20 / 5 * 2 = 8

C does:

20 / 5 = 4
4 * 2 = 8

Subtraction also goes left to right.

20 - 5 - 2 = 13

C does:

20 - 5 = 15
15 - 2 = 13

Parentheses can change the answer:

20 - (5 - 2) = 17

C does:

5 - 2 = 3
20 - 3 = 17

Memory rule:

Parentheses first.
Then * / %.
Then + -.
Use parentheses when the order might be confusing.
*/