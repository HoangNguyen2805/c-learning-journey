# Lesson 07 - Functions

Day 07 is about functions.

A function is a reusable block of code.

Instead of writing the same code again and again, we can put that code inside a function and call it when we need it.

## Lesson 07A - Basic Function With No Input and No Return

This lesson is only the introduction to functions.

This type of function:

```c
void sayHello() {
    printf("Hello from a function!\n");
}
```

has:

```text
no input
no return value
only runs code
```

## Function Structure

```c
void sayHello() {
    printf("Hello from a function!\n");
}
```

Breakdown:

```text
void
```

means the function does not return/send back a value.

```text
sayHello
```

is the function name.

You choose the function name.

Good function names should explain what the function does.

Examples:

```text
sayHello
printWelcome
printGoodbye
showMenu
```

```text
()
```

means this function takes no input.

Later we will put variables inside the parentheses.

Example later:

```c
void printNumber(int number)
```

```text
{
    code here
}
```

is the function body.

The code inside the braces runs when the function is called.

## Creating a Function vs Calling a Function

This creates the function:

```c
void sayHello() {
    printf("Hello from a function!\n");
}
```

But creating a function does not run it.

This calls/runs the function:

```c
sayHello();
```

## Program Flow

Example:

```c
#include <stdio.h>

void sayHello() {
    printf("Hello from a function!\n");
}

int main() {
    printf("--- Basic Function ---\n");

    sayHello();

    printf("Program finished.\n");

    return 0;
}
```

The program starts in `main()`.

Step by step:

```text
1. main starts
2. prints --- Basic Function ---
3. sees sayHello();
4. jumps to the sayHello function
5. runs the code inside sayHello
6. comes back to main
7. prints Program finished.
8. return 0 ends the program
```

## Important Rules

A function must be called if you want it to run.

Correct:

```c
sayHello();
```

Wrong:

```c
sayHello;
```

Function calls need parentheses and semicolon.

```text
functionName();
```

## Memory Rules

```text
void = function does not return a value
function name = what the function is called
() = no input for now
{} = function body
functionName(); = call/run the function
```

## Day 07 Later Lessons

```text
07A - Basic function with no input and no return
07B - Function with parameters/input
07C - Function that returns a value
07D - Function prototype
07E - LeetCode-style functions
```
-------------------------------------------------------------

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
-------------------------------------------------------------

## Lesson 07C - Function That Returns a Value

A void function does not send back an answer.

Example:
```c
void checkAge(int age)
```
But an int function returns an int answer.

Example:
```c
int addNumbers(int a, int b) {
    int sum = a + b;
    return sum;
}
```
Breakdown:
```bash
int = return type
addNumbers = function name
int a, int b = parameters/input
return sum; = send sum back to main
```
When we call:
```c
result = addNumbers(5, 3);
```
This means:
```bash
1. send 5 into a
2. send 3 into b
3. addNumbers calculates 5 + 3
4. return sum sends 8 back
5. result stores 8
```
Memory rule:
```bash
void function = does not return an answer
int function = returns an int answer
return = send value back
```
-------------------------------------------------------------

