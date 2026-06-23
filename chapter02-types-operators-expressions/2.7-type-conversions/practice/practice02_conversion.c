/*
Practice 01 - Type Conversions

Goal:
Practice the main ideas from K&R 2.7 Type Conversions.

Requirements:

1. Include stdio.h.

2. Create two int variables:
   - a = 10
   - b = 3

3. Print integer division:
   - a / b

4. Print decimal division using a cast:
   - (double) a / b

5. Create an expression that mixes int and double:
   - int value plus double value

6. Create a char digit:
   - char digitChar = '8';

7. Convert the char digit to an int value using:
   - digitChar - '0'

8. Create a char letter:
   - char letter = 'A';

9. Print the letter as:
   - character using %c
   - integer code using %d

10. Create a double value with a decimal part.

11. Assign that double value to an int variable.

12. Print both values and notice what is lost.

13. Add comments explaining:
   - automatic conversion
   - cast
   - integer division
   - decimal division
   - char to int conversion
   - assignment conversion
   - why double to int can lose information

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
   int b = 3;
   double c = 4.5;

   // 3.
   printf("3. a / b = %d\n", a / b);

   // 4.
   printf("4. (double) a / b = %f\n", (double) a / b);

   // 5.
   printf("5. a + c = %.2f\n", a + c);

   // 6.
   char digitChar = '8';// '8' = character code 56
   printf("6. char digitChar = '%c';\n", digitChar);

   // 7.
   // char digitChar = '8';
   int digitValue;
                         // '0' = character code 48
   digitValue = digitChar - '0'; // 56 - 48 = 8

   printf("7. Character digit: %c\n", digitChar);
   printf("Integer value: %d\n", digitValue);

   // 8.
   char letter = 'A';

   // 9. 
   printf("9. letter as character using %%c: %c\n", letter);
   printf("9. letter as integer code using %%d: %d\n", letter);

   // 10.
   double d = 5.55;

   // 11.
   int wholeNumber = d;

   // 12.
   printf("12. Double value: %.2f\n", d);
   printf("12. Int value: %d\n", wholeNumber);

   // 13.
   /*

// Automatic conversion:
// C can automatically convert one type to another when needed.
// Example: if an int is used with a double, the int is converted to double.

// Cast:
// A cast temporarily changes a value to another type for one expression.
// Example: (double) a treats a as a double only for that calculation.

// Integer division:
// When both numbers are int, division gives an int result.
// Example: 10 / 3 gives 3, not 3.333.

// Decimal division:
// If at least one number is double or float, division gives a decimal result.
// Example: 10.0 / 3 gives 3.333333.

// Char to int conversion:
// Characters are stored as integer codes.
// Example: '7' - '0' gives the integer value 7.

// Assignment conversion:
// When assigning a value to a variable, C converts the value to the variable's type.
// Example: int dollars = price; converts price to int.

// Why double to int can lose information:
// double can store decimals, but int cannot.
// Example: 9.99 becomes 9, so the .99 is lost.
   */

   return 0;
}