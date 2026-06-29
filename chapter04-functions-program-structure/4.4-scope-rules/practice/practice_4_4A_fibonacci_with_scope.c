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

// Given prompt
/*
#include <stdio.h>

int n = 0;   // EXTERNAL - tracks total Fibonacci numbers generated

int fib(int n);   // PARAMETER named n - which position to calculate

int main() {
    int n;   // LOCAL to main - how many numbers the user wants

    printf("Enter how many Fibonacci numbers to generate: ");
    scanf("%d", &n);

    printf("Fibonacci sequence:\n");

    return 0;
}
*/

#include <stdio.h>
// Step 3
int n = 0;   // EXTERNAL - tracks total Fibonacci numbers generated
             // The external n is a separate counter, completely unrelated 
             // to the Fibonacci math. Its only job: count how many Fibonacci 
             // numbers have actually been printed to the screen, across the 
             // whole program run. Since main()'s loop runs once per number 
             // printed, you want this counter to go up by exactly 1 each time through the loop.
void incrementCounter(void);
// so the external n = 0 will store the amount of first for loop inside main, the void function will be also call inside first for loop.

void showCount(void);
int fib(int n);   // PARAMETER named n - which position to calculate

int main() {
    int n;   // LOCAL to main - how many numbers the user wants

    printf("Enter how many Fibonacci numbers to generate: ");
    scanf("%d", &n);

    printf("Fibonacci sequence:\n");
    // Step 1:
    int i;
    for(i = 1; i <= n; i++){ // First loop is just to track how many time that function fib(i) should call base on user input n.
      printf("%d\n", fib(i));
      incrementCounter(); // step 3
      
    }

    showCount();
    return 0;
}
//Step 2
int fib(int n){
  int a = 1; // position 1
  int b = 1; // position 2
  // fib(3) should alwayu start at 3rd position because in Fibonacci first and second position is already both = 1.
  // if function is to prevent if user input is 1 or 2 because if fib(1) or fib(2) then we dont need the loop, just printf.

  if (n == 1 || n == 2){
    return 1; // <- stops here, hands back the number 1 to main
  } // in this case return non zero value doesnt mean function is failed.
  // It mean the Fibonacci number at the position fib() was asked to compute will besave and return to main function as data.
  // (anything below this would be SKIPPED if n was 1 or 2,
  //  because return already ended the function above)

  int i;
  int next;
  for(i = 3; i <= n; i++){// second for loop is to do Fibonacci calculation with already have 2 attemp , which first a = 1, then b = 1, so we start at i = 3 as third sequence.
    next = a + b;
    a = b;
    b = next;
  }
  return b; // Why return b ?
  /*
  reason to return is 

  b always holds the MOST RECENT Fibonacci number calculated.

  Every time the loop runs one round, b gets updated to the newest
  number in the sequence. By the time the loop finishes, b is sitting
  on exactly the number at position n - the answer we want.

  a is always ONE STEP BEHIND b (the previous number, not the current one),
  so returning a would give the wrong, earlier answer.

  Trace for n = 6, starting a = 1, b = 1:

  i    next = a+b    a = b    b = next     (a, b after)
  3    1+1 = 2        a=1      b=2         (1, 2)
  4    1+2 = 3        a=2      b=3         (2, 3)
  5    2+3 = 5        a=3      b=5         (3, 5)
  6    3+5 = 8        a=5      b=8         (5, 8)

  After the loop ends, b = 8 - and the 6th Fibonacci number IS 8.
  So we return b, because it's the variable that ends up holding
  the correct, final answer once the loop is done.

  So what does return b; actually do, if not stop the loop? It does two separate things, once the loop has already finished:

  It stops the function (fib()) — ends fib() entirely, no further lines run after this
  It hands the value of b back to main(), to be used (e.g., printed)
  It simply asks: "whatever b currently equals, right now, after the loop is fully done — send that number back to main."
  */
}

// with step 3
void incrementCounter(void) {
    n = n + 1;   // no local n exists here, so this reaches the EXTERNAL n directly
}

void showCount(void) {
    printf("Total Fibonacci numbers generated: %d\n", n);   // job: print the counter
}