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


---




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