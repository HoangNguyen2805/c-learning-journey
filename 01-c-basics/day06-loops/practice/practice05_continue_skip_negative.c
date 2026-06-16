/*
Practice 05 — continue challenge.

Create:

01-c-basics/day06-loops/practice/practice05_continue_skip_negative.c
Task

Ask the user to enter 5 numbers.

Use a for loop.

If the number is negative, skip it using continue.

Add only zero or positive numbers into sum.

Example run
Enter number 1: 5
Enter number 2: -3
Negative number skipped.
Enter number 3: 10
Enter number 4: -2
Negative number skipped.
Enter number 5: 4

--- Result ---
Sum: 19
Program finished.

Why sum is 19:

5 + 10 + 4 = 19

Negative numbers are skipped.

Requirements

Use:

for loop
scanf
if
continue
sum += number
Hint only
sum starts at 0

inside loop:
    ask for number
    if number < 0:
        print skipped message
        continue

    add number to sum

Compile/run:

cd ~/c-learning-journey/01-c-basics/day06-loops/practice
gcc practice05_continue_skip_negative.c -o practice05_continue_skip_negative
./practice05_continue_skip_negative

Test with:

5
-3
10
-2
4

*/

#include <stdio.h>

int main() {

    int number;
    int sum = 0;


    for ( int i = 1; i <= 5; i++){
        printf("Enter number %d: ", i);
        scanf("%d", &number);

        if ( number < 0) {
                    printf("Negative number skipped.\n");
                    continue;
                }

        sum += number;

    }

    printf("\n--- Result ---\n");
    printf("Sum: %d\n", sum);
    printf("Program finished.\n");

    return 0;
}