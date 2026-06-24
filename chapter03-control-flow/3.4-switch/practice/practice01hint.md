# Practice 01 Hint

## Practice 01 - Cumulative Switch Challenge

Use this file only when you are stuck.

<details>
<summary>HINT - Suggested Order</summary>

1. Include the standard input/output library.

```c
#include <stdio.h>
```

2. Inside `main`, create the variables you need:

```c
char menuChoice;
int quantity;
char studentType;
double price;
double subtotal;
double discountRate;
double discount;
double total;
```

3. Ask the user for the menu choice.

Because this is a `char`, use a space before `%c`:

```c
printf("Enter menu choice A/B/C/D: ");
scanf(" %c", &menuChoice);
```

4. Ask the user for quantity.

```c
printf("Enter quantity: ");
scanf("%d", &quantity);
```

5. Ask the user for student type.

Because this is also a `char`, use a space before `%c` again:

```c
printf("Enter student type F/P/N: ");
scanf(" %c", &studentType);
```

6. Use `switch(menuChoice)` to choose the price.

Use these choices:

```text
A = 8.50
B = 7.25
C = 6.75
D = 3.50
```

7. Use `default` for invalid menu choice.

8. Use `break` after every `case`.

9. Use `if / else-if / else` to choose the discount rate.

Use these choices:

```text
F = 0.15
P = 0.10
N = 0.0
```

10. Calculate:

```c
subtotal = price * quantity;
discount = subtotal * discountRate;
total = subtotal - discount;
```

11. Print a receipt with:

```text
Campus Meal Kiosk
Item choice:
Quantity:
Student type:
Subtotal:
Discount:
Total:
```

</details>

<details>
<summary>EXPLANATION - Concepts Used</summary>

## Why use `switch`?

Use `switch` when you are checking one exact value.

Good examples:

```c
menuChoice == 'A'
menuChoice == 'B'
menuChoice == 'C'
menuChoice == 'D'
```

That is why `switch` is good for menu choices.

## Why use `if / else-if / else`?

Use `if / else-if / else` when you are checking conditions or making decisions that may not fit cleanly as one menu.

For this problem, student type can be checked like this:

```c
if (studentType == 'F')
else if (studentType == 'P')
else if (studentType == 'N')
else
```

## Why use `break`?

Inside a `switch`, `break` stops fall-through.

Without `break`, C keeps running into the next case.

Example problem:

```c
case 'A':
   price = 8.50;

case 'B':
   price = 7.25;
```

If the user enters `A`, C may continue into `B` because there is no `break`.

Correct version:

```c
case 'A':
   price = 8.50;
   break;
```

## Why use `default`?

`default` handles anything that does not match a case.

Example:

```text
User enters X
```

There is no `case 'X'`, so `default` runs.

## Why does `scanf(" %c", &menuChoice)` need a space?

`%c` reads one character exactly.

That means it can accidentally read leftover newline from the previous input.

This version is safer:

```c
scanf(" %c", &menuChoice);
```

The space before `%c` tells `scanf` to skip whitespace first.

</details>
