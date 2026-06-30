/*
Practice 4.7A - Register vs Normal Local Variables

Book Level:
K&R 1.1 through 4.7 (register variables)

Problem:
This is a SHORT, conceptual practice (4.7 is a lightweight, mostly
historical section - no heavy DSA problem fits here, same as Ch.4.3's
external variable section).

Build a simple program that sums numbers from 1 to N, using a register
variable as the loop counter, and a register variable as the running sum.

Then, in a SEPARATE function, do the exact same calculation using
normal (non-register) variables - to prove they produce IDENTICAL
results, since register is only a hint, not a different calculation.

Functions required:
* long sumWithRegister(int n) -> uses register int i and register long sum
  internally, loops from 1 to n adding each number, returns the total
* long sumNormal(int n) -> does the EXACT same calculation, but with
  plain (non-register) int i and long sum

Requirements:
* Both functions must produce the SAME answer for the same input -
  prove this by calling both and comparing.
* Ask the user for n, call both functions, print both results, and
  print whether they match.

Example:
Enter n: 100
sumWithRegister(100) = 5050
sumNormal(100) = 5050
Results match: YES

Why this matters (the real lesson):
register is ONLY a hint to the compiler about optimization - it does
NOT change what a variable can do, what values it holds, or how
calculations work. The two functions should behave IDENTICALLY in
every way except (theoretically) speed, which you cannot observe
directly without specialized tools - so for everyday purposes,
register and normal local variables are functionally interchangeable.

Program Requirements:
* Use prototypes above main (Ch.4.1).
* Use a for loop in both functions (Ch.3).
* Use long (not int) for the sum, since sums can get large (Ch.2).
* Compare both results with if/else and print whether they match (Ch.3).

Rules:
* Do not use arrays.
* Do not take the address (&) of any register variable - this will
  not compile.
* Try from memory first.
*/
/*
#include <stdio.h>

int main() {

    return 0;
}
*/

#include <stdio.h>

int main() {

    return 0;
}