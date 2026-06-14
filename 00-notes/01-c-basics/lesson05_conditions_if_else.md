# Day 05 - Conditions / if else in C

## What is a condition?

A condition is a question that C can answer as true or false.

Example:

```c
age >= 18
```

This asks:

```text
Is age greater than or equal to 18?
```

If the answer is true, C can run one block of code.

If the answer is false, C can skip it or run another block.

## Why conditions are important

Conditions let a program make decisions.

Example:

```c
if (age >= 18) {
    printf("Adult\n");
}
```

Meaning:

```text
If age is 18 or more, print Adult.
```

## Basic if statement

```c
if (condition) {
    // code runs only if condition is true
}
```

Example:

```c
int age = 20;

if (age >= 18) {
    printf("Adult\n");
}
```

Since `age` is 20, the condition is true.

Output:

```text
Adult
```

## if statement syntax

```c
if (condition) {
    statement;
}
```

Important parts:

```text
if = keyword
(condition) = true/false question
{ } = block of code
```

## if / else

`else` runs when the `if` condition is false.

```c
if (condition) {
    // runs if true
} else {
    // runs if false
}
```

Example:

```c
int age = 16;

if (age >= 18) {
    printf("Adult\n");
} else {
    printf("Minor\n");
}
```

Output:

```text
Minor
```

## else if

`else if` lets us check another condition.

```c
if (condition1) {
    // runs if condition1 is true
} else if (condition2) {
    // runs if condition1 is false, but condition2 is true
} else {
    // runs if all conditions above are false
}
```

Example:

```c
int score = 85;

if (score >= 90) {
    printf("A\n");
} else if (score >= 80) {
    printf("B\n");
} else if (score >= 70) {
    printf("C\n");
} else {
    printf("Fail\n");
}
```

Output:

```text
B
```

Why?

```text
score is 85
85 >= 90 is false
85 >= 80 is true
So it prints B and stops checking the rest.
```

## Important: else if checks from top to bottom

C checks conditions in order.

Example:

```c
int score = 95;

if (score >= 70) {
    printf("C or better\n");
} else if (score >= 90) {
    printf("A\n");
}
```

This is bad order.

Output:

```text
C or better
```

Why?

Because `95 >= 70` is true, so C runs the first block and does not reach the `score >= 90` check.

Better order:

```c
if (score >= 90) {
    printf("A\n");
} else if (score >= 70) {
    printf("C or better\n");
}
```

Rule:

```text
Put the most specific / highest condition first.
```
<>
## Comparison operators

Comparison operators compare values.

They return true or false.

```text
Operator     Meaning
-------------------------------
==           equal to
!=           not equal to
>            greater than
<            less than
>=           greater than or equal to
<=           less than or equal to
```

## == equal comparison

```c
if (age == 18) {
    printf("Age is exactly 18\n");
}
```

Important:

```text
== checks equality
= assigns value
```
<>
## = vs ==

This is one of the biggest C mistakes.

Assignment:

```c
age = 18;
```

Meaning:

```text
Put 18 into age.
```

Comparison:

```c
age == 18
```

Meaning:

```text
Check if age equals 18.
```

Wrong:

```c
if (age = 18) {
    printf("Age is 18\n");
}
```

This is wrong because it assigns 18 into age.

Correct:

```c
if (age == 18) {
    printf("Age is 18\n");
}
```

Memory rule:

```text
= means assign
== means compare
```

## != not equal

```c
if (age != 18) {
    printf("Age is not 18\n");
}
```

Meaning:

```text
If age is not equal to 18.
```

## > greater than

```c
if (age > 18) {
    printf("Older than 18\n");
}
```

## < less than

```c
if (age < 18) {
    printf("Younger than 18\n");
}
```

## >= greater than or equal

```c
if (age >= 18) {
    printf("Adult\n");
}
```

This includes 18.

## <= less than or equal

```c
if (age <= 18) {
    printf("18 or younger\n");
}
```

This includes 18.
<>
## Logical operators

Logical operators combine conditions.

```text
Operator     Name       Meaning
-----------------------------------------
&&           AND        both conditions must be true
||           OR         at least one condition must be true
!            NOT        flips true/false
```

## && AND

Both sides must be true.

```c
int age = 20;
int hasID = 1;

if (age >= 18 && hasID == 1) {
    printf("Can enter\n");
}
```

Meaning:

```text
age must be 18 or more
AND
hasID must be 1
```

If one side is false, the whole condition is false.

## || OR

Only one side needs to be true.

```c
int hasCash = 0;
int hasCard = 1;

if (hasCash == 1 || hasCard == 1) {
    printf("Can pay\n");
}
```

Meaning:

```text
If has cash OR has card, can pay.
```

## ! NOT

`!` flips true and false.

```c
int isRaining = 0;

if (!isRaining) {
    printf("Go outside\n");
}
```

Meaning:

```text
if not raining
```

Since `isRaining` is 0 / false, `!isRaining` becomes true.
<>
## True and false in C

C treats:

```text
0 = false
non-zero = true
```

Examples:

```c
if (0) {
    printf("This will not print\n");
}
```

```c
if (1) {
    printf("This will print\n");
}
```

```c
if (25) {
    printf("This will also print\n");
}
```

Because 25 is non-zero, C treats it as true.

## Using bool with conditions

If using `bool`, include:

```c
#include <stdbool.h>
```

Example:

```c
#include <stdio.h>
#include <stdbool.h>

int main() {
    bool isStudent = true;

    if (isStudent) {
        printf("Student\n");
    }

    return 0;
}
```

## Using % with if

Modulus `%` is useful with if statements.

Example: even or odd.

```c
int number = 10;

if (number % 2 == 0) {
    printf("Even\n");
} else {
    printf("Odd\n");
}
```

Why?

```text
number % 2 gives the remainder after dividing by 2.

If remainder is 0, the number is even.
If remainder is 1, the number is odd.
```

Examples:

```text
10 % 2 = 0  even
11 % 2 = 1  odd
```
<>
## Nested if

A nested if is an if statement inside another if statement.

Example:

```c
int age = 20;
int hasID = 1;

if (age >= 18) {
    if (hasID == 1) {
        printf("Can enter\n");
    } else {
        printf("Need ID\n");
    }
} else {
    printf("Too young\n");
}
```

Meaning:

```text
First check age.
If age is okay, then check ID.
```

Nested if works, but too much nesting can make code harder to read.

Sometimes `&&` is cleaner:

```c
if (age >= 18 && hasID == 1) {
    printf("Can enter\n");
}
```

## Common mistake 1: using = instead of ==

Wrong:

```c
if (age = 18) {
    printf("Age is 18\n");
}
```

Correct:

```c
if (age == 18) {
    printf("Age is 18\n");
}
```

## Common mistake 2: semicolon after if

Wrong:

```c
if (age >= 18);
{
    printf("Adult\n");
}
```

That semicolon ends the if statement too early.

Correct:

```c
if (age >= 18) {
    printf("Adult\n");
}
```

## Common mistake 3: wrong else if order

Bad:

```c
if (score >= 70) {
    printf("C\n");
} else if (score >= 90) {
    printf("A\n");
}
```

If score is 95, it prints C because 95 is already greater than 70.

Better:

```c
if (score >= 90) {
    printf("A\n");
} else if (score >= 70) {
    printf("C\n");
}
```

## Common mistake 4: forgetting braces

This works:

```c
if (age >= 18)
    printf("Adult\n");
```

But only one line belongs to the if.

Safer habit:

```c
if (age >= 18) {
    printf("Adult\n");
}
```

Use braces `{}` even when there is only one line.

## Common mistake 5: confusing && and ||

Use `&&` when both must be true.

```c
if (age >= 18 && hasID == 1)
```

Use `||` when at least one can be true.

```c
if (hasCash == 1 || hasCard == 1)
```

## What I need to remember

```text
if = run code only if condition is true
else = run code if if-condition is false
else if = check another condition

= means assign
== means compare

0 = false
non-zero = true

Comparison:
== equal
!= not equal
> greater than
< less than
>= greater than or equal
<= less than or equal

Logical:
&& AND
|| OR
! NOT

Use % with if to check even or odd:
number % 2 == 0 means even

Do not put semicolon after if.
Use braces { }.
Order matters in else if.
```
