# Practice 4.1A - Hints and Skills

Use the hints only if you are stuck.

---

## Skills Used

**From Chapter 1:** printf, scanf, semicolons, comments, program structure

**From Chapter 2:** int variables, arithmetic operators (+, -, *, /), comparison operators (==, %)

**From Chapter 3:** do-while loop, switch / case / default, if / else, continue, break

**From Chapter 4.1 (new this practice):** function definition, function call, parameters vs arguments, return values, function prototypes, functions are not nested, call by value

---

<details>
<summary>HINT - Suggested Order</summary>

## 1. Write your function prototypes first, above main()

```c
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);
```

## 2. Set up your variables in main()

```c
int choice;
int num1, num2;
int result;
int count = 0;
```

## 3. Build the do-while menu (same shape as Ch.3 practice)

```c
do {
    // print menu
    // scanf choice

    switch (choice) {
        case 1:
            // ask num1, num2
            // result = add(num1, num2);
            // print result, check even/odd, count++
            break;
        ...
    }
} while (choice != 0);
```

## 4. Handle divide separately — it has a special rule

```c
case 4:
    // ask num1, num2
    if (num2 == 0) {
        printf("Cannot divide by zero.\n");
        continue;
    }
    result = divide(num1, num2);
    // print result, check even/odd, count++
    break;
```

Worth testing directly: does `continue` inside a `switch`, inside a
`do-while`, actually skip back to the menu the way you'd expect?

## 5. Even/odd check (reuse Ch.3 logic)

```c
if (result % 2 == 0) {
    printf("Result is even.\n");
} else {
    printf("Result is odd.\n");
}
```

## 6. Print the count only on quit

```c
case 0:
    printf("Total calculations performed: %d\n", count);
    printf("Quitting.\n");
    break;
```

## 7. Define your four functions AFTER main()

```c
int add(int a, int b) {
    return a + b;
}
```

Repeat the pattern for subtract, multiply, divide.

</details>

<details>
<summary>EXPLANATION - Concepts Used</summary>

## Why prototypes?

Functions are defined AFTER main(), so the compiler needs to know
they exist (and what they expect/return) before reaching main().
The prototype is a promise: "trust me, this function exists below."

## Why pass through parameters instead of using global variables?

This is the whole point of 4.1: functions take INPUT through
parameters and send OUTPUT through return values. No sharing
variables behind the scenes — that's saved for 4.3 (external variables).

## Main idea

```text
main = traffic controller (menu, input, decisions)
add/subtract/multiply/divide = workers (just do math, return answer)
```

</details>