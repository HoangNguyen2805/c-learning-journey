  /*
Practice 01 - Increment and Decrement Operators

Goal:
Practice the main ideas from K&R 2.8.

Requirements:

1. Include stdio.h.

2. Create an int variable:
   - x = 10

3. Print x.

4. Use and print x after:
   - x++
   - ++x
   - x--
   - --x

5. Create a post-increment example:
   - int a = 7;
   - int b = a++;

6. Print a and b.

7. Create a pre-increment example:
   - int c = 7;
   - int d = ++c;

8. Print c and d.

9. Create a post-decrement example.

10. Create a pre-decrement example.

11. Add comments explaining:
   - increment
   - decrement
   - post-increment
   - pre-increment
   - post-decrement
   - pre-decrement

Rules:
- Do not use scanf.
- Do not use if/else.
- Do not use loops.
- Do not copy the lesson file exactly.
- Write it from memory first, then check your notes.
*/

#include <stdio.h>

int main () {

   // 2.
   int x = 10;

   // 3.
   printf("x = %d\n", x);

   // 4.
   x++;
   printf("x++ = %d\n", x);

   ++x;
   printf("++x = %d\n", x);
   
   x--;
   printf("x-- = %d\n", x);
   
   --x;
   printf("--x = %d\n", x);

   // 5.
   int a = 7;
   int b = a++;

   // 6. 
   printf("a = %d\n", a);
   printf("b = %d\n", b);

   // 7.
   int c = 7;
   int d = ++c;

   // 8.
   printf("c = %d\n", c);
   printf("d = %d\n", d);

   // 9.
   int e = 7;
   int f = e--;

   printf("e = %d\n", e);
   printf("f = %d\n", f);

   // 10.

   int g = 7;
   int h = --g;

   printf("g = %d\n", g);
   printf("h = %d\n", h);

   // 11.
   /*
   ```c
// Increment:
// The ++ operator increases a variable by 1.
x++;

// Decrement:
// The -- operator decreases a variable by 1.
x--;

// Post-increment:
// x++ uses the old value first, then increases x by 1.
y = x++;

// Pre-increment:
// ++x increases x by 1 first, then uses the new value.
y = ++x;

// Post-decrement:
// x-- uses the old value first, then decreases x by 1.
y = x--;

// Pre-decrement:
// --x decreases x by 1 first, then uses the new value.
y = --x;
```

   */
   
   return 0;
}