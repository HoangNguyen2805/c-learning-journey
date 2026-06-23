/*
Practice 01 - Statements and Blocks

Goal:
Practice the main ideas from K&R 3.1 Statements and Blocks.

Requirements:

1. Include stdio.h.

2. Create two int variables.

3. Use simple statements to:

   * assign values to both variables
   * print both variables

4. Create a block using { }.

5. Inside the block:

   * create one new int variable
   * assign it a value using the first two variables
   * print it

6. After the block, print one more message.

7. Add comments explaining:

   * statement
   * semicolon
   * block
   * why blocks are useful

Rules:

* Do not use scanf.
* Do not use if/else yet.
* Do not use loops yet.
* Do not copy the lesson file exactly.
* Write it from memory first, then check your notes.
  */

  #include <stdio.h>

  int main() {

   // 2.
   int a;
   int b;

   // 3.
   a = 10;
   b = 20;
   printf("a = %d\n", a);
   printf("b = %d\n", b);

   // 4.
   {
      // 5.
      int c;

      c = a + b;
      printf("Inside another block. c = %d\n", c);
   }
   // 6.
   printf("Out side the block.\n");

   // 7.
/*
// Statement:
// A statement is one complete instruction for C to do.
// Most simple statements end with a semicolon.
a = 10;

// Semicolon:
// The semicolon tells C that the statement is finished.
b = 20;

// Block:
// A block is a group of statements inside braces { }.
// Variables created inside a block only belong to that block.
{
    int c;

    c = a + b;
    printf("Inside another block. c = %d\n", c);
}

// Why blocks are useful:
// Blocks let multiple statements stay together.
// They are used in functions, if/else, loops, and switch statements.
printf("Outside the block.\n");
*/

   return 0;
  }