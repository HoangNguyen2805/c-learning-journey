# Practice 01 Hint - Break and Continue

Use this file only if you are stuck.

<details>
<summary>HINT - Suggested Order</summary>

## 1. Create variables

You probably need variables like:

```c
int choice;
int count;
int number;
int i;
int sum;
int accepted;
int even;
int odd;
```

## 2. Use a do-while menu

The menu should repeat until the user chooses 0.

Shape:

```c
do
{
   // print menu
   // scanf choice
   // switch choice
} while (choice != 0);
```

## 3. Use switch for the menu

Menu choices:

```text
1 - Process a batch of numbers
0 - Quit
```

Shape:

```c
switch (choice)
{
   case 1:
      // batch processing
      break;

   case 0:
      // goodbye
      break;

   default:
      // invalid choice
      break;
}
```

## 4. Inside case 1, reset your counters

Before processing a new batch, reset:

```c
sum = 0;
accepted = 0;
even = 0;
odd = 0;
```

This matters because the menu can repeat.

## 5. Ask how many numbers

```c
printf("How many numbers? ");
scanf("%d", &count);
```

## 6. Use a for loop

Shape:

```c
for (i = 1; i <= count; i++)
{
   // ask for number
}
```

## 7. Use break for 0

If the user enters 0, stop reading numbers early.

Idea:

```c
if (number == 0)
{
   printf("Zero entered. Stopping early.\n");
   break;
}
```

This `break` exits the nearest loop, which is the `for` loop.

## 8. Use continue for negative numbers

If the user enters a negative number, skip the rest of that loop round.

Idea:

```c
if (number < 0)
{
   printf("Negative number skipped.\n");
   continue;
}
```

This means the negative number does not get added to sum and does not count as even or odd.

## 9. Positive number logic

After the break/continue checks, the number should be positive.

Then:

```text
accepted increases by 1
number gets added to sum
check if even or odd
```

Even check:

```c
number % 2 == 0
```

Odd check:

```c
number % 2 != 0
```

## 10. Print final batch result

After the for loop, print:

```text
Accepted numbers:
Even numbers:
Odd numbers:
Sum:
```

</details>

<details>
<summary>EXPLANATION - Concepts Used</summary>

## Why do we use `break`?

`break` stops the nearest loop or switch.

In this practice, there are two different uses.

Inside the `for` loop:

```c
if (number == 0)
{
   break;
}
```

This stops reading numbers early.

Inside the `switch`:

```c
case 1:
   // code
   break;
```

This stops fall-through into the next case.

## Why do we use `continue`?

`continue` skips the rest of the current loop round.

In this practice:

```c
if (number < 0)
{
   continue;
}
```

This skips negative numbers so they do not affect the result.

## Why reset counters inside case 1?

Because the menu repeats.

If you process one batch, then choose 1 again, you want a fresh result.

So reset:

```c
sum = 0;
accepted = 0;
even = 0;
odd = 0;
```

inside `case 1`.

## Important order

The order inside the `for` loop should be:

```text
1. Read number
2. If number is 0, break
3. If number is negative, continue
4. Add positive number to sum
5. Count accepted
6. Count even or odd
```

Order matters.

If you add the number before checking for 0 or negative, your result will be wrong.

## Main idea

```text
break = stop early
continue = skip this round
```

</details>
