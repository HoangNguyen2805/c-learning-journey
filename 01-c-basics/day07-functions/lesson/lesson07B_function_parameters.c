#include <stdio.h>

void printNumber(int number) {
    printf("The number is: %d\n", number);
}

int main() {
    printf("--- Function Parameters ---\n");

    printNumber(5);
    printNumber(10);
    printNumber(25);

    printf("Program finished.\n");

    return 0;
}

/*
## Lesson 07B - Function With Parameters

## Function Parameters vs Function Arguments

When learning functions, there are two important places:

1. Function definition
2. Function call

They look similar, but they do different jobs.

---

## 1. Function definition

A function definition is where we create the function.

Example:

```c
int addNumbers(int a, int b) {
    return a + b;
}
```

This part is the function definition:

```c
int addNumbers(int a, int b)
```

The parameters are:

```c
int a, int b
```

A parameter is like an empty box waiting to receive a value.

In a function definition, we write:

```text
data type + parameter name
```

Example:

```c
int a
int b
```

This means:

```text
This function needs two int values.
Inside the function, call the first value a.
Inside the function, call the second value b.
```

Allowed in a function definition:

```c
int age
double price
float average
char grade
char name[]
char name[50]
bool isPassed
```

Examples:

```c
void printAge(int age)

double calculateTotal(double price, int quantity)

void printGrade(char grade)

void printName(char name[])

int addNumbers(int a, int b)
```

Do not put real values in the function definition.

Wrong:

```c
int addNumbers(5, 3)
```

Wrong:

```c
int addNumbers(int 5, int 3)
```

Correct:

```c
int addNumbers(int a, int b)
```

---

## 2. Function call

A function call is when we use the function.

Example:

```c
result = addNumbers(5, 3);
```

This part is the function call:

```c
addNumbers(5, 3)
```

The values inside the call are called arguments.

The arguments are:

```c
5, 3
```

In a function call, we do not write the data type again.

We only pass:

```text
actual values
variables
math expressions
other function results
```

Allowed in a function call:

```c
addNumbers(5, 3);

addNumbers(x, y);

addNumbers(score1, score2);

addNumbers(x + 2, y * 3);
```

Wrong:

```c
addNumbers(int x, int y);
```

Wrong:

```c
addNumbers(int 5, int 3);
```

Correct:

```c
addNumbers(x, y);
```

Correct:

```c
addNumbers(5, 3);
```

---

## Universal rule

```text
Function definition = data type + parameter name

Function call = value or variable only
```

Example:

```c
int addNumbers(int a, int b)
```

This is the function definition.

```c
addNumbers(5, 3)
```

This is the function call.

---

## How C matches arguments to parameters

C matches arguments by order.

Function definition:

```c
int addNumbers(int a, int b)
```

Function call:

```c
addNumbers(5, 3);
```

C matches them like this:

```text
a = 5
b = 3
```

Another example:

```c
addNumbers(10, 4);
```

C matches them like this:

```text
a = 10
b = 4
```

The order matters.

---

## Number of arguments must match

If the function expects two values:

```c
int addNumbers(int a, int b)
```

Then the function call must give two values.

Correct:

```c
addNumbers(5, 3);
```

Wrong:

```c
addNumbers(5);
```

Wrong:

```c
addNumbers(5, 3, 2);
```

---

## Types should match

If the function expects integers:

```c
int addNumbers(int a, int b)
```

Then pass integers:

```c
addNumbers(5, 3);
```

If the function expects a double and an int:

```c
double calculateAverage(double total, int count)
```

Then call it with a double and an int:

```c
calculateAverage(240.0, 3);
```

---

## Full example

```c
#include <stdio.h>

int addNumbers(int a, int b) {
    return a + b;
}

int main() {
    int x = 5;
    int y = 3;
    int result;

    result = addNumbers(x, y);

    printf("%d\n", result);

    return 0;
}
```

In this line:

```c
int addNumbers(int a, int b)
```

`a` and `b` are parameters.

In this line:

```c
addNumbers(x, y)
```

`x` and `y` are arguments.

C copies the values:

```text
a = x = 5
b = y = 3
```

Then the function returns:

```text
8
```

So this line:

```c
result = addNumbers(x, y);
```

becomes like:

```c
result = 8;
```

---

## Easy memory rule

```text
Parameter = variable in the function definition

Argument = real value or variable passed during the function call
```

Example:

```c
int addNumbers(int a, int b)
```

`a` and `b` are parameters.

```c
addNumbers(5, 3)
```

`5` and `3` are arguments.

```c
addNumbers(x, y)
```

`x` and `y` are arguments.

---

## Super simple rule

```text
When creating the function:
write type + name

When calling the function:
write value only
```

Example:

```c
int addNumbers(int a, int b)   // create function
```

```c
addNumbers(5, 3);              // call function
```


*/