# Day 03 - User Input with scanf

## scanf with different data types

`scanf` is used to read input from the keyboard.

Basic format:

```c
scanf("placeholder", &variable);
```

Example:

```c
int age;
scanf("%d", &age);
```

Meaning:

* `%d` tells scanf to read an integer.
* `&age` tells scanf where to store the input.

## printf vs scanf

`printf` is for output:

```c
printf("Age: %d\n", age);
```

`scanf` is for input:

```c
scanf("%d", &age);
```

Simple rule:

```text
printf uses the variable value.
scanf usually uses &variable.
```

## scanf format table

```text
Data type        scanf format        Example
---------------------------------------------------------
int              %d                  scanf("%d", &age);
float            %f                  scanf("%f", &price);
double           %lf                 scanf("%lf", &gpa);
char             %c                  scanf(" %c", &grade);
char[]           %s                  scanf("%s", name);
short            %hd                 scanf("%hd", &smallNumber);
long             %ld                 scanf("%ld", &population);
long long        %lld                scanf("%lld", &bigNumber);
unsigned int     %u                  scanf("%u", &count);
bool             use int input       read 1 or 0 first
void             no scanf            void means no value
```

## scanf with int

```c
int age;

printf("Enter your age: ");
scanf("%d", &age);
```

`%d` reads an integer.

Example input:

```text
25
```

## scanf with float

```c
float price;

printf("Enter price: ");
scanf("%f", &price);
```

`%f` reads a decimal number into a float.

Example input:

```text
9.99
```

## scanf with double

```c
double gpa;

printf("Enter GPA: ");
scanf("%lf", &gpa);
```

Important:

```text
For scanf, double uses %lf.
```

## scanf with char

```c
char grade;

printf("Enter grade: ");
scanf(" %c", &grade);
```

The space before `%c` is important.

```c
scanf(" %c", &grade);
```

The space means skip leftover Enter, spaces, or tabs before reading the character.

Without the space:

```c
scanf("%c", &grade);
```

`scanf` may read the leftover Enter key instead of the real character.

## scanf with char[]

```c
char name[50];

printf("Enter your name: ");
scanf("%s", name);
```

For `char[]`, usually do not use `&`.

```text
Normal variables usually use &.
Arrays/strings usually do not use &.
```

We will understand this more later when we learn arrays and pointers.

## scanf with bool

For bool, it is better to read an int first.

```c
#include <stdbool.h>

int input;
bool isStudent;

printf("Are you a student? Type 1 for yes, 0 for no: ");
scanf("%d", &input);

isStudent = input;
```

In C:

```text
true = 1
false = 0
```

So if the user types `1`, the bool becomes true.

If the user types `0`, the bool becomes false.

## void has no scanf

`void` means no value.

So we do not read input into `void`.

This does not exist:

```c
void x;
scanf(...);
```

`void` is used later for functions that return nothing.

Example:

```c
void sayHello() {
    printf("Hello\n");
}
```

## Why we do not practice all data types deeply today

Today’s main goal is to understand:

* `scanf`
* input from keyboard
* why `scanf` usually needs `&`
* why `%c` needs a space before it
* how user input gets stored inside variables

We will practice the most important types first:

```text
int
float
double
char
char[]
bool
```

Later, we will practice:

```text
short
long
long long
unsigned int
```

when we learn number ranges and memory size.

Later, we will learn:

```text
void
```

when we study functions.

## What I need to remember

```text
printf = output
scanf = input

printf("Age: %d\n", age);
scanf("%d", &age);

For scanf:
int -> %d
float -> %f
double -> %lf
char -> " %c"
char[] -> %s
```

Most important rule:

```text
gcc compiles.
./program runs.
printf prints.
scanf reads.
```
