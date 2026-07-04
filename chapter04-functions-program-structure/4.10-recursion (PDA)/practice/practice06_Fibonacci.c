/*
### Problem 6 - Fibonacci (the classic, and a trap)

Write:
```c
int fib(int n);
```
using the definition `fib(n) = fib(n-1) + fib(n-2)`, with base cases
`fib(0) = 0` and `fib(1) = 1`.

Test with `fib(6)` — predict first (write out `fib(0)` through `fib(6)`
by hand if you're not sure).
trace:
fib(0) = 0

fib(1) = 1

fib(2) = fib(n-1) + fib(n-2) = fib(2-1) + fib(2-2) = fib(1) + fib(0) = 1 + 0 = 1
fib(2) = 1

fib(3) = fib(n-1) + fib(n-2) = fib(3-1) + fib(3-2) = fib(2) + fib(1) = 1 + 1 = 2
fib(3) = 2

fib(4) = fib(n-1) + fib(n-2) = fib(4-1) + fib(4-2) = fib(3) + fib(2) = 2 + 1 = 3
fib(4) = 3

fib(5) = fib(n-1) + fib(n-2) = fib(5-1) + fib(5-2) = fib(4) + fib(3) = 3 + 2 = 5
fib(5) = 5

fib(6) = fib(n-1) + fib(n-2) = fib(6-1) + fib(6-2) = fib(5) + fib(4) = 5 + 3 = 8
fib(6) = 8

**Then, a real DSA question to think about (don't code this part yet,
just answer in a comment):** Look at `weird(n)` from Quiz Q5 — the one
that calls itself twice and roughly doubles in calls each level. `fib`
has that exact same double-branching shape. What do you think happens
to the *number of calls* `fib` makes as `n` gets larger, like `fib(30)`
or `fib(40)`? Would you expect it to run instantly, or would you expect
it to feel slow? Why?
- Take noticeably long
- BecauseSince each fib(n) call branches into two more calls, and that pattern repeats 
all the way down, the total number of calls grows exponentially. fib(40) with double-branching 
at each level would make roughly 2^40 calls — that's over a trillion calls. Your computer would 
hang for minutes (or longer).

(We'll come back to *why* this happens and how to fix it — it's a real,
famous problem in DSA — once we've done a bit more. For now just reason
about it based on the branching shape.)
*/

#include <stdio.h>

int fib(int n);

int main(){

    int n;
    printf("Fibonacci calculation, Enter n = ");
    scanf("%d", &n);
    printf("Result = %d\n", fib(n));

    return 0;
}

int fib(int n){
    if (n == 0){
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fib(n-1) + fib(n-2);
    }
}
