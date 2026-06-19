/*
Practice 3

Task: ask the user for one letter grade, then print it back.

Expected output:

Enter grade: A
Your grade is A.


Compile and run:

gcc practice03_read_grade.c -o practice03
./practice03

*/
#include <stdio.h>

int main() {

    char grade;

    printf("Enter grade: ");

    scanf("%c", &grade);

    printf(" Your grade is %c.\n", grade);

    return 0;
}