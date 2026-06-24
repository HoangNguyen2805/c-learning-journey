# Practice 01 Hint - Goto and Labels

Use this file only if you are stuck.

<details>
<summary>HINT - Suggested Order</summary>

## 1. Create variables

You probably need:

```c
int choice;
int target;
int maxA;
int maxB;
int a;
int b;
int found;
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

## 3. Use switch for menu choice

Menu:

```text
1 - Search for target product
0 - Quit
```

Shape:

```c
switch (choice)
{
   case 1:
      // search code
      break;

   case 0:
      // goodbye
      break;

   default:
      // invalid choice
      break;
}
```

## 4. Inside case 1, ask for input

Ask for:

```text
Target:
Max a:
Max b:
```

## 5. Set found to 0 before searching

```c
found = 0;
```

This means:

```text
We have not found a pair yet.
```

## 6. Use nested for loops

You need one loop inside another loop.

Shape:

```c
for (a = 1; a <= maxA; a++)
{
   for (b = 1; b <= maxB; b++)
   {
      // check product
   }
}
```

## 7. Check if the product matches

Inside the inner loop:

```c
if (a * b == target)
{
   found = 1;
   goto found_pair;
}
```

This means:

```text
If the pair is found, remember that we found it, then jump to the label.
```

## 8. Create the label after both loops

The label should be after the nested loops.

Shape:

```c
found_pair:
```

A label ends with a colon.

## 9. Print result after the label

After the label, use if / else.

If found is 1:

```text
Found: a * b = target
```

Otherwise:

```text
No pair found.
```

## 10. Important switch break

After printing the result, use:

```c
break;
```

That exits the switch case.

</details>

<details>
<summary>EXPLANATION - Concepts Used</summary>

## What is a label?

A label is a named place in your code.

Example:

```c
done:
```

The colon is required.

## What does goto do?

`goto` jumps to a label.

Example:

```c
goto done;
```

This jumps to:

```c
done:
```

## Why use goto here?

Normally, `break` only exits one loop.

Example:

```c
for (...)
{
   for (...)
   {
      break;
   }
}
```

That `break` only exits the inner loop.

But this practice has nested loops, and we want to escape both loops immediately when a pair is found.

That is one situation where K&R says goto can be useful.

## What is the main idea?

```text
goto = jump to a label
label = place where goto can jump
```

But do not overuse goto.

Most of the time, loops, if statements, switch, break, and continue are better.

## Warning

Bad use of goto can make code messy.

Good use here:

```text
Use goto only to escape nested loops.
```

Bad use:

```text
Jumping randomly all over the program.
```

</details>
