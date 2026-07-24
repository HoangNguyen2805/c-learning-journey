# Mini-Quiz: Section 1.2 — Variables and Arithmetic Expressions

Answer in your own words or with code. Write your answers before checking anything.

---

### 1.
Where in a function must declarations appear, and why does C require variables
to be declared at all?

---

### 2.
What is the difference between these two lines?

```c
int count;
count = 0;
```

```c
int count = 0;
```

---

### 3.
Predict the output. Explain each result.

```c
printf("%d\n", 5 / 9);
printf("%d\n", 9 / 5);
printf("%f\n", 5.0 / 9.0);
```

---

### 4.
K&R writes the conversion as `5 * (fahr - 32) / 9` rather than
`5 / 9 * (fahr - 32)`. Both are algebraically identical. Why does only one work?

---

### 5.
What happens when an arithmetic operator has one `int` operand and one `float`
operand? Give an example.

---

### 6.
Trace this loop by hand. How many lines does it print, and what are they?

```c
int i = 1;
while (i <= 3) {
    printf("%d\n", i);
    i = i + 1;
}
```

---

### 7.
What is wrong with this loop, and what would happen if you ran it?

```c
int fahr = 0;
while (fahr <= 300) {
    printf("%d\n", fahr);
}
```

---

### 8.
For each of these, say exactly what is printed. Use `[` and `]` to show spacing.

```c
printf("[%d]\n", 7);
printf("[%3d]\n", 7);
printf("[%6d]\n", 1234);
```

---

### 9.
What does each conversion specification produce for the value `3.14159`?

```c
%f      %.2f      %6.2f      %.0f
```

---

### 10.
This program compiles but prints nonsense. Find the bug and explain why the
compiler did not catch it.

```c
#include <stdio.h>

main()
{
    float price;
    price = 9.99;
    printf("%d\n", price);
}
```

---

## Exercises From the Book

### [FROM K&R] Exercise 1-3
Modify the temperature conversion program to print a heading above the table.

### [FROM K&R] Exercise 1-4
Write a program to print the corresponding Celsius to Fahrenheit table.

Think before you write: the formula inverts to `F = (9/5)C + 32`. What does that
tell you about which arithmetic type you need?

---

## Notes

The two ideas most worth carrying forward from this section are that integer
division truncates, and that every `%` in a format string must match its
argument by number and type. Nearly every bug in early C programs is one of
those two.
