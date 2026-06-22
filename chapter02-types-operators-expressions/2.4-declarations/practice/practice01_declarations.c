/*
Practice 01 - Declarations

Goal:
Practice the main ideas from K&R 2.4 Declarations.

Requirements:

1. Include stdio.h.

2. Declare variables first, then assign values later:
   - int age
   - double price
   - char grade

3. Declare and initialize variables in one line:
   - int score
   - double gpa
   - char letter

4. Declare multiple int variables in one line:
   - lower
   - upper
   - step

5. Assign values to lower, upper, and step.

6. Create const variables:
   - const int MAX_SCORE
   - const double TAX_RATE

7. Print every variable using the correct printf placeholder.

8. Add comments explaining:
   - declaration
   - initialization
   - assignment
   - const
   - why uninitialized local variables are dangerous

Rules:
- Do not use scanf.
- Do not use if/else.
- Do not use loops.
- Do not copy the lesson file exactly.
- Write it from memory first, then check your notes.
*/

#include <stdio.h>

int main() {

   // 2.
   int age;
   age = 25;

   double price;
   price = 9.99;

   char grade;
   grade = 'A';

   // 3.
   int score = 999;
   double gpa = 3.00;
   char letter = 'B';

   // 4.
   int lower , upper , step;
   // 5.
   lower = 0;
   upper = 100;
   step = 25;
   
   // 6.
   const int MAX_SCORE = 100;
   const double TAX_RATE = 0.0825;
   
   // 7.
   printf("2.\n");
   printf("Age: %d\n", age);
   printf("Price: $%.2f\n", price);
   printf("Grade: %c\n", grade);
   printf("\n3.\n");
   printf("Score: %d\n", score);
   printf("GPA: %.2f\n", gpa);
   printf("Letter: %c\n", letter);
   printf("\n4.\n");
   printf("\n5.\n");
   printf("Lower: %d\n", lower);
   printf("Upper: %d\n", upper);
   printf("Step: %d\n", step);
   printf("MAX_SCORE: %d\n", MAX_SCORE);
   printf("TAX_RATE: %.4f\n", TAX_RATE);

   /*
// Declaration:
// Telling C that a variable exists and what type of value it can hold.
int age;

// Initialization:
// Giving a variable its first value at the same time it is declared.
int score = 100;

// Assignment:
// Giving a value to a variable after it has already been declared.
age = 25;

// const:
// Makes a variable read-only after it is initialized.
const int MAX_SCORE = 100;

// Uninitialized local variables are dangerous:
// A local variable without a starting value may contain a garbage value.
// Using it before assigning a value can give wrong or unpredictable results.
int total;
   */

   return 0;
}