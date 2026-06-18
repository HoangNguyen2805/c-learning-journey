/*
Practice 02

Create:

01-c-basics/day07-functions/practice/practice02_function_parameter.c

Task

Create a function:

void checkAge(int age)

The function should:

If age >= 18:
    print "Adult"

Else:
    print "Minor"

Inside main():

Use a while loop to ask for 3 ages.
Each time, call checkAge(age).
Example output
--- Practice 02 ---

Enter age 1: 17
Minor

Enter age 2: 18
Adult

Enter age 3: 25
Adult

Program finished.
Requirements
void function
parameter
scanf
while loop
if / else
function call
return 0

Compile/run:

cd ~/c-learning-journey/01-c-basics/day07-functions/practice
gcc practice02_function_parameter.c -o practice02_function_parameter
./practice02_function_parameter

*/

#include <stdio.h>

void checkAge(int age) {
    if (age >= 18) {
        printf("Adult\n");
    } else {
        printf("Minor\n");
    }
}

int main() {

    int age;
    int i = 1;

    printf("--- Practice 02 ---\n");

    while (i <= 3) {
        printf("\nEnter age %d: ", i);
        scanf("%d", &age);

        i++;

        checkAge(age);
    }

    return 0;
}