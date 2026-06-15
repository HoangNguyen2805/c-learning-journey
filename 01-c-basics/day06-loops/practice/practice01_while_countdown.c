/*
Practice 01 — while loop cumulative challenge.

Create:

01-c-basics/day06-loops/practice/practice01_while_countdown.c
Task

Ask the user for a starting number.

Use a while loop to count down from that number to 1.

Then print:

Blast off!
Example

Input:

Enter starting number: 5

Output:

5
4
3
2
1
Blast off!
Requirements

Use:

scanf
printf
int
while
condition
decrement --
Compile/run
cd ~/c-learning-journey/01-c-basics/day06-loops/practice
gcc practice01_while_countdown.c -o practice01_while_countdown
./practice01_while_countdown

*/

#include <stdio.h>

int main() {

    int i;

    printf("Enter starting number: ");
    scanf("%d", &i);

    while (i >= 1) {
        printf("%d\n", i);
        i--;
    }

    printf("Blast off!\n");
    return 0;
}