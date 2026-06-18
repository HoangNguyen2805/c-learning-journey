# Day 02 - Variables and Data Types

## Phase

Still in Phase 1: C Basics.

## Big idea

A variable is a named box that stores a value.

A data type tells C what kind of value the variable can store.

Example:

int age = 25;

Meaning:
- int = data type
- age = variable name
- 25 = value

## Data types learned today

int = whole number

Example:
int age = 25;

float = decimal number

Example:
float price = 9.99;

double = more precise decimal number

Example:
double gpa = 3.75;

char = one character

Example:
char grade = 'A';

char[] = text/string, many characters together

Example:
char name[] = "Hoang";

bool = true or false

Example:
bool isStudent = true;

To use bool, I need:

#include <stdbool.h>

## Single quotes vs double quotes

Single character uses single quotes:

char grade = 'A';

Text/string uses double quotes:

char name[] = "Hoang";

## My Day 02 code

#include <stdio.h>
#include <stdbool.h>

int main() {
    int age = 25;
    float price = 9.99;
    double gpa = 3.75;
    char grade = 'A';
    char name[] = "Hoang";
    bool isStudent = true;

    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("Price: %.2f\n", price);
    printf("GPA: %.2f\n", gpa);
    printf("Grade: %c\n", grade);
    printf("Is student: %d\n", isStudent);

    return 0;
}

## printf placeholders

%s = string/text

%d = integer number

%.2f = decimal number with 2 digits after the decimal point

%c = one character

%d = bool as 1 or 0

## Why bool prints as 1 or 0

In C:

true = 1

false = 0

So if I write:

bool isStudent = true;

and print it with:

printf("Is student: %d\n", isStudent);

The output is:

Is student: 1

## Output

Name: Hoang
Age: 25
Price: 9.99
GPA: 3.75
Grade: A
Is student: 1

## What I need to remember

Variable = named box that stores a value.

Data type = kind of value the box can store.

C needs placeholders in printf to print variables correctly.

Important types:
- int
- float
- double
- char
- char[]
- bool

Important placeholders:
- %d
- %f
- %.2f
- %c
- %s

----------------------------------------------------------------------------------------

A Variable = a 'named box' that "Stores A Value".
A Data Type = a 'lable' on the box that says "what kind of thing (value) 
              can go inside (store) the Variable".
Ex: Create a variable named age that stores the whole number 25.
    int age = 25;

    Think:
        int = type of value (It's an Interger)
        age = variable name
        25 = value store inside Variable (age)

When you use printf, you need the correct placeholder for the data type. We don't write
    out raw date number, we use:
        ("%__, age");
    to displace the raw data number or value that have store in specific variable, and 
    to dis place the correct value of that specific variable we comma and add the variable
    within the (" ").

    Ex: printf needs placeholders:
        int      -> %d
        float    -> %f
        double   -> %f
        char     -> %c
        char[]   -> %s
        bool     -> %d

Basic data types:
1. int = Stores whole numbers.
    Ex:
        int age = 25;
        int year = 2026;
        int score = -10;
    Use %d to print:
        printf("Age: %d\n", age);

2. float = Stores decimal numbers (6-7 digits AFTER the decimal).
    Ex:
        float price = 9.99;
        float temperature = 98.6;
    Use %f to print:
        printf("Price: %f\n", price);
    Usually we use %.2f to show 2 decimal places:
        printf("Price: %.2f\n", price);
            Output:
            Price: 9.99
3. double = Stores decimal numbers with more precision than float (15-16 digits AFTER the decimal).
    Ex:
        double gpa = 3.754321;
        double pi = 3.1415926535;
    Use %f or %lf in printf:
        printf("GPA: %.2f\n", gpa);

    float = decimal
    double = more accurate decimal

4. char = Stores ONLY 1 Charcter in a SINGlE ' ' (NOT DOUBLE " ")
    Ex:
        char grade = 'A';
        char letter = 'h';
        char symbol = '$';
    Use %c to print:
        printf("Grade: %c\n", grade);
    Important:
        char grade = 'A';      // correct
        char grade = "A";      // wrong for char

Modified integer ( int ) types - These are variations of whole numbers.
5. short = Stores smaller whole numbers ( same as int but only SMALL number with FEWER Digits).
    Ex:
        short smallNumber = 100;
    Use %hd:
        printf("%hd\n", smallNumber);

6. long = Stores biger whole number than int.
    Ex:
        long population = 8000000000;
    Use %ld:
        printf("%ld\n", population);

7. long long = Stores very big whole numbers.
    Ex:
        long long bigNumber = 9000000000000;
    Use %lld:
        printf("%lld\n", bigNumber);

Positive-only integer types
8. unsigned int = Stores only zero or positive whole numbers.
    Ex:
        unsigned int count = 50;
    Use %u:
        printf("%u\n", count);
    Meaning: Meaning:

Boolean type
9. bool = Stores true or false.
    To use bool, we have to # this header:
        #include <stdbool.h>
    Example:
        #include <stdio.h>
        #include <stdbool.h>

        int main() {
            bool isPassing = true;

            printf("Is passing: %d\n", isPassing);

            return 0;
        }
    Output:
        Is passing: 1

    In C:
        true = 1
        false = 0

Text / string 
10. char[] = In C, we store string like text and sentence or multiple character
             As An ARRAY.
    Ex:
        char name[] = "Hoang";
    Print with %s:
        printf("Name: %s\n", name);

    Important:
        char = one character
            Ex: char grade = 'A';
        char[] = text/string
            Ex: char name[] = "Hoang";

Special type
11. void = Means “no value.” USe in naming function.
    Ex:
        void sayHello() {
            printf("Hello\n");
        }
    Meaning:
        This function does not return a value.

----------------------------------------------------------------------------------------
## Lesson 02G - Constant Variables with const

A constant variable is a variable that cannot be changed after it is created.

In C, we use:

```c
const
```

---

## Basic example

```c
const int MAX_SCORE = 100;
```

This means:

```text
MAX_SCORE is an int
MAX_SCORE stores 100
MAX_SCORE cannot be changed later
```

---

## Why use const?

Use `const` when a value should stay the same for the whole program.

Examples:

```c
const int MAX_SCORE = 100;
const int PASSING_SCORE = 70;
const double TAX_RATE = 0.0825;
const double PI = 3.14159;
```

These values should not randomly change.

---

## Normal variable vs const variable

Normal variable:

```c
int score = 90;
score = 95;
```

This is allowed because `score` is not constant.

Constant variable:

```c
const int MAX_SCORE = 100;
MAX_SCORE = 90;
```

This is wrong because `MAX_SCORE` is constant.

---

## Example program

```c
#include <stdio.h>

int main() {
    const int PASSING_SCORE = 70;

    int score;

    printf("Enter score: ");
    scanf("%d", &score);

    if (score >= PASSING_SCORE) {
        printf("Pass\n");
    } else {
        printf("Fail\n");
    }

    return 0;
}
```

---

## const with double

```c
const double TAX_RATE = 0.0825;
```

Example:

```c
double subtotal = 30.00;
double tax = subtotal * TAX_RATE;
```

---

## Naming style

Many C programmers write constant names in all caps:

```c
const int MAX_SCORE = 100;
const double TAX_RATE = 0.0825;
```

This makes it easy to see that the value should not change.

---

## Important rule

You must give a `const` variable a value when you create it.

Correct:

```c
const int MAX_SCORE = 100;
```

Wrong:

```c
const int MAX_SCORE;
MAX_SCORE = 100;
```

Because once a const variable is created, you cannot assign a new value later.

---

## Memory rule

```text
normal variable = value can change

const variable = value cannot change

const protects important values from being changed by mistake
```
---
