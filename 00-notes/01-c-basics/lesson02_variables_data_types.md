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