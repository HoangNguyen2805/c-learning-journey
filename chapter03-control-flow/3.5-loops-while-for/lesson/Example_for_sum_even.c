/*
Practice 02 — for loop cumulative challenge.

Create:

01-c-basics/day06-loops/practice/practice02_for_sum_even.c
Task

Ask the user how many numbers they want to enter.

Then use a for loop to ask for that many numbers.

Your program must calculate:

sum of all numbers
count of even numbers
count of odd numbers
Example input
How many numbers: 5
Enter number 1: 10
Enter number 2: 7
Enter number 3: 4
Enter number 4: 9
Enter number 5: 2
Expected output
--- Result ---
Sum: 32
Even count: 3
Odd count: 2
Program finished.
Requirements

Use lessons from Day 01 to now:

printf
scanf
int variables
for loop
if / else
%
+=
++
Hint only
sum starts at 0
evenCount starts at 0
oddCount starts at 0

Inside the loop:
read number
add number to sum
check number % 2 == 0

Compile/run:

cd ~/Desktop/c-learning-journey/01-c-basics/day06-loops/practice
gcc practice02_for_sum_even.c -o practice02_for_sum_even
./practice02_for_sum_even

*/

#include <stdio.h>

int main() {

    int totalNumber;
    int number;
    int sum = 0;
    int evenNumber = 0;
    int oddNumber = 0;

    printf("How many numbers: ");
    scanf("%d", &totalNumber);

    for (int i = 1; i <= totalNumber; i++){
        printf("Enter number %d: ", i);
        scanf("%d", &number);
        sum += number;

        if ( number % 2 == 0 ) {
        evenNumber++;
    }

    if ( number % 2 == 1 ) {
        oddNumber++;
    }

    }

    printf("\n--- Result ---\n");
    printf("Sum: %d\n", sum);
    printf("Even count: %d\n", evenNumber);
    printf("Odd count: %d\n", oddNumber);
    printf("Program finished.\n");

    return 0;
}