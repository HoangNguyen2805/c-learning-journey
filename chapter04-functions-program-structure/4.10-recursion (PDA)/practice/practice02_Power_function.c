/*
### Problem 2 - Power function

Write a recursive function:
```c
int power(int base, int exp);
```
that computes `base^exp` (assume `exp >= 0`) using recursion.

Think about the recursive definition first:
`power(base, exp) = base * power(base, exp - 1)`, with a base case for
`exp == 0`.

Test with `power(2, 5)` — predict first.
*/
#include <stdio.h>

int power(int base, int exp);

int main(){

    int base;
    int exp;

    printf("Enter base: ");
    scanf("%d", &base);
    printf("Enter exponent: ");
    scanf("%d", &exp);

    printf("Answer = %d\n", power(base, exp));

    return 0;
}

int power(int base, int exp){
    if (exp <= 0){
        return 1;
    } else {
        return base * power(base, exp - 1);
    }
}