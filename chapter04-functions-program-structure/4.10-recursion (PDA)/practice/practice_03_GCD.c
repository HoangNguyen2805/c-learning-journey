/*
### Problem 3 - GCD (Euclidean algorithm)
Write a function that finds the GCD (greatest common divisor) of two numbers.
The GCD is just "the biggest number that divides evenly into both a and b."
For example, the GCD of 48 and 18: what's the biggest number that goes into both 48 and 18 with no remainder?
This is a real, classic DSA recursion problem — genuinely used in real
systems (cryptography, fractions, etc.), not just a teaching toy.

Write:
```c
int gcd(int a, int b);
```
using the recursive rule: `gcd(a, b) = gcd(b, a % b)`, with base case
`gcd(a, 0) = a`.

Test with `gcd(48, 18)` — predict first, then verify by hand using
regular long division if you're unsure your prediction is right.
*/
