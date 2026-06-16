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
