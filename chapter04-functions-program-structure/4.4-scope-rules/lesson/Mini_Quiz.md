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

## Question 4
True or False: a function parameter and an external variable can have the
same name, and the function will still correctly use its OWN parameter
inside its body, not the external one.

## Question 5
If function A has a local variable `n`, and function B also has a local
variable `n`, are these the same variable or two different variables?
Why does C allow this without any conflict?