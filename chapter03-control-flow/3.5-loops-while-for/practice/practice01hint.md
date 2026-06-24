# Practice 01 Hint

## Practice 01 - Cumulative Loop Challenge

Use this only when you are stuck.

<details>
<summary>HINT - Suggested Order</summary>

1. Create your variables:

```c
int start;
int end;
int choice;
int i;
int sum;
```

2. Ask for the starting number:

```c
printf("Enter starting number: ");
scanf("%d", &start);
```

3. Ask for the ending number:

```c
printf("Enter ending number: ");
scanf("%d", &end);
```

4. Print the menu:

```text
1 - Print all numbers
2 - Print even numbers
3 - Print odd numbers
4 - Print sum
```

5. Ask for menu choice:

```c
printf("Enter choice: ");
scanf("%d", &choice);
```

6. Use `switch(choice)`.

7. For choice `1`, print all numbers.

Example idea:

```c
for (i = start; i <= end; i++)
{
   printf("%d\n", i);
}
```

8. For choice `2`, print only even numbers.

Use:

```c
if (i % 2 == 0)
```

9. For choice `3`, print only odd numbers.

Use:

```c
if (i % 2 != 0)
```

10. For choice `4`, add numbers into `sum`.

Start with:

```c
sum = 0;
```

Then inside the loop:

```c
sum = sum + i;
```

11. Use `default` for invalid menu choice.

</details>

<details>
<summary>EXPLANATION - Concepts Used</summary>

## Why use a loop?

A loop lets you repeat code.

Without a loop, printing numbers from 1 to 5 would look like this:

```c
printf("1\n");
printf("2\n");
printf("3\n");
printf("4\n");
printf("5\n");
```

With a loop, C can repeat for you.

## Why use `for`?

A `for` loop is good when you know the start and end.

Example:

```c
for (i = start; i <= end; i++)
```

This means:

```text
Start i at start.
Keep going while i <= end.
Add 1 to i after each loop.
```

## Why use `%`?

The `%` operator gives the remainder.

Example:

```c
10 % 2 == 0
```

That means 10 is even.

```c
11 % 2 != 0
```

That means 11 is odd.

## Why use `switch`?

The menu choice is one exact value:

```text
1, 2, 3, or 4
```

That is why `switch` is a good fit.

## Why use `break`?

`break` stops one case from falling into the next case.

Without `break`, C may continue running the next case.

</details>
