# 4.6 Quiz - Static Variables (Part 1: static inside a function)

Predict the output BEFORE running any code.

## Question 1
```c
void counter(void) {
    static int x = 0;
    x++;
    printf("%d\n", x);
}

int main() {
    counter();
    counter();
    counter();
    return 0;
}
```
What prints, in order?
- pirint output
- 1
- 2
- 3
## Question 2
```c
void counter(void) {
    int x = 0;
    x++;
    printf("%d\n", x);
}

int main() {
    counter();
    counter();
    counter();
    return 0;
}
```
What prints, in order? Why is this different from Question 1, even though
the function body looks almost identical?
- Print
- 1
- 1
- 1
- without static, the everytime the function call it reassin x back to 0.
## Question 3
```c
static int x = 5;   // this is OUTSIDE the function

void show(void) {
    printf("%d\n", x);
    x = x + 1;
}
```
If `show()` is called 3 times in a row, what prints each time? Is this
the SAME mechanism as Question 1's static, or a DIFFERENT one (external
variable vs. static local variable)? Explain the difference.
- answer
show() is called 3 times, printing: 5, 6, 7

Trace, step by step:

Call 1: prints x's current value (5, the original starting value). Then x = x + 1; runs, making x become 6.
Call 2: prints x's current value (6, left over from call 1). Then x = x + 1; runs, making x become 7.
Call 3: prints x's current value (7, left over from call 2). Then x = x + 1; runs, making x become 8 (never printed, since the increment happens after the print).
Is this the same mechanism as Q1, or different? — Different.

In Q1, static int x = 0; was declared inside counter()'s own { } — making it a static local variable, private memory belonging only to counter(). No other function in the program could ever see or touch that x.

In Q3, static int x = 5; is declared outside any function entirely, at the very top of the file. This is the second meaning of static from the lesson — "static outside a function = private to this file." This x isn't tied to show() specifically — it behaves like an external variable (Ch.4.3): any function in this file could read or modify it, not just show(). The static keyword here only adds the restriction that other files (in a multi-file program) couldn't reach it either — a restriction that doesn't show up visibly in this single-function example.

In short: Q1's x is private to one function. Q3's x is private to one file, but shared across every function within that file.

## Question 4
True or False: a static local variable's initializer (e.g. "= 0") runs
every single time the function is called.
- T
Fix: The correct answer is False — a static local variable's initializer runs only once, the very first time the function is ever called, never again on subsequent calls. Look back at Q1's trace: if static int x = 0; reset to 0 every call, would counter() ever print 2 or 3? It would print 1, 1, 1 forever, exactly like Q2's non-static version. The fact that Q1 prints 1, 2, 3 is the direct proof that the = 0 initializer does not re-run on every call.

## Question 5
Give one real-world reason you might want a function to "remember"
something between calls, without using an external variable shared by
multiple functions.
- To counting number