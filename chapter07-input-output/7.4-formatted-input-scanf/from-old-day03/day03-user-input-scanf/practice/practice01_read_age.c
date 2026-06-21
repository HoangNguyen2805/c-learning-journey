/*
Practice 1

Task: ask the user for their age, then print it back.

Your output should look like:

Enter your age: 25
Your age is 25.


Compile/run:

cd ~/c-learning-journey/01-c-basics/day03-user-input-scanf/practice
gcc practice01_read_age.c -o practice01
./practice01

*/

#include <stdio.h>

int main() {

    int age;

    printf("Enter your age: ");

    scanf("%d", &age);

    printf("Your age is: %d.\n", age);

    return 0;
}