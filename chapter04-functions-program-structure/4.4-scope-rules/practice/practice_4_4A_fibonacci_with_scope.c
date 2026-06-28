/*
Practice 4.4A - Cumulative: Fibonacci with Deliberate Scope Collisions

Book Level:
K&R 1.1 through 4.4 (scope rules)

Classic DSA Problem:
Generate the first N numbers of the Fibonacci sequence
(1, 1, 2, 3, 5, 8, 13, 21...) where each number is the sum of the
two before it.

THE SCOPE TWIST (the actual point of this practice):
You MUST use a variable named "n" in THREE different places, and they
must NOT interfere with each other:

1. An EXTERNAL variable called "n" that tracks how many Fibonacci
   numbers have been generated so far (starts at 0).
2. A LOCAL variable called "n" inside main() that stores how many
   numbers the USER wants generated (the input value).
3. A PARAMETER called "n" inside a function fib(int n) that calculates
   the Nth Fibonacci number directly using a for loop (iteratively,
   not recursively - recursion is Ch.4.10, not yet).

Requirements:
* int fib(int n) -> takes which position in the sequence (1st, 2nd, 3rd...)
  and returns that Fibonacci number, using a FOR loop internally.
* The external "n" must be incremented once per number actually printed
  (i.e., it counts total numbers generated across the whole program).
* main()'s local "n" stores how many numbers the user asked for - this
  is DIFFERENT from the external "n" and must stay correct throughout.
* Use a for loop in main() to call fib() that many times and print each result.
* After the loop, print the external n's final value as "Total Fibonacci
  numbers generated: X" - this proves the external counter tracked
  correctly without being confused by the other two "n" variables.

Example:
Enter how many Fibonacci numbers to generate: 6
Fibonacci sequence:
1
1
2
3
5
8
Total Fibonacci numbers generated: 6

Why this matters (the real lesson):
If you confuse main()'s local n with the external n, or accidentally
let fib()'s parameter n leak into either of the others, your program
will either crash, print the wrong count, or behave unpredictably.
Getting this right means you ACTUALLY understand scope - not just
"passing" because the variables happened to have different names.

Program Requirements:
* Use prototypes above main (Ch.4.1).
* Use a FOR loop in fib() to compute the Nth Fibonacci number (Ch.3).
* Use a FOR loop in main() to call fib() repeatedly (Ch.3 - and a
  genuine non-do-while loop this time).
* The external "n" counter and main()'s local "n" must NOT collide
  or produce wrong output.

Rules:
* Do not use arrays (you don't know them yet - store/compute fib
  values using just a few int variables inside fib(), not a list).
* Do not use recursion (that's 4.10 - use a for loop instead).
* Do not rename any of the three "n" variables - the whole point is
  proving you can keep three same-named variables straight.
* Try from memory first.
*/

#include <stdio.h>

int n = 0;   // EXTERNAL - tracks total Fibonacci numbers generated

int fib(int n);   // PARAMETER named n - which position to calculate

int main() {
    int n;   // LOCAL to main - how many numbers the user wants

    printf("Enter how many Fibonacci numbers to generate: ");
    scanf("%d", &n);

    printf("Fibonacci sequence:\n");

    int a = 1; // position 1
    int b = 1; // position 2
    int i; // so i start at position 3
    extern result;
    Z
    for(i = 3; i <= n ; i++){ // n is
      fib(n);
      b = a;
      result = b;

    } 

    return 0;
}

int fib(int n){
    int result;
    a + b = result;
    return result;
}