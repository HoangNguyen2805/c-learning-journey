# Practice 01 Hint - Do-While ATM Menu

Use this file only if you are stuck.

<details>
<summary>HINT - Suggested Order</summary>

## 1. Create variables

You probably need:

```c
int choice;
double balance;
double amount;
```

Start the balance at:

```c
balance = 100.00;
```

## 2. Use a do-while loop

The menu must show at least once, so use:

```c
do
{
   // menu code here
} while (choice != 0);
```

## 3. Print the menu inside the do-while

The menu should repeat every time.

```text
ATM Menu
1 - Check balance
2 - Deposit money
3 - Withdraw money
0 - Quit
```

## 4. Use scanf for the choice

```c
scanf("%d", &choice);
```

## 5. Use switch(choice)

Each menu option should be one case.

```c
switch (choice)
{
   case 1:
      // check balance
      break;

   case 2:
      // deposit
      break;

   case 3:
      // withdraw
      break;

   case 0:
      // quit
      break;

   default:
      // invalid choice
      break;
}
```

## 6. Deposit logic

Ask for an amount.

If amount is greater than 0:

```text
balance = balance + amount
```

Otherwise print invalid deposit.

## 7. Withdraw logic

Ask for an amount.

Withdraw is valid only if:

```text
amount > 0
AND
amount <= balance
```

If valid:

```text
balance = balance - amount
```

Otherwise print invalid withdrawal.

## 8. Quit logic

When choice is 0, print:

```text
Goodbye
```

The do-while condition should stop the loop.

</details>

<details>
<summary>EXPLANATION - Concepts Used</summary>

## Why do-while?

A menu should show at least one time.

That is why this is better than a normal while loop:

```c
do
{
   // show menu
} while (choice != 0);
```

## Why switch?

The user is choosing one exact menu number:

```text
1, 2, 3, or 0
```

That is a good use for switch.

## Why if / else?

Deposit and withdrawal need condition checks.

Examples:

```text
Is deposit amount greater than 0?
Is withdrawal amount more than balance?
```

That is why if / else is needed.

## Why break?

Inside switch, break stops fall-through.

Without break, one case can accidentally run into another case.

## Why choice != 0?

This means:

```text
Keep repeating while the user did not choose 0.
```

When the user enters 0, the loop stops.

</details>
