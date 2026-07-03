/*
### Problem 1 - Sum of 1 to N (warm-up)

Write a recursive function:
```c
int sumToN(int n);
```
that returns `1 + 2 + 3 + ... + n` using recursion (no loops allowed).

Test it with `sumToN(5)` — predict the answer before running.
*/

#include <stdio.h>

int sumToN(int n);

int main(){

    int n;
    printf("Sum of 1 to N\n");
    printf("N = ");
    scanf("%d", &n);
    int result = sumToN(n);
    printf("Sum = %d\n", result);

    return 0;
}

int sumToN(int n){
    if (n <= 0){
        return 0;
    } else {
        return n + sumToN(n - 1);
    }
}
/*
Trace sumToN by hand:
sumToN(5)
    return 5 + sumToN(5 - 1);
        5 + sumToN(4)

        where sumToN(4)
            sumToN(4)
                return 4 + sumToN(4 - 1);
                    4 + sumToN(3)

                    where sumToN(3)
                        sumToN(3)
                            return 3 + sumToN(3 - 1);
                                3 + sumToN(2)
                                
                                where sumToN(2)
                                    sumToN(2)
                                        return 2 + sumToN(2 - 1);
                                            2 + sumToN(1)

                                            where sumToN(1)
                                                sumToN(1)
                                                    return 1 + sumToN(1 - 1);
                                                        1 + sumToN(0)

                                                        where sumToN(0)
                                                            return 0;
*/