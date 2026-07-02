# 4.9 Quiz - Initialization

Predict answers BEFORE running any code.

## Question 1
```c
int main() {
    int x;
    printf("%d\n", x);
    return 0;
}
```
What prints? Can you predict the exact value?
- It'll print random number if local variable is not initialized, we can;t predict what it print.
## Question 2
```c
int counter;

int main() {
    printf("%d\n", counter);
    return 0;
}
```
What prints? Why is this different from Question 1?
- 0
## Question 3
```c
void mystery(void) {
    static int val;
    val = val + 5;
    printf("%d\n", val);
}

int main() {
    mystery();
    mystery();
    mystery();
    return 0;
}
```
What prints, in order? (Note: no "= 0" written anywhere - does static
still start at 0?)
- 5
  10
  15
## Question 4
True or False: this is legal C:
```c
int getStart(void) { return 50; }

static int max = getStart();   // static initialized with a function call
```
- F — external/static initializers must be constants, not function calls, because they're set before the program even starts running. getStart() can't run before the program starts.
## Question 5
In my own past practices, which bug did I personally hit that proves
Rule 1 (uninitialized local = garbage)? What was the garbage value I saw?
- local variable not asign or initialized with any fixed value will printf out random value.
Fix: Half credit — your explanation of the rule is right, but the question asked about the specific bug you personally hit. The answer: the Fibonacci practice (4.4) where enterNumber(a, b) couldn't set main()'s variables, so the math ran on uninitialized a and b, printing garbage like 1835822505. Worth writing the specific memory down — connecting rules to your own bugs is what makes them stick.