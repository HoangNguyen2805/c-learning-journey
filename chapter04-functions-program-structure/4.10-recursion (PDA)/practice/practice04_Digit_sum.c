/*
### Problem 4 - Digit sum (recursive, no arrays)

Write:
```c
int digitSum(int n);
```
that adds up all the digits of `n` recursively. Example: `digitSum(1234)`
should give `1+2+3+4 = 10`.

Hint: think about `n % 10` (last digit) and `n / 10` (the rest), similar
to how `printd` peeled digits off — except here you're *summing* them
instead of printing them, so think carefully about whether the sum
happens on the way down or the way up.

Test with `digitSum(9875)` — predict first.
*/

#include <stdio.h>

int digitSum(int n);

int main(){

    int n;
    printf("This is the Sum of All digit of N, What is your N ?\n");
    printf("N = ");
    scanf("%d", &n);

    printf("Result = %d\n", digitSum(n));

    return 0;
}

int digitSum(int n){

    if (n == 0){
        return n;
    } else {
        int lastDigit = n % 10;
        n = n / 10;
        return lastDigit + digitSum (n);
    }
}