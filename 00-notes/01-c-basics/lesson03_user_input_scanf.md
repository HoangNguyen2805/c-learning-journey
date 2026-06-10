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

## Mini lesson: char array / string input

In C, there is no simple `string` data type like some other languages.

Instead, C uses a **char array** to store text.

```c
char name[50];
```

Meaning:

```text
Create a box named name that can hold text.
The box has space for 50 characters.
```

## char vs char[]

`char` stores one character:

```c
char grade = 'A';
```

`char[]` stores text / many characters:

```c
char name[50];
```

Simple memory rule:

```text
char = one character
char[] = many characters / text
```

## Why do we write [50]?

```c
char name[50];
```

The `50` means C reserves 50 spaces in memory.

Example:

```text
Hoang
```

This needs 6 spaces in memory:

```text
H o a n g \0
```

The last one is hidden.

## What is \0?

C strings end with a hidden character called:

```text
\0
```

It means:

```text
end of string
```

So when we store:

```text
Hoang
```

C really stores:

```text
H o a n g \0
```

That is why `char name[50]` can store up to 49 visible characters.

The last space is saved for `\0`.

## scanf with char[]

To read a word into a char array:

```c
char name[50];

printf("Enter your name: ");
scanf("%s", name);
```

Important:

```text
char[] usually does not use &
```

So this is correct:

```c
scanf("%s", name);
```

This is not what we use right now:

```c
scanf("%s", &name);
```

## Why no & for char[]?

For normal variables, we use `&` because `scanf` needs the address.

Example:

```c
int age;
scanf("%d", &age);
```

But with an array:

```c
char name[50];
```

The name of the array already acts like the address of the first character.

So:

```c
scanf("%s", name);
```

means:

```text
Put the text starting at the first spot in the name array.
```

Simple rule for now:

```text
int uses &
float uses &
double uses &
char uses &
char[] does not use &
```

## scanf("%s") only reads one word

This works:

```text
Hoang
```

But this:

```text
Hoang Nguyen
```

will only store:

```text
Hoang
```

Because `scanf("%s", name)` stops when it sees a space.

We will learn how to read full names with spaces later using:

```c
fgets()
```

## Example program

```c
#include <stdio.h>

int main() {
    char name[50];

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Your name is %s.\n", name);

    return 0;
}
```

Example output:

```text
Enter your name: Hoang
Your name is Hoang.
```

## What I need to remember

```text
char = one character
char[] = text / string
char name[50] = text box with 50 spaces
C string ends with hidden \0
scanf("%s", name) reads one word
char[] does not use &
scanf("%s") stops at space
```
