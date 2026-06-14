/*
Practice 03 — cumulative else-if challenge.

Task: ask for age, then print ticket price:

Age 0-12: Child ticket: $5
Age 13-17: Teen ticket: $8
Age 18 and up: Adult ticket: $12

Expected tests:

Enter age: 10
Child ticket: $5

Enter age: 15
Teen ticket: $8

Enter age: 25
Adult ticket: $12

Requirements:

scanf
if
else if
else
<=

Compile/run:

cd ~/c-learning-journey/01-c-basics/day05-conditions-if-else/practice
gcc practice03_ticket_price.c -o practice03_ticket_price
./practice03_ticket_price

*/

#include <stdio.h>

int main() {

    int age;

    printf("Enter age: ");
    scanf("%d", &age);

    if ( age >= 18 ) {
        printf("Adult ticket: $12\n");
    } else if ( age >= 13 && age <= 17 ) {
        printf("Teen ticket: $8\n");
    } else {        // else ( age <= 12 ) -> this is wrong, else is FAULT, else should not have a conmdition at all
        printf("Child ticket: $5\n");
    }

    return 0;
}