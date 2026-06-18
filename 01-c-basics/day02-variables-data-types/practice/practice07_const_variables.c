/*
Practice 07 — Const Variables

Make a program that asks for:

student name
score

Use these constants:

const int MAX_SCORE = 100;
const int PASSING_SCORE = 70;

Print:

--- Score Report ---
Name:
Score:
Max score:
Passing score:
Result:

Rules:

score >= 70 → Pass
score < 70  → Fail

Example input:

Enter name: Hoang
Enter score: 85

Expected output:

--- Score Report ---
Name: Hoang
Score: 85
Max score: 100
Passing score: 70
Result: Pass

Run:

cd ~/c-learning-journey/01-c-basics/day02-variables-data-types/practice
gcc practice07_const_variables.c -o practice07_const_variables
./practice07_const_variables

*/
#include <stdio.h>

int main() {
    
    const int MAX_SCORE = 100;
    const int PASSING_SCORE = 70;

    return 0;
}