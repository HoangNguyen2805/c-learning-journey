/*
Practice 1.2.3 — Integer Square Root

Store 2000 in an int. Print the largest integer r such that r * r <= 2000.
For 2000 the answer is 44, because 44*44 = 1936 and 45*45 = 2025.

You must not use float, and you must not use any math library. Only int
arithmetic and a while loop.

Constraints:
- The answer must be computed, not looked up or guessed
- It must be correct for perfect squares too: 144 must give exactly 12
- Do not include <math.h>

Hint, not a solution:
  The simplest correct approach counts upward. Start a candidate at 0 or 1
  and keep going while some condition still holds. The whole exercise is
  working out what that condition is, and noticing that when the loop stops,
  your candidate has gone one step too far.

  Write the condition wrong on purpose first — use < instead of <=, or check
  after incrementing instead of before — and run it on 144. Off-by-one errors
  are easiest to understand when you have just caused one.

DSA concept: linear search over a monotonic predicate
Approach: increment while the square still fits, then step back
Time: O(sqrt n)
Space: O(1)

Extension, only after the basic version works: r*r overflows an int long
before n does. Rewrite the loop condition so it never computes r*r at all.
Division can compare the same two quantities without the multiply. This is a
real technique, not a trick.

Note there is a much faster method — binary search on the answer, O(log n).
You do not have the tools for it cleanly yet. Come back to this file after
Chapter 3.
*/

#include <stdio.h>

int main()
{

    return 0;
}
