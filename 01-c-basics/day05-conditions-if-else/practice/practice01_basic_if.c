/*
Practice 01
Task

Ask the user for their age using scanf.

Then:

If age is 18 or older, print:

You can vote.

Always print:

Program finished.
Example 1

Input:

Enter age: 21

Output:

Age: 21
You can vote.
Program finished.
Example 2

Input:

Enter age: 16

Output:

Age: 16
Program finished.

Notice: for age 16, it should not print You can vote.

Requirements

Use:

18 is the youngest age to vote
int age
scanf
if
>=

Compile/run:

cd ~/c-learning-journey/01-c-basics/day05-conditions-if-else/practice
gcc practice01_basic_if.c -o practice01_basic_if
./practice01_basic_if

*/

#include <stdio.h>

int main() {

    int age;

    printf("Enter age: ");
    scanf("%d", &age);

    printf("Age: %d\n", age);

    if (age >= 18){
        printf("You can vote.\n");
    }

    printf("Program finished.\n");

    return 0;
}