## 1.4A - Constant Variables with const

A constant variable is a variable that cannot be changed after it is created.

In C, we use:

```c
const
```

---

## Basic example

```c
const int MAX_SCORE = 100;
```

This means:

```text
MAX_SCORE is an int
MAX_SCORE stores 100
MAX_SCORE cannot be changed later
```

---

## Why use const?

Use `const` when a value should stay the same for the whole program.

Examples:

```c
const int MAX_SCORE = 100;
const int PASSING_SCORE = 70;
const double TAX_RATE = 0.0825;
const double PI = 3.14159;
```

These values should not randomly change.

---

## Normal variable vs const variable

Normal variable:

```c
int score = 90;
score = 95;
```

This is allowed because `score` is not constant.

Constant variable:

```c
const int MAX_SCORE = 100;
MAX_SCORE = 90;
```

This is wrong because `MAX_SCORE` is constant.

---

## Example program

```c
#include <stdio.h>

int main() {
    const int PASSING_SCORE = 70;

    int score;

    printf("Enter score: ");
    scanf("%d", &score);

    if (score >= PASSING_SCORE) {
        printf("Pass\n");
    } else {
        printf("Fail\n");
    }

    return 0;
}
```

---

## const with double

```c
const double TAX_RATE = 0.0825;
```

Example:

```c
double subtotal = 30.00;
double tax = subtotal * TAX_RATE;
```

---

## Naming style

Many C programmers write constant names in all caps:

```c
const int MAX_SCORE = 100;
const double TAX_RATE = 0.0825;
```

This makes it easy to see that the value should not change.

---

## Important rule

You must give a `const` variable a value when you create it.

Correct:

```c
const int MAX_SCORE = 100;
```

Wrong:

```c
const int MAX_SCORE;
MAX_SCORE = 100;
```

Because once a const variable is created, you cannot assign a new value later.

---

## Memory rule

```text
normal variable = value can change

const variable = value cannot change

const protects important values from being changed by mistake
```
---
---

## 1.4B - #define Symbolic Constants

K&R uses `#define` for symbolic constants.

A symbolic constant gives a name to an important value.

Example:

```c
#define LOWER 0
#define UPPER 300
#define STEP 20
```

This means:

```text
LOWER represents 0
UPPER represents 300
STEP represents 20
```

Then instead of writing numbers directly:

```c
for (fahr = 0; fahr <= 300; fahr = fahr + 20)
```

we can write:

```c
for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
```

This makes the code easier to understand.

---

## Important rules for #define

`#define` does not use `=`.

Correct:

```c
#define LOWER 0
```

Wrong:

```c
#define LOWER = 0
```

`#define` does not use a semicolon.

Correct:

```c
#define UPPER 300
```

Wrong:

```c
#define UPPER 300;
```

---

## Why use symbolic constants?

Symbolic constants help avoid magic numbers.

Magic numbers are numbers written directly in code without explanation.

Less clear:

```c
for (fahr = 0; fahr <= 300; fahr = fahr + 20)
```

More clear:

```c
for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
```

Now we know:

```text
LOWER = starting value
UPPER = ending value
STEP = amount added each time
```

---

## #define vs const

`const` creates a typed variable that cannot change.

Example:

```c
const int MAX_SCORE = 100;
```

`#define` is handled before the program is compiled.

Example:

```c
#define MAX_SCORE 100
```

For now, remember:

```text
const = typed constant variable

#define = symbolic replacement before compile
```

K&R Chapter 1.4 mainly teaches `#define`.

---

## Memory rule

```text
#define NAME value

No =
No semicolon

Use uppercase names for symbolic constants.
```
---
---