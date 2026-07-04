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
/*
So the way to find GCD is divided the bgiger number to the smaller number to find remainder, until
the remainder is equal to zero the the result of that division that have remiander of zero is GCD.
Ex: find gcd(287, 91)
    gcd(287, 91)    287 % 91   ->  287 = 3(91) + 14 -> 14 is the remainder
    = gcd(91, 14)    91 % 14   ->   91 = 6(14) + 7  ->  7 is the remainder  
    = gcd(14, 7)     14 %  7   ->   14 = 2(7)  + 0  ->  0 is the remainder, thereforce 7 is gcd(287, 91).
    = gcd(7, 0)

    In this case base case stop when  second number == 0 and the answer it return is first number.
*/

#include <stdio.h>

int gcd(int a, int b);

int main(){

    int a;
    int b;
    printf("Find GCD(a,b)\n");
    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);
    
    printf("Result = %d\n", gcd(a,b));


    return 0;
}

int gcd(int a, int b){
    if (b == 0){
        return a;
    }else{
        int remainder = a % b;               // OR Just return gcd(b, a % b);
        return gcd(b, remainder);
    }
}