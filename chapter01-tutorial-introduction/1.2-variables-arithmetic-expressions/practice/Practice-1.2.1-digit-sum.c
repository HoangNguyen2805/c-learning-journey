/*
Practice 1.2.1 — Digit Sum

Read the number 9375 as a fixed value in your program. Print the sum of its
digits (9 + 3 + 7 + 5 = 24). Then print the number of digits (4).

You may not use arrays, strings, or functions — you do not have them yet.
Everything you need is int arithmetic and a while loop.

Constraints:
- The number must be stored in an int variable, not typed into printf
- Your loop must work unchanged if you replace 9375 with 61 or 4820073
- Do not hard-code the digit count

Hint, not a solution:
  Integer division truncates. What does 9375 / 10 give you?
  What is left over that division threw away, and how would you recover it?
  You have + - * / available. One of those four is not division.

DSA concept: digit decomposition by radix
Approach: repeatedly peel the last digit, then shrink the number
Time: O(d) where d is the number of digits, which is O(log n)
Space: O(1) — a fixed number of int variables regardless of input size

Once it works, answer this in a comment: what does your program print for 0,
and is that the answer you want?
*/

#include <stdio.h>

int main()
{

    return 0;
}
