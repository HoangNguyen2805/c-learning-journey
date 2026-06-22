/*
Practice 01 - Arithmetic Operators

Goal:
Practice the main ideas from K&R 2.5 Arithmetic Operators.

Requirements:

1. Include stdio.h.

2. Create two int variables:

   * a = 10
   * b = 3

3. Print the values of a and b.

4. Print the result of:

   * a + b
   * a - b
   * a * b
   * a / b
   * a % b

5. Print these extra examples:

   * 10 / 3
   * 10 % 3
   * 10 % 2
   * 10 % 4
   * 10 + 2 * 5

6. Add comments explaining:

   * addition
   * subtraction
   * multiplication
   * integer division
   * remainder / modulus
   * why 10 / 3 gives 3
   * why % only works with integers
   * why dividing by zero is bad

Rules:

* Do not use scanf.
* Do not use if/else.
* Do not use loops.
* Do not copy the lesson file exactly.
* Write it from memory first, then check your notes.
  */

  #include <stdio.h>

  int main(){

   // 2.
   int a = 10;
   int b = 3;

   // 3.
   printf("\na = %d\n", a);
   printf("b = %d\n", b);

   // 4.
   printf("\na + b = %d\n", a + b);
   printf("a - b = %d\n", a - b);
   printf("a * b = %d\n", a * b);
   printf("a / b = %d\n", a / b);
   printf("a %% b = %d\n", a % b);

   // 5.
   int c = 2;
   int d = 4;
   int e = 5;

   printf("\n%d / %d = %d\n", a , b , a / b);
   printf("%d %% %d = %d\n", a , b , a % b);
   printf("%d %% %d = %d\n", a , c , a % c);
   printf("%d %% %d = %d\n", a , d , a % d);
   printf("%d + %d * %d = %d\n", a , c , e , a + c * e);

/*
   ```c
// Addition:
// The + operator adds two numbers.
printf("\na + b = %d\n", a + b);

// Subtraction:
// The - operator subtracts the second number from the first number.
printf("a - b = %d\n", a - b);

// Multiplication:
// The * operator multiplies two numbers.
printf("a * b = %d\n", a * b);

// Integer division:
// Since a and b are both int, a / b gives a whole-number answer.
// 10 / 3 gives 3, not 3.333, because the decimal part is cut off.
printf("a / b = %d\n", a / b);

// Remainder / modulus:
// The % operator gives the leftover amount after integer division.
// 10 % 3 gives 1 because 3 goes into 10 three times with 1 left over.
printf("a %% b = %d\n", a % b);

// The % operator only works with integers.
// It cannot be used with float or double values.

// Dividing by zero is bad because C cannot divide a number by 0.
// Example: 10 / 0 or 10 % 0 would cause an error or crash.
```
*/

   return 0;
  }