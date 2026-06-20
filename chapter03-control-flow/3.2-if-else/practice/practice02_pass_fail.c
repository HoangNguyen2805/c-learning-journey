/*
Practice 02 — Cumulative if / else Challenge.
Task
Ask the user for their exam score.

Then:

If score is 70 or higher, print:

You passed.

Else print:

You failed.

Always print:

Program finished.
Example 1

Input:

Enter score: 85

Output:

Score: 85
You passed.
Program finished.
Example 2

Input:

Enter score: 60

Output:

Score: 60
You failed.
Program finished.
Requirements

Use everything we learned so far:

int variable
scanf
printf
if
else
>=

Compile/run:

cd ~/c-learning-journey/01-c-basics/day05-conditions-if-else/practice
gcc practice02_pass_fail.c -o practice02_pass_fail
./practice02_pass_fail

*/

#include <stdio.h>

int main() {

    int score;

    printf("Enter score: ");
    scanf("%d", &score);

    printf("Score: %d\n", score);

    if (score >= 70) {
        printf("You passed.\n");
    } else {
        printf("You failed.\n");
    }

    printf("Program finished.\n");

    return 0;
}