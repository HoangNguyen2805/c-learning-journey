/*
Practice 6, last practice before quiz.

Task

Ask user for:

name
student status

Expected output:

Enter your name: Hoang
Are you a student? Type 1 for yes, 0 for no: 1

--- Info ---
Name: Hoang
Student: 1

Hints only
name = char name[50];
student input = int student;

scanf for name = %s
scanf for int = %d

char[] does not use &
int uses &

Compile/run:

gcc practice06_read_name_bool.c -o practice06
./practice06
*/

#include <stdio.h>
#include <stdbool.h>

int main() {

    char name [50];
    bool isStudent;                 // You can not scanf directly to bool
    int studentInput;               // So we declare another the int 
                                      
    printf("Enter your name: ");

    scanf(" %s", name);

    printf("Are you a student? Type 1 for yes, 0 for no: ");
    
    scanf(" %d", &studentInput);

    isStudent = studentInput;      // and set it equal to each
                                   // other so we can use the interger value for scanf and printf.

    printf("--- Info ---\n");
    printf("Name: %s\n", name);
    printf("Student: %d\n", isStudent); // we want scanf assign value into int instead of bool's variable
                                           // but in print we still want to displace correct bool's variable

    return 0;
}