./practice01_temperature_table_for/*Practice 2 — Fix errors

Create:

practice02_fix_errors.c

Paste this broken code:

*

#include <stdio.h>

int main() {
    printf("Hello C!\n")
    printf("I am fixing errors\n");
    printf("C needs semicolons\n")
    return 0;
}

*

Fix it so the output is:

Hello C!
I am fixing errors
C needs semicolons

Compile and run:

gcc practice02_fix_errors.c -o practice02
./practice02
 
Start here:
*/

#include <stdio.h>

int main() {
    printf("Hello C!\n"); // <- missing a semicolon
    printf("I am fixing errors\n");
    printf("C needs semicolons\n"); // <- missing a semicolon
    
    return 0;
}