/*
Practice 03 — Password Retry

Create:

practice03_password_retry.c
Task

Ask the user to enter a PIN.

Correct PIN is:

1234

Use a do while loop so the program keeps asking until the user enters the correct PIN.

When correct, print:

Access granted.
Example run
Enter PIN: 1111
Wrong PIN. Try again.

Enter PIN: 5555
Wrong PIN. Try again.

Enter PIN: 1234
Access granted.
Program finished.
Requirements

Use:

int pin
do while
scanf
if / else
!=
Hint only
do {
    ask for pin
    read pin

    if pin is wrong
        print wrong message
    else
        print access granted

} while pin is not 1234

Compile/run:

cd ~/Desktop/c-learning-journey/01-c-basics/day06-loops/practice
gcc practice03_password_retry.c -o practice03_password_retry
./practice03_password_retry

*/

#include <stdio.h>

int main() {

    int pin;

    do {
        printf("Enter PIN: ");
        scanf("%d", &pin);

        if ( pin != 1234 ){
            printf(" PIN incorrect. Try again.\n");
        } else {
            printf("Access granted.\n");
        }
    } while ( pin != 1234 );

    return 0;
}