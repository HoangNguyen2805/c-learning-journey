#include <stdio.h>

int main() {

    int age;
    int hasID;
    int score;

    printf("Enter age: ");
    scanf("%d", &age);

    printf("Do you have ID? 1 yes, 0 no: ");
    scanf("%d", &hasID);

    printf("Enter score: ");
    scanf("%d", &score);

    printf("\n--- Nested if Example ---\n");

    /*
    Main idea:

    nested if = if inside another if

    First check age.
    If age is okay, then check ID.

    else if order matters:
    check 90 before 80 before 70
    */

    if (age >= 18) {
        if (hasID == 1) {
            printf("You can enter.\n");
        } else {
            printf("You are old enough, but you need ID.\n");
        }
    } else {
        printf("You are too young.\n");
    }

    printf("\n--- else if order example ---\n");

    if (score >= 90) {
        printf("Grade: A\n");
    } else if (score >= 80) {
        printf("Grade: B\n");
    } else if (score >= 70) {
        printf("Grade: C\n");
    } else {
        printf("Grade: F\n");
    }

    printf("Program finished.\n");

    return 0;
}

/*
## Lesson 05F - Nested if and Common Mistakes

Nested if means an if statement inside another if statement.

Example:

if (age >= 18) {
    if (hasID == 1) {
        printf("You can enter.\n");
    } else {
        printf("You are old enough, but you need ID.\n");
    }
} else {
    printf("You are too young.\n");
}

Meaning:

First check age.
If age is 18 or older, then check ID.
If age is below 18, skip the ID check.

Common mistakes:

1. Using = instead of ==

Wrong:
if (age = 18)

Correct:
if (age == 18)

= assigns value.
== compares value.

2. Semicolon after if

Wrong:
if (age >= 18);
{
    printf("Adult\n");
}

Correct:
if (age >= 18) {
    printf("Adult\n");
}

3. Wrong else-if order

Wrong:
if (score >= 70) {
    printf("C\n");
} else if (score >= 90) {
    printf("A\n");
}

Correct:
if (score >= 90) {
    printf("A\n");
} else if (score >= 70) {
    printf("C\n");
}

Order matters because C checks from top to bottom.

4. Missing braces

This works but is risky:
if (age >= 18)
    printf("Adult\n");

Better:
if (age >= 18) {
    printf("Adult\n");
}

*/

/*
## Nested if vs &&

A nested if means an if statement inside another if statement.

Example:

```c
if (age >= 18) {
    if (hasID == 1) {
        printf("You can enter.\n");
    }
}
```

This means:

```text
First check age.
If age is 18 or older, then check ID.
Both conditions must be true before printing.
```

This is very similar to using `&&`.

Example:

```c
if (age >= 18 && hasID == 1) {
    printf("You can enter.\n");
}
```

This also means:

```text
age must be 18 or older
AND
hasID must be 1
```

So these two are logically similar:

```c
if (age >= 18) {
    if (hasID == 1) {
        printf("You can enter.\n");
    }
}
```

and:

```c
if (age >= 18 && hasID == 1) {
    printf("You can enter.\n");
}
```

Both require:

```text
age >= 18
hasID == 1
```

## When nested if is useful

Nested if is useful when I want to give different messages depending on which condition failed.

Example:

```c
if (age >= 18) {
    if (hasID == 1) {
        printf("You can enter.\n");
    } else {
        printf("You are old enough, but you need ID.\n");
    }
} else {
    printf("You are too young.\n");
}
```

This explains the reason:

```text
If age is too low, print too young.
If age is okay but no ID, print need ID.
If both are good, print can enter.
```

## When && is useful

`&&` is useful when I only care that both conditions are true, and I do not need separate reasons.

Example:

```c
if (age >= 18 && hasID == 1) {
    printf("You can enter.\n");
} else {
    printf("You cannot enter.\n");
}
```

This is shorter and cleaner.

## Memory rule

```text
nested if = good for step-by-step checks and different failure messages

&& = good when both conditions just need to be true
```


*/