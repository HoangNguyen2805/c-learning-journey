/*Practice 1 — Student info

Write a program that uses variables and prints this output:

Name: Hoang
Age: 25
Grade: A
GPA: 3.75
Is student: 1

You must use these variables:

char name[] = "Hoang";
int age = 25;
char grade = 'A';
double gpa = 3.75;
bool isStudent = true;

Remember, because you use bool, you need:

#include <stdbool.h>

Compile and run:

cd ~/c-learning-journey/01-c-basics/day02-variables-data-types/practice
gcc practice01_student_info.c -o practice01
./practice01
*/

#include <stdio.h>
#include <stdbool.h>

int main() {

    char name[] = "Hoang";
    int age = 25;
    char grade = 'A';
    float gpa = 3.75;
    bool isStudent = 1;


    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("Grade: %c\n", grade);
    printf("GPA: %.2f\n", gpa);
    printf("Is Student: %d\n", isStudent);

    return 0;
}