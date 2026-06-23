/*
Practice 01 - Conditional Expressions

Goal:
Practice the main ideas from K&R 2.11 Conditional Expressions.

Requirements:

1. Include stdio.h.

2. Create two int variables:
   - a
   - b

3. Use a conditional expression to find:
   - the larger value
   - the smaller value

4. Print a, b, the larger value, and the smaller value.

5. Create an int variable:
   - score

6. Use a conditional expression to print:
   - "Pass" if score is at least 70
   - "Fail" otherwise

7. Create an int variable:
   - age

8. Use a conditional expression to print:
   - "Adult" if age is at least 18
   - "Not adult" otherwise

9. Use a conditional expression to print 1 or 0 for:
   - a > b
   - a == b
   - a != b

10. Add comments explaining:
   - conditional expression
   - condition
   - true value
   - false value
   - why parentheses help readability

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
   int a = 10;
   int b = 20;

   // 3.
   int max;
   int min; 
   max = ( a > b ) ? a : b;
   min = ( a < b ) ? a : b;

   // 4.
   printf("a = %d\n", a);
   printf("b = %d\n", b);
   printf("Larger = %d\n", max);
   printf("Smaller = %d\n", min);

   // 5.
   int score = 85;

   // 6.
   printf("%s\n", (score >= 70) ? "Pass" : "Fail" );

   // 7.
   int age = 24;

   // 8.
   printf("%s\n", (age >= 18) ? "Adult" : "Not adult" );

   // 9.
   printf("a > b: %d\n", (a > b)? 1 : 0);
   printf("a == b: %d\n", (a == b)? 1 : 0);
   printf("a != b: %d\n", (a != b)? 1 : 0);

   // 10.
// Conditional expression:
// A short way to choose between two values.
// Format: condition ? true_value : false_value

// Condition:
// The test that C checks first.
// If the condition is true, C uses the value before the colon.
// If the condition is false, C uses the value after the colon.

// True value:
// The value used when the condition is true.
// Example: in score >= 70 ? "Pass" : "Fail", "Pass" is the true value.

// False value:
// The value used when the condition is false.
// Example: in score >= 70 ? "Pass" : "Fail", "Fail" is the false value.

// Parentheses:
// Parentheses make the condition easier to read.
// They help show which part is being tested.

   return 0;
}