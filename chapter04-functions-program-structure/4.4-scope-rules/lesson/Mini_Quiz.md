# 4.4 Quiz - Scope Rules

Predict the output BEFORE running any code. Then check yourself.

## Question 1
```c
int x = 100;

void show(void) {
    int x = 5;
    printf("%d\n", x);
}

int main() {
    show();
    printf("%d\n", x);
    return 0;
}
```
What prints, in order?
- x = 5
  x = 100
## Question 2
```c
int total = 0;

void addToTotal(int amount) {
    int total = amount;
}

int main() {
    addToTotal(50);
    printf("%d\n", total);
    return 0;
}
```
What prints? Why might this surprise someone who didn't understand scope?
- print zero 0, bacause value of total is already set equal to 0
## Question 3
```c
int counter = 0;

void increment(void) {
    counter = counter + 1;
}

int main() {
    int counter = 99;
    increment();
    printf("%d\n", counter);
    return 0;
}
```
What prints? (Careful — there are TWO variables named counter here.)
- 0 
Fix:Q3 Answer: 99
Think of counter here as two separate boxes that just happen to share the same label:

📦 Box A (external counter) — starts at 0
📦 Box B (main()'s local counter) — starts at 99

These are two completely different variables in memory. They are not connected just because they share a name.
Walk through what happens:

main() creates Box B and sets it to 99.
main() calls increment().
Inside increment(), there's no int counter = ... line — it never made its own box. So when it writes counter = counter + 1;, the only counter it can possibly mean is Box A, since Box B belongs only to main() and increment() has no way to see it.
Box A changes: 0 → 1. Box B is never touched.
Back in main(), the rule is: once a function declares its own local variable with a name, every use of that name inside that function automatically means the local one — for the entire rest of that function. So printf("%d\n", counter); reads Box B, not Box A.
Box B was never changed by increment() — it's still 99.

Result: 99 prints, even though increment() did successfully increment something (Box A, now 1) — main() just never looks at that box.
The real lesson: once main() declares its own local counter, it permanently loses the ability to "see" the external counter for the rest of its own function body — no matter what any other function does to the external one.
## Question 4
True or False: a function parameter and an external variable can have the
same name, and the function will still correctly use its OWN parameter
inside its body, not the external one.
- T
## Question 5
If function A has a local variable `n`, and function B also has a local
variable `n`, are these the same variable or two different variables?
Why does C allow this without any conflict?
- Different, 2 different function doesn't see each other variable.