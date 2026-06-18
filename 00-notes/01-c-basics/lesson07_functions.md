# Lesson 07 - Functions

Day 07 is about functions.

A function is a reusable block of code.

Instead of writing the same code again and again, we can put that code inside a function and call it when we need it.

# Day 07 - Functions in C

## Big Picture

A function is a reusable block of code.

Instead of writing the same code again and again, we can put that code inside a function and call it whenever we need it.

Functions help us:

```text
organize code
reuse code
make main() cleaner
separate jobs
make programs easier to read
```

---

## Function idea

A function can do one job.

Example jobs:

```text
print a message
add numbers
calculate an average
print a grade
check pass or fail
```

Each function should have a clear purpose.

---

## Basic function format

```c
returnType functionName(parameters) {
    // code
}
```

Example:

```c
void sayHello() {
    printf("Hello\n");
}
```

---

## Function parts

```text
return type = what the function sends back

function name = the name we use to call the function

parameters = values the function receives

function body = code inside { }

return = sends a value back
```

---

## Function call

Creating a function does not run it automatically.

To run a function, we must call it.

Example:

```c
sayHello();
```

---

## Three main types we learn in Day 07

```text
07A - basic function
A function with no parameter and no return value.

07B - function with parameters
A function that receives values.

07C - function with return value
A function that sends an answer back.

07D - function prototypes
A preview that tells C the function exists later.

07E - variable scope
Where variables can and cannot be used.

07F - cumulative function review
Using functions with old lessons together.
```

---

## Memory rule

```text
void = function does not return a value

parameters = input going into the function

return value = output coming back from the function

function call = using the function
```

Functions are like small machines:

```text
input -> function does work -> output
```

----------------------------------------------------------------------------------------
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

## Lesson 07D - Function Prototypes

A function prototype is a preview of a function.

It tells C:

```text
This function exists later in the file.
Here is the return type.
Here is the function name.
Here are the parameters.
```

---

## Why do we need prototypes?

C reads code from top to bottom.

If `main()` calls a function before C has seen that function, C can get confused.

Example without prototype:

```c
#include <stdio.h>

int main() {
    int result = addNumbers(5, 3);
    printf("Result: %d\n", result);

    return 0;
}

int addNumbers(int a, int b) {
    return a + b;
}
```

Problem:

```text
main uses addNumbers before C has seen addNumbers.
```

A prototype fixes this.

---

## Prototype example

```c
#include <stdio.h>

int addNumbers(int a, int b);

int main() {
    int result = addNumbers(5, 3);
    printf("Result: %d\n", result);

    return 0;
}

int addNumbers(int a, int b) {
    return a + b;
}
```

This line is the prototype:

```c
int addNumbers(int a, int b);
```

It tells C:

```text
There will be a function named addNumbers later.
It returns an int.
It needs two int parameters.
```

---

## Prototype vs full function

Prototype:

```c
int addNumbers(int a, int b);
```

Full function:

```c
int addNumbers(int a, int b) {
    return a + b;
}
```

Main difference:

```text
Prototype ends with semicolon ;

Full function has body { }
```

---

## Universal rule

```text
Prototype = function preview

Function definition = real function code
```

Prototype:

```c
double calculateAverage(int total);
```

Function definition:

```c
double calculateAverage(int total) {
    return total / 3.0;
}
```

---

## Important rules

The prototype must match the real function.

These must match:

```text
return type
function name
parameter types
parameter order
```

Correct:

```c
int addNumbers(int a, int b);

int addNumbers(int a, int b) {
    return a + b;
}
```

Wrong:

```c
int addNumbers(int a, int b);

double addNumbers(int a, int b) {
    return a + b;
}
```

Wrong because prototype says `int`, but function returns `double`.

---

## Parameter names in prototypes

Parameter names are allowed but not required.

Both are okay:

```c
int addNumbers(int a, int b);
```

```c
int addNumbers(int, int);
```

For learning, use parameter names because it is easier to read.

---

## When should we use prototypes?

Use prototypes when you want this structure:

```text
#include
prototypes
main
function definitions
```

Example:

```c
#include <stdio.h>

int addNumbers(int a, int b);
double calculateAverage(int total);
void printMessage();

int main() {
    printMessage();

    int total = addNumbers(80, 90);
    double average = calculateAverage(total);

    printf("Total: %d\n", total);
    printf("Average: %.2f\n", average);

    return 0;
}

int addNumbers(int a, int b) {
    return a + b;
}

double calculateAverage(int total) {
    return total / 2.0;
}

void printMessage() {
    printf("--- Function Prototype Lesson ---\n");
}
```

---

## Memory rule

```text
Prototype tells C the function exists.

Prototype has semicolon.

Full function has braces.

Prototype goes before main.

Real function code can go after main.
```
---

## Lesson 07E - Variable Scope

Scope means where a variable can be used.

A variable does not work everywhere in the program.

Where you create the variable decides where you can use it.

---

## 1. Variable inside main

```c
int main() {
    int age = 20;

    printf("%d\n", age);

    return 0;
}
```

`age` was created inside `main`.

So `age` can only be used inside `main`.

---

## 2. Variable inside a function

```c
void printNumber() {
    int number = 10;
    printf("%d\n", number);
}
```

`number` was created inside `printNumber`.

So `number` can only be used inside `printNumber`.

You cannot use `number` inside `main`.

---

## 3. Parameters are local variables

```c
int add(int a, int b) {
    return a + b;
}
```

`a` and `b` are parameters.

They only exist inside the `add` function.

They do not exist inside `main`.

---

## 4. Same variable name can exist in different functions

```c
void functionOne() {
    int x = 10;
}

void functionTwo() {
    int x = 20;
}
```

These are not the same `x`.

Each function has its own variable.

---

## 5. Block scope

A block is code inside `{ }`.

```c
if (1) {
    int score = 90;
    printf("%d\n", score);
}
```

`score` only exists inside the `if` block.

Outside the block, `score` does not exist.

---

## Common mistake

Wrong:

```c
void calculate() {
    int total = 100;
}

int main() {
    printf("%d\n", total);
    return 0;
}
```

This is wrong because `total` was created inside `calculate`.

`main` cannot see it.

Correct:

```c
int calculate() {
    int total = 100;
    return total;
}

int main() {
    int result = calculate();
    printf("%d\n", result);

    return 0;
}
```

The function returns the value, then `main` stores it.

---

## Memory rule

```text
Variable created inside a function = only works inside that function

Parameter = only works inside that function

Variable created inside { } = only works inside that block

If main needs a value from another function, use return
```
---

## Lesson 07F - Cumulative Functions Review

This lesson combines everything from Day 07.

By now, you have learned:

```text
basic function
function parameter
return value
function prototype
variable scope
void function
```

---

## Big picture

A good C program should not put everything inside `main`.

Instead, `main` should control the program, and functions should do smaller jobs.

Good structure:

```text
prototypes
main
function definitions
```

---

## Example structure

```c
#include <stdio.h>

double calculateSubtotal(double price, int quantity);
double calculateTax(double subtotal, double taxRate);
double calculateFinalTotal(double subtotal, double tax);
void printReceipt(double subtotal, double tax, double finalTotal);

int main() {
    double price;
    int quantity;
    double taxRate;

    double subtotal;
    double tax;
    double finalTotal;

    // input
    // function calls
    // output

    return 0;
}

// function definitions
```

---

## Function jobs

Each function should have one clear job.

Example:

```text
calculateSubtotal = calculate price before tax

calculateTax = calculate tax amount

calculateFinalTotal = calculate subtotal + tax

printReceipt = print the result
```

---

## Return value function

A return value function gives an answer back.

Example:

```c
double calculateSubtotal(double price, int quantity) {
    return price * quantity;
}
```

Call it in `main`:

```c
subtotal = calculateSubtotal(price, quantity);
```

Meaning:

```text
send price and quantity into function
function calculates subtotal
function returns answer
main stores answer in subtotal
```

---

## Void function

A `void` function does not return a value.

It usually prints something or performs an action.

Example:

```c
void printReceipt(double subtotal, double tax, double finalTotal) {
    printf("Subtotal: %.2f\n", subtotal);
    printf("Tax: %.2f\n", tax);
    printf("Final total: %.2f\n", finalTotal);
}
```

Call it in `main`:

```c
printReceipt(subtotal, tax, finalTotal);
```

---

## Scope reminder

Variables inside one function do not belong to another function.

Example:

```c
double calculateTax(double subtotal, double taxRate) {
    double tax = subtotal * taxRate;
    return tax;
}
```

The variable `tax` inside this function only exists inside this function.

If `main` needs the answer, use `return`.

---

## Prototype reminder

Prototype goes before `main`.

Example:

```c
double calculateTax(double subtotal, double taxRate);
```

Real function definition goes after `main`.

Example:

```c
double calculateTax(double subtotal, double taxRate) {
    return subtotal * taxRate;
}
```

Prototype must match the real function:

```text
same return type
same function name
same parameter types
same parameter order
```

---

## Memory rule

```text
main controls the program

return value functions calculate and send answers back

void functions do actions but do not return values

parameters receive values

arguments are values sent into the function

scope decides where variables can be used

prototypes tell C the function exists later
```
---