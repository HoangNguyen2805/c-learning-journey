/*
Practice 1.2.2 — Reverse a Number

Store 12045 in an int. Print 54021.

This is a build on 1.2.1: same peeling loop, but instead of adding each digit
to a running total, you assemble them into a new number.

Constraints:
- No arrays, no strings, no functions
- The result must be an int you print once at the end with %d, not a series
  of digits printed one at a time inside the loop

Hint, not a solution:
  Suppose you have built up 54 so far and the next digit you peel is 0.
  You need 540. What single arithmetic step turns 54 into 540 before you
  add the new digit? Now do it again with the digit 2 to reach 5402.

  Printing digits one at a time as you peel them is a different, easier
  program. Notice why it is easier, then do the harder one.

DSA concept: accumulator pattern — building a result across loop iterations
Approach: result = result * 10 + newdigit, repeated
Time: O(log n)
Space: O(1)

Follow-up to answer in a comment: reversing 1200 gives 21. Reversing 21 gives
12, not 1200. Why is this operation not reversible, and where did the
information go?
*/

#include <stdio.h>

int main()
{

    return 0;
}
