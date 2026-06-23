/*
Practice 01 - If-Else

Goal:
Practice the main ideas from K&R 3.2 If-Else.

Requirements:

1. Include stdio.h.

2. Create an int variable:

   * score

3. Use an if statement:

   * if score is at least 70, print "Passing score"

4. Use an if-else statement:

   * if score is at least 70, print "Pass"
   * otherwise, print "Fail"

5. Create an int variable:

   * age

6. Use if-else:

   * if age is at least 18, print "Adult"
   * otherwise, print "Not adult"

7. Create an int variable:

   * hasID

8. Create a nested if example:

   * first check age
   * then check hasID

9. Use braces when multiple statements belong to the same if or else.

10. Add comments explaining:

* if
* else
* condition
* block
* nested if
* dangling else problem
* why braces help

Rules:

* Do not use scanf.
* Do not use loops.
* Do not use else-if yet.
* Do not copy the lesson file exactly.
* Write it from memory first, then check your notes.
  */

#include <stdio.h>

int main() {
   
   // 2.
   int score = 90;

   // 3. If statement
   if (score >= 70) {
      printf("Passing score\n");
   }

   // 4. If-else statement
   if (score >= 70) {
      printf("Pass\n");
   } else {
      printf("Fail\n");
   }

   // 5.
   int age = 27;

   // 6.
   if (age >= 18) {
      printf("Adult\n");
   } else {
      printf("Not adult\n");
   }

   // 7. 
   int hasID = 1;

   // 8. and 9.
   if (age >= 18) {
      if (hasID == 1) {
         printf("You are good to to go!\n");
      } else {
         printf("Sorry ! You need to have an ID!\n");
      }
   } else {
      printf("Sorry! You're not old enough!\n");
   }

   // 10.

// If:
// An if statement checks a condition.
// If the condition is true, the statement or block under it runs.

// Else:
// Else runs when the if condition is false.

// Condition:
// The condition is the test inside parentheses.
// Example: age >= 18

// Block:
// A block is a group of statements inside { }.
// Blocks let multiple statements belong to the same if or else.

// Nested if:
// A nested if is an if statement inside another if statement.

// Dangling else problem:
// This happens when it is unclear which if an else belongs to.
// In C, an else matches the nearest unmatched if.

// Why braces help:
// Braces make it clear which statements belong to each if or else.
// Beginners should use braces to avoid confusion.


   return 0;
}