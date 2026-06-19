# 1.2 Note - Operators and Math in C

## What is an operator?

An operator is a symbol that tells C to do something.

For math, operators tell C to add, subtract, multiply, divide, or find a remainder.

Example:

```c
int answer = 10 + 3;
```

The `+` is the operator.

## Main arithmetic operators

```text
Operator      Name                Example        Result
--------------------------------------------------------
+             Addition            10 + 3         13
-             Subtraction         10 - 3         7
*             Multiplication      10 * 3         30
/             Division            10 / 3         3
%             Modulus/Remainder   10 % 3         1
```

## Addition

```c
int result = 10 + 3;
```

Result:

```text
13
```

## Subtraction

```c
int result = 10 - 3;
```

Result:

```text
7
```

## Multiplication

In C, multiplication uses `*`.

```c
int result = 10 * 3;
```

Result:

```text
30
```

Do not use `x` for multiplication in C.

Wrong:

```c
int result = 10 x 3;
```

Correct:

```c
int result = 10 * 3;
```

## Division

float  = smaller decimal number, less precise
double = bigger decimal number, more precise

float  = about 6 to 7 digits total
double = about 15 to 16 digits total

float x = 3.1415926;
double y = 3.141592653589793;

In C, division uses `/`.

```c
int result = 10 / 3;
```

Result:

```text
3
```

Why not `3.333`?

Because both numbers are integers.

```c
10 / 3
```

means:

```text
integer divided by integer
```

So C gives an integer answer and removes the decimal part.

```text
10 / 3 = 3
```

## Decimal division

If you want decimal division, at least one number must be decimal.

```c
double result = 10.0 / 3;
```

Result:

```text
3.333333
```

Examples:

```c
10 / 3      // 3
10.0 / 3    // 3.333333
10 / 3.0    // 3.333333
10.0 / 3.0  // 3.333333
```

Simple rule:

```text
int / int = int
decimal / int = decimal
int / decimal = decimal
decimal / decimal = decimal
```

## Modulus / remainder

The `%` operator gives the remainder after division.

```c
int result = 10 % 3;
```

Think:

```text
10 divided by 3 = 3 remainder 1
```

So:

```text
10 % 3 = 1
```

More examples:

```text
10 % 2 = 0
10 % 3 = 1
10 % 4 = 2
10 % 5 = 0
11 % 5 = 1
12 % 5 = 2
13 % 5 = 3
14 % 5 = 4
15 % 5 = 0
```

## Why modulus is useful

Modulus is very useful in programming.

### Check even or odd

```c
if (number % 2 == 0) {
    printf("Even\n");
}
```

Meaning:

```text
If number divided by 2 has remainder 0, it is even.
```

Examples:

```text
10 % 2 = 0  even
11 % 2 = 1  odd
```

We will use this more when we learn `if` statements.

## Important: `%` only works with integer types

This is okay:

```c
int a = 10;
int b = 3;
int result = a % b;
```

This is not okay:

```c
float x = 10.5;
float y = 3.2;
float result = x % y;
```

`%` does not work with `float` or `double`.

Simple rule:

```text
% is for integers only.
```

## Division by zero

Never divide by zero.

Bad:

```c
int result = 10 / 0;
```

Bad:

```c
int result = 10 % 0;
```

This can crash the program or cause undefined behavior.

Simple rule:

```text
Do not use / 0
Do not use % 0
```

## Assignment operator

The `=` operator assigns a value.

```c
int x = 10;
```

Meaning:

```text
Put 10 into x.
```

Important:

```text
= does not mean equal in math.
= means assign value in C.
```

Later, for comparison, we use `==`.

```c
x = 10;   // assign 10 into x
x == 10;  // check if x equals 10
```


<>
## Assignment shortcut operators

These are shortcuts to update a variable.

```text
Operator      Meaning
-------------------------------
+=            add and assign
-=            subtract and assign
*=            multiply and assign
/=            divide and assign
%=            modulus and assign
```

## +=

```c
int x = 10;
x += 3;
```

Same as:

```c
x = x + 3;
```

Result:

```text
x = 13
```

## -=

```c
int x = 10;
x -= 3;
```

Same as:

```c
x = x - 3;
```

Result:

```text
x = 7
```

## *=

```c
int x = 10;
x *= 3;
```

Same as:

```c
x = x * 3;
```

Result:

```text
x = 30
```

## /=

```c
int x = 10;
x /= 3;
```

Same as:

```c
x = x / 3;
```

Result:

```text
x = 3
```

Because `x` is an integer.

## %=

```c
int x = 10;
x %= 3;
```

Same as:

```c
x = x % 3;
```

Result:

```text
x = 1
```
<>
## Increment operator

The `++` operator increases a variable by 1.

```c
int x = 10;
x++;
```

Same as:

```c
x = x + 1;
```

Result:

```text
x = 11
```
<>
## Decrement operator

The `--` operator decreases a variable by 1.

```c
int x = 10;
x--;
```

Same as:

```c
x = x - 1;
```

Result:

```text
x = 9
```
<>
## Post-increment vs pre-increment

There are two forms:

```c
x++;
++x;
```

If the line is only by itself, they do the same thing.

```c
x++;
++x;
```

Both add 1.

But inside another expression, they are different.

## Post-increment: x++

```c
int x = 5;
int y = x++;
```

Meaning:

```text
Use x first, then increase x.
```

Result:

```text
x = 6
y = 5
```

## Pre-increment: ++x

```c
int x = 5;
int y = ++x;
```

Meaning:

```text
Increase x first, then use x.
```

Result:

```text
x = 6
y = 6
```

Simple rule:

```text
x++ = use first, then add
++x = add first, then use
```

## Post-decrement and pre-decrement

Same idea:

```c
x--;
--x;
```

Post-decrement:

```c
int x = 5;
int y = x--;
```

Result:

```text
x = 4
y = 5
```

Pre-decrement:

```c
int x = 5;
int y = --x;
```

Result:

```text
x = 4
y = 4
```

## Operator precedence

Precedence means the order C does math.

C does:

```text
* / % before + -
```

Example:

```c
int result = 10 + 3 * 2;
```

C does multiplication first:

```text
3 * 2 = 6
10 + 6 = 16
```

Result:

```text
16
```

## Parentheses

Parentheses force C to do something first.

```c
int result = (10 + 3) * 2;
```

C does parentheses first:

```text
10 + 3 = 13
13 * 2 = 26
```

Result:

```text
26
```

Simple rule:

```text
Use parentheses when you want to make the order clear.
```

## Precedence order for Day 04

For now, remember this order:

```text
1. Parentheses: ()
2. Multiplication, division, modulus: * / %
3. Addition, subtraction: + -
4. Assignment: =
```

## Left to right

Operators with the same precedence usually go left to right.

Example:

```c
int result = 20 / 5 * 2;
```

C reads left to right:

```text
20 / 5 = 4
4 * 2 = 8
```

Result:

```text
8
```

Example:

```c
int result = 20 - 5 - 2;
```

C reads left to right:

```text
20 - 5 = 15
15 - 2 = 13
```

Result:

```text
13
```
<>
## Negative numbers with %

In C, the sign of the remainder usually follows the left number.

Example:

```c
-10 % 3
```

Result:

```text
-1
```

Example:

```c
10 % -3
```

Result:

```text
1
```

For beginner practice, we mostly use positive numbers with `%`.

## int math vs double math

If both numbers are `int`, the result is `int`.

```c
int result = 10 / 3;
```

Result:

```text
3
```

If one number is `double`, the result can be decimal.

```c
double result = 10.0 / 3;
```

Result:

```text
3.333333
```

## Casting

Casting means temporarily treating a value as another type.

Example:

```c
int a = 10;
int b = 3;

double result = (double)a / b;
```

Result:

```text
3.333333
```

Why?

Because `(double)a` changes `a` into a double for this calculation.

Without casting:

```c
double result = a / b;
```

Result:

```text
3.000000
```

Because `a / b` happens first as integer division.

Simple rule:

```text
(double)a / b gives decimal division.
a / b gives integer division if both are int.
```

## Common mistakes

### Mistake 1: Expecting int division to show decimal

```c
int result = 10 / 3;
```

Result:

```text
3
```

Not:

```text
3.333
```

### Mistake 2: Using % with float or double

Wrong:

```c
double x = 10.5;
double y = 3.0;
double result = x % y;
```

`%` only works with integers.

### Mistake 3: Dividing by zero

Wrong:

```c
int result = 10 / 0;
```

Wrong:

```c
int result = 10 % 0;
```

### Mistake 4: Confusing = and ==

```c
x = 10;   // assignment
x == 10;  // comparison
```

### Mistake 5: Forgetting parentheses

```c
int result = 10 + 3 * 2;
```

Result:

```text
16
```

If you wanted 26, write:

```c
int result = (10 + 3) * 2;
```
<>
## What I need to remember

```text
+  addition
-  subtraction
*  multiplication
/  division
%  remainder

int / int = int
10 / 3 = 3

Use decimal or casting for decimal division:
10.0 / 3
(double)a / b

% only works with integers.

Do not divide by 0.
Do not use % 0.

= assigns a value.
== checks equality.

x += 3 means x = x + 3.
x++ means add 1.
x-- means subtract 1.

* / % happen before + -.
Use parentheses to control order.
```

## Printing symbols in printf

Most symbols can be printed normally inside `printf`.

Example:

```c
printf("Symbols: ! @ # $ ^ & *\n");
```

Output:

```text
Symbols: ! @ # $ ^ & *
```

## The percent sign `%` is special

The percent sign `%` is special in `printf` because `printf` uses `%` for placeholders.

Examples:

```c
%d   // int
%f   // float or double
%c   // char
%s   // string
```

So if we want to print a real `%` symbol, we must write:

```c
%%
```

Example:

```c
printf("Percent sign: %%\n");
```

Output:

```text
Percent sign: %
```

## Example with modulus

```c
printf("10 %% 3 = %d\n", 10 % 3);
```

Output:

```text
10 % 3 = 1
```

In this line:

```c
printf("10 %% 3 = %d\n", 10 % 3);
```

`%%` prints the real `%` symbol.

`%d` prints the integer answer.

`10 % 3` does the actual modulus math.

## What I need to remember

```text
! @ # $ ^ & * = print normally

% = special in printf

To print a real percent sign:
%%
```

---
---
# 1.2A - Variables and Data Types

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

---

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
---
---

## 1.2B - printf Placeholders and Formatting

`printf` is used to print output to the screen.

A placeholder tells `printf` what type of value to print.

A placeholder starts with `%`.

Example:

```c
int age = 25;

printf("Age: %d\n", age);
```

Output:

```text
Age: 25
```

The `%d` is a placeholder for an integer.

---

## Why placeholders are needed

C needs placeholders because different values have different data types.

Example:

```c
int age = 25;
double gpa = 3.75;
char grade = 'A';
char name[] = "Hoang";
```

Each one uses a different placeholder:

```c
printf("Age: %d\n", age);
printf("GPA: %.2f\n", gpa);
printf("Grade: %c\n", grade);
printf("Name: %s\n", name);
```

---

## Common printf placeholders

```text
%d = decimal integer
%f = decimal number / floating-point number
%c = one character
%s = string / character array
%o = octal integer
%x = hexadecimal integer
%% = percent sign
```

---

## %d - Decimal Integer

Use `%d` for normal whole numbers.

```c
int age = 25;

printf("Age: %d\n", age);
```

Output:

```text
Age: 25
```

`%d` prints the number in base 10.

Base 10 is the normal number system we use every day.

---

## %f - Floating-Point Number

Use `%f` for `float` or `double` values in `printf`.

```c
double price = 12.5;

printf("Price: %f\n", price);
```

Output:

```text
Price: 12.500000
```

By default, `%f` prints 6 digits after the decimal.

---

## %.2f - Decimal Places

Use `%.2f` to print 2 digits after the decimal.

```c
double price = 12.5;

printf("Price: %.2f\n", price);
```

Output:

```text
Price: 12.50
```

The `.2` means 2 decimal places.

Examples:

```text
%.1f = 1 digit after decimal
%.2f = 2 digits after decimal
%.3f = 3 digits after decimal
```

---

## %c - Character

Use `%c` for one character.

```c
char grade = 'A';

printf("Grade: %c\n", grade);
```

Output:

```text
Grade: A
```

A `char` uses single quotes:

```c
char grade = 'A';
```

---

## %s - String

Use `%s` for a string or character array.

```c
char name[] = "Hoang";

printf("Name: %s\n", name);
```

Output:

```text
Name: Hoang
```

A string uses double quotes:

```c
char name[] = "Hoang";
```

---

## %o - Octal Integer

Use `%o` to print an integer in octal.

Octal means base 8.

```c
int number = 255;

printf("%o\n", number);
```

Output:

```text
377
```

So decimal `255` is octal `377`.

---

## %x - Hexadecimal Integer

Use `%x` to print an integer in hexadecimal.

Hexadecimal means base 16.

```c
int number = 255;

printf("%x\n", number);
```

Output:

```text
ff
```

So decimal `255` is hexadecimal `ff`.

Use `%X` for uppercase hexadecimal:

```c
printf("%X\n", number);
```

Output:

```text
FF
```

---

## %% - Percent Sign

The `%` symbol is special in `printf`.

It starts a placeholder.

So if you want to print a real percent sign, use `%%`.

```c
printf("Score: 90%%\n");
```

Output:

```text
Score: 90%
```

---

## Field Width

Field width means the minimum amount of space used when printing a value.

Example:

```c
printf("%3d\n", 7);
```

Output:

```text
  7
```

`%3d` means:

```text
print an integer using at least 3 spaces wide
```

Since `7` only uses 1 space, C adds 2 spaces before it.

---

## Field Width Example

```c
printf("%3d %6d\n", 0, -17);
printf("%3d %6d\n", 20, -6);
printf("%3d %6d\n", 100, 37);
```

Output:

```text
  0    -17
 20     -6
100     37
```

This is useful for making columns line up like a table.

---

## Right Alignment

By default, field width is right-aligned.

```c
printf("|%6d|\n", 7);
```

Output:

```text
|     7|
```

The number is pushed to the right.

---

## Left Alignment

Use `-` to left-align the value.

```c
printf("|%-6d|\n", 7);
```

Output:

```text
|7     |
```

The number is pushed to the left.

---

## Zero Padding

Use `0` before the width to fill empty spaces with zeros.

```c
printf("%05d\n", 7);
```

Output:

```text
00007
```

`%05d` means:

```text
print an integer using width 5
fill empty spaces with 0
```

---

## Width With Decimal Numbers

You can also use field width with decimals.

```c
double price = 12.5;

printf("|%8.2f|\n", price);
```

Output:

```text
|   12.50|
```

`%8.2f` means:

```text
8 = total minimum width
.2 = two digits after decimal
f = floating-point number
```

---

## Left Align With Decimal Numbers

```c
double price = 12.5;

printf("|%-8.2f|\n", price);
```

Output:

```text
|12.50   |
```

The `-` means left-align.

---

## Placeholder Pattern

The common pattern is:

```text
%[flags][width][.precision][type]
```

Do not type the brackets. They only show the parts.

Example:

```c
printf("%8.2f\n", price);
```

Breakdown:

```text
% = starts placeholder
8 = width
.2 = precision
f = type
```

---

## Flags

Flags change how the value is printed.

Common flags:

```text
- = left-align
0 = zero padding
```

Examples:

```c
printf("|%6d|\n", 7);
printf("|%-6d|\n", 7);
printf("|%06d|\n", 7);
```

Output:

```text
|     7|
|7     |
|000007|
```

---

## Width

Width controls minimum space.

```c
printf("|%5d|\n", 42);
```

Output:

```text
|   42|
```

If the value is longer than the width, C still prints the full value.

```c
printf("|%3d|\n", 12345);
```

Output:

```text
|12345|
```

Width does not cut off the number.

---

## Precision

Precision means different things depending on the placeholder.

For `%f`, precision controls digits after the decimal.

```c
printf("%.2f\n", 3.14159);
```

Output:

```text
3.14
```

For `%s`, precision controls the maximum number of characters printed.

```c
printf("%.3s\n", "Hoang");
```

Output:

```text
Hoa
```

---

## Width and Precision Together

```c
printf("|%8.2f|\n", 3.5);
```

Output:

```text
|    3.50|
```

Meaning:

```text
total width = 8
decimal places = 2
```

---

## Important scanf Difference

Do not confuse `printf` and `scanf`.

For `printf`, use:

```c
printf("%.2f\n", price);
```

For `scanf`, do not use `.2`.

Wrong:

```c
scanf("%.2lf", &price);
```

Correct:

```c
scanf("%lf", &price);
```

Memory rule:

```text
printf double = %f or %.2f
scanf double  = %lf
```

---

## Common Mistakes

Wrong placeholder type:

```c
int age = 25;
printf("%f\n", age);
```

Wrong because `age` is an `int`, not a decimal number.

Correct:

```c
printf("%d\n", age);
```

---

Wrong string placeholder:

```c
char grade = 'A';
printf("%s\n", grade);
```

Wrong because `grade` is one character.

Correct:

```c
printf("%c\n", grade);
```

---

Wrong percent sign:

```c
printf("Score: 90%\n");
```

Wrong because `%` starts a placeholder.

Correct:

```c
printf("Score: 90%%\n");
```

---

## Quick Reference Table

| Placeholder | Meaning                      | Example     |
| ----------- | ---------------------------- | ----------- |
| `%d`        | decimal integer              | `25`        |
| `%f`        | decimal number               | `12.500000` |
| `%.2f`      | decimal with 2 digits        | `12.50`     |
| `%c`        | one character                | `A`         |
| `%s`        | string                       | `Hoang`     |
| `%o`        | octal integer                | `377`       |
| `%x`        | hexadecimal integer          | `ff`        |
| `%X`        | uppercase hexadecimal        | `FF`        |
| `%%`        | percent sign                 | `%`         |
| `%6d`       | integer width 6              | `     7`    |
| `%-6d`      | left-aligned integer width 6 | `7     `    |
| `%05d`      | zero-padded integer width 5  | `00007`     |
| `%8.2f`     | decimal width 8, 2 decimals  | `   12.50`  |
| `%-8.2f`    | left-aligned decimal width 8 | `12.50   `  |

---

## Memory Rule

```text
%d = normal integer
%f = decimal number
%.2f = decimal number with 2 decimal places
%c = one character
%s = string
%o = octal
%x = hexadecimal
%% = percent sign

width controls spacing
precision controls decimal places for floats
- means left-align
0 means zero padding
```


--- 
---

## 1.2C - Arithmetic Operators

Arithmetic operators are used to do basic math in C.

The main arithmetic operators are:

```text
+   addition
-   subtraction
*   multiplication
/   division
%   remainder / modulus
```

---

## Example

```c
int a = 10;
int b = 3;
```

Using those values:

```text
a + b = 13
a - b = 7
a * b = 30
a / b = 3
a % b = 1
```

---

## Addition

```c
a + b
```

Adds two numbers.

Example:

```c
printf("Addition: %d + %d = %d\n", a, b, a + b);
```

Output:

```text
Addition: 10 + 3 = 13
```

---

## Subtraction

```c
a - b
```

Subtracts the second number from the first number.

Example:

```c
printf("Subtraction: %d - %d = %d\n", a, b, a - b);
```

Output:

```text
Subtraction: 10 - 3 = 7
```

---

## Multiplication

```c
a * b
```

Multiplies two numbers.

Example:

```c
printf("Multiplication: %d * %d = %d\n", a, b, a * b);
```

Output:

```text
Multiplication: 10 * 3 = 30
```

---

## Division

```c
a / b
```

Divides the first number by the second number.

Example:

```c
printf("Division: %d / %d = %d\n", a, b, a / b);
```

Output:

```text
Division: 10 / 3 = 3
```

Because `a` and `b` are both `int`, C does integer division.

That means C removes the decimal part.

```text
10 / 3 = 3.333...
C keeps only 3
```

---

## Modulus / Remainder

```c
a % b
```

Gives the remainder after division.

Example:

```c
printf("Remainder: %d %% %d = %d\n", a, b, a % b);
```

Output:

```text
Remainder: 10 % 3 = 1
```

Because:

```text
10 / 3 = 3 remainder 1
```

---

## Important printf rule for %

In `printf`, `%` is special because it starts format specifiers like `%d`.

So if you want to print a real percent sign or modulus symbol, use:

```c
%%
```

Example:

```c
printf("Remainder: %d %% %d = %d\n", a, b, a % b);
```

---

## Memory rule

```text
+ means add
- means subtract
* means multiply
/ means divide
% means remainder
```

Use `%` when you need the remainder.

Use `%%` inside `printf` when you want to print the `%` symbol.

---
---

## 1.2D - Integer vs Decimal Division

If both values are integers, C does integer division.

Example:

10 / 3 = 3

C removes the decimal part.

Even if the answer is stored inside a double, the calculation already happened as integer division first.

Example:

double result = 10 / 3;

This gives:

3.00

To get decimal division, at least one value must be decimal.

Example:

double result = 10.0 / 3;

This gives:

3.33

Another way is casting:

int a = 10;
int b = 3;

double result = (double)a / b;

This temporarily treats a as a double, so the answer is decimal.

Important rules:

int / int = int
double / int = double
int / double = double
double / double = double

If I want decimal division from int variables, use casting:

(double)a / b

---
---

## 1.2E - Modulus / Remainder

The % operator gives the remainder after division.

Example:

10 / 3 = 3
10 % 3 = 1

Meaning:

10 divided by 3 = 3 remainder 1.

The / operator gives the quotient.
The % operator gives the remainder.

More examples:

10 % 2 = 0
10 % 3 = 1
10 % 4 = 2
10 % 5 = 0

% is useful for checking even or odd.

10 % 2 = 0 means even.
11 % 2 = 1 means odd.

Important:

% only works with integer types.

Do not use % with float or double.
Do not use % 0.

---
---

## 1.2F - Assignment Shortcuts

Assignment shortcuts update the same variable.

x += 3 means x = x + 3
x -= 2 means x = x - 2
x *= 4 means x = x * 4
x /= 2 means x = x / 2
x %= 5 means x = x % 5

Example:

int x = 10;

x += 3;   x becomes 13
x -= 2;   x becomes 11
x *= 4;   x becomes 44
x /= 2;   x becomes 22
x %= 5;   x becomes 2

Important:
The value of x changes after every line.

So x %= 5 is not 10 % 5.
It is 22 % 5 because x already changed to 22.

22 % 5 = 2

---
---

## 1.2G - Increment and Decrement

x++ means add 1 to x.
++x means add 1 to x.
x-- means subtract 1 from x.
--x means subtract 1 from x.

If the line is by itself, x++ and ++x do almost the same thing.

Example:

int x = 5;
x++;
// x becomes 6

++x;
// x becomes 7

The difference matters when it is inside another assignment.

Post-increment:

int a = 5;
int b = a++;

a++ means use old value first, then add 1.

Step:
b = 5
a = 6

Final:
a = 6
b = 5

Pre-increment:

int c = 5;
int d = ++c;

++c means add 1 first, then use the new value.

Step:
c = 6
d = 6

Final:
c = 6
d = 6

Memory rule:

x++ = use first, then add
++x = add first, then use

x-- = use first, then subtract
--x = subtract first, then use

---
---

## 1.2H - Precedence and Parentheses

Precedence means the order C does math.

C does:

1. Parentheses first: ()
2. Multiplication, division, modulus next: * / %
3. Addition and subtraction next: + -
4. Assignment last: =

Example:

10 + 3 * 2 = 16

C does 3 * 2 first, then adds 10.

But:

(10 + 3) * 2 = 26

Parentheses force 10 + 3 to happen first.

If operators have the same precedence, C usually goes left to right.

Example:

20 / 5 * 2 = 8

C does:

20 / 5 = 4
4 * 2 = 8

Subtraction also goes left to right.

20 - 5 - 2 = 13

C does:

20 - 5 = 15
15 - 2 = 13

Parentheses can change the answer:

20 - (5 - 2) = 17

C does:

5 - 2 = 3
20 - 3 = 17

Memory rule:

Parentheses first.
Then * / %.
Then + -.
Use parentheses when the order might be confusing.

---