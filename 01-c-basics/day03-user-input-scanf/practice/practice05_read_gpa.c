/*
Practice 5

This one uses double.

Create:

practice05_read_gpa.c

Task: ask user for GPA, then print it with 2 decimals.

Expected output:

Enter GPA: 3.75
Your GPA is 3.75.

Hints:

GPA should be double
scanf for double uses %lf
printf for double can use %.2f

Compile/run:

gcc practice05_read_gpa.c -o practice05
./practice05

Rule:

scanf double = %lf
printf double = %.2f

*/

#include <stdio.h>

int main() {

    double gpa;

    printf("Enter GPA: ");
    scanf("%lf", &gpa);

    printf("Your GPA is: %.2f\n", gpa);

    return 0;
}