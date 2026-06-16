/*
Task

Ask the user to enter 5 numbers.

Use a for loop.

If the user enters 0, stop the loop immediately using break.

Add all non-zero numbers into sum.

Example run
Enter number 1: 5
Enter number 2: 8
Enter number 3: 0
Zero entered. Stopping loop.

--- Result ---
Sum: 13
Program finished.

Notice:

Number 4 and 5 are not asked
because 0 stopped the loop.
Requirements

Use:

for loop
scanf
if
break
sum += number
Hint only
sum starts at 0

inside loop:
    ask for number
    if number is 0
        print stop message
        break
    add number to sum

Compile/run:

cd ~/c-learning-journey/01-c-basics/day06-loops/practice
gcc practice04_break_stop_at_zero.c -o practice04_break_stop_at_zero
./practice04_break_stop_at_zero

*/

#include <stdio.h>

int main (){

    int number;
    int sum = 0;

    for (int i = 1; i <= 5; i++) {
        printf("Enter number %d: ", i);
        scanf("%d", &number);

        if ( number == 0){
            printf("Zero entered. Stopping loop.\n");
            break;
        }

        sum += number;

        
    }
    printf("\n--- Result ---\n");
    printf("Sum: %d\n", sum);
    printf("Program finished.\n");

    return 0;
}