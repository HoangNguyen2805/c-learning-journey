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
----------------------------------------------------------------------------------------

        What is scanf ?
    We have already learn that data type and variable can hold value , and
we able to asign value into it. Then inorder to displace that value in terminal,
we have to use printf with data plave holder to displace it as an output. Everything
have to be done by the programer, BUT what if the user want to asign value them self
as an input ?
    - We will use scanf to allow use input the own data.
            printf = print/output
            scanf = scan/read/input
    Today we let the user type the value.
Example:
    int age;

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Your age is %d\n", age);

Meaning:
    int age; = create an empty variable named age
    printf = ask the user a question
    scanf = read what the user types
    &age = store the typed value inside age

Common scanf formats
    int      -> scanf("%d", &age);
    float    -> scanf("%f", &price);
    double   -> scanf("%lf", &gpa);
    char     -> scanf(" %c", &grade);
    char[]   -> scanf("%s", name);

For double, scanf uses:
    scanf("%lf", &gpa);
For printf, double can use:
    printf("%f\n", gpa);

char[] does not use &
    char name[50];
    scanf("%s", name);
Not:
    scanf("%s", &name);
Remember: 
    normal variables use &
    arrays/strings usually do not use &

    The format of scanf and ALMOST the same but NOT EXACTLY the same as printf , where 
    - printf = printf("text + placeholder", variable);
    But 
    - scanf = scanf("%d", &age);

    You CAN put text inside scanf, but usually you should not when learning.
    Notice: scanf can contain text, but it is not used for normal prompts.
If text is inside scanf, the user input must match that text exactly.
Better habit: use printf to ask, then scanf to read.
    Why ?
    Ex:
    scanf("Age: %d", &age);
    The user must LITERALLY type -> Age: 25 
    Istead of just -> 25
    scanf expecte user to type -> Age: <- first.

    BUT other than that, THE ONLY DIFFERENT that printf doesn't have that scanf have is
            &
        next to the variable. What is & and why it's important ?
    Why does scanf need &?
        - Because scanf needs to know WHERE THE VARIABLE LIVES IN MEMORY so it can change
        the value inside it.
    Think:
        printf only looks at the value.
        scanf needs to put a new value into the variable.
    SO & is like a poiter that point the user's inut to the correct Variable.
    
One important char rule
    Use a space before %c:
        scanf(" %c", &grade);
    - The space helps skip leftover Enter/newline from previous input.

----------------------------------------------------------------------------------------

input buffer
Ex:
    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter a price: ");
    scanf("%f", &price);

    printf("Enter your grade: ");
    scanf("%c", &grade);

Output:
Enter your age: 25
Enter a price: 9.99
Enter your grade: 
---result---
Age: 25
Price: 9.99
Grade: 

Why can't we enter grade ? 
- Because of in put buffer in this line -> scanf("%c", &grade);
After you typed price 9.99 and pressed Enter, that Enter key is
still waiting in the input buffer. %c reads that Enter instead of waiting for A.

To Fix this adding space in front of %c
That space means: skip whitespace like Enter, spaces, tabs then read the character

Fix from this:
    scanf("%c", &grade);
To This:
    scanf(" %c", &grade);

Simple memory rule
%d, %f, %lf = skip whitespace automatically
%c = does not skip whitespace unless you put a space before it
So:
scanf("%d", &age);      // okay
scanf("%f", &price);    // okay
scanf(" %c", &grade);   // use space before %c

----------------------------------------------------------------------------------------