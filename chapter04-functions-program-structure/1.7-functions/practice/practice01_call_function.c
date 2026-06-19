/*
Practice 01 — call your own function.

Task

Make a program with 2 functions:

printWelcome()
printGoodbye()

printWelcome() should print:

Welcome to Day 07 Functions!

printGoodbye() should print:

Practice finished.

Inside main(), call both functions.

Expected output
--- Practice 01 ---
Welcome to Day 07 Functions!
Practice finished.
Requirements

Use:

#include <stdio.h>
void function
main()
function call
printf
return 0
Hint

Your structure should look like:

void printWelcome() {
    // print welcome message
}

void printGoodbye() {
    // print goodbye message
}

int main() {
    // print title
    // call printWelcome
    // call printGoodbye

    return 0;
}

Compile/run:

cd ~/c-learning-journey/01-c-basics/day07-functions/practice
gcc practice01_call_function.c -o practice01_call_function
./practice01_call_function

*/

#include <stdio.h>

void printWelcome() {
    printf("Welcome to Day 07 Functions !\n");
}

void printGoodbye() {
    printf("Practice finished.\n");
}

int main() {

    printf(" --- Practice 01 ---\n");
    
    printWelcome();
    printGoodbye();

    return 0;
}