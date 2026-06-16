/*
Practice 06 — cumulative loop challenge.

Task

Ask the user to enter numbers.

Rules:

User can enter up to 10 numbers.
If user enters 0, stop early using break.
If user enters a negative number, skip it using continue.
Only positive numbers count.

Your program must calculate:

sum of positive numbers
count of positive numbers
even count
odd count
Example run
Enter number 1: 5
Enter number 2: -3
Negative number skipped.
Enter number 3: 10
Enter number 4: 7
Enter number 5: 0
Zero entered. Stopping loop.

--- Result ---
Sum: 22
Positive count: 3
Even count: 1
Odd count: 2
Program finished.

Why:

5 + 10 + 7 = 22
positive numbers: 5, 10, 7 = 3
even: 10 = 1
odd: 5, 7 = 2
Requirements

Use:

for loop
scanf
if / else
break
continue
sum += number
count++
%

Compile/run:

cd ~/c-learning-journey/01-c-basics/day06-loops/practice
gcc practice06_loop_summary.c -o practice06_loop_summary
./practice06_loop_summary

Test with:

5
-3
10
7
0

*/

#include <stdio.h>

int main() {

    int number;
    int sum = 0;
    int evenNumber = 0;
    int oddNumber = 0;
    int possitiveCount = 0;

    for ( int i = 1; i <= 10; i++ ) {
        printf("Enter number %d: ", i);
        scanf("%d", &number);

        if ( number < 0 ) {
            printf("Negative number skipped.\n");
            continue;
        }

        if ( number > 0) {
            possitiveCount++;
        }
        
        if ( number == 0 ) {
            printf("Zero entered. Stopping loop.\n");
            break;
        }

        if ( number % 2 == 0 ) {
            evenNumber++;
        } else {
            oddNumber++;
        }

        sum += number;

    }

    printf("\n--- Result ---\n");
    printf("Sum: %d\n", sum);
    printf("Positive count: %d\n", possitiveCount);
    printf("Even count: %d\n", evenNumber);
    printf("Odd count: %d\n", oddNumber);
    printf("Program finished.\n");
    

    return 0;
}