# Practice 4.2A - Hints and Skills

Use the hints only if you are stuck.

---

## Skills Used

**From Chapter 1:** printf, scanf, program structure

**From Chapter 2:** int, double, arithmetic operators, comparison operators

**From Chapter 3:** do-while, switch/case/default, if/else, continue

**From Chapter 4.1:** functions, parameters, return values, prototypes

**From Chapter 4.2 (new this practice):** functions returning double, functions returning char, matching prototype return type to definition

---

<details>
<summary>HINT - Suggested Order</summary>

## 1. Prototypes — note the return types carefully

```c
double celsiusToFahrenheit(double c);
double fahrenheitToCelsius(double f);
double average(double a, double b);
char letterGrade(int score);
```

## 2. Variables in main()

```c
int choice;
double num1, num2, result;
int score;
char grade;
int count = 0;
```

## 3. Menu shape (same as before)

```c
do {
    // print menu
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter Celsius temperature: ");
            scanf("%lf", &num1);
            result = celsiusToFahrenheit(num1);
            printf("Result: %.2f F\n", result);
            count++;
            break;
        ...
    }
} while (choice != 0);
```

Note: `scanf` for a `double` uses `%lf`, not `%d`. Watch this carefully —
it's a new detail this section introduces.

## 4. Option 4 — validate the score first

```c
case 4:
    printf("Enter score: ");
    scanf("%d", &score);
    if (score < 0 || score > 100) {
        printf("Invalid score.\n");
        continue;
    }
    grade = letterGrade(score);
    printf("Grade: %c\n", grade);
    count++;
    break;
```

## 5. letterGrade function — if/else if/else chain returning char

```c
char letterGrade(int score) {
    if (score >= 90) {
        return 'A';
    } else if (score >= 80) {
        return 'B';
    } else if (score >= 70) {
        return 'C';
    } else {
        return 'F';
    }
}
```

## 6. The conversion functions — straightforward one-line returns

```c
double celsiusToFahrenheit(double c) {
    return c * 9.0 / 5.0 + 32.0;
}
```

Repeat the pattern for fahrenheitToCelsius and average.

</details>

<details>
<summary>EXPLANATION - Concepts Used</summary>

## Why %lf for scanf, but %f for printf?

This is a real C quirk worth knowing: `scanf` requires `%lf` to read into
a `double` variable, but `printf` uses `%f` for both `float` and `double`.
This inconsistency trips up almost everyone the first time — it's not
something you did wrong if you forget it once.

## Why does letterGrade return as soon as it hits a true condition?

Once a `return` executes, the function ends immediately — none of the
later `else if` checks even run. This is actually efficient and correct;
you don't need to "break out" of anything extra.

## Why must double prototypes be declared before main()?

Same reason as int functions in 4.1 — but it's MORE important here.
Old C used to assume an unknown function returned int. If you forgot
the prototype for a double-returning function, old compilers might
silently truncate your double into an int-sized return — a real,
hard-to-spot bug. Modern compilers warn you, but the prototype is
still the correct habit.

</details>