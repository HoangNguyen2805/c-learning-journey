# Mini Quiz - 4.1 Basics of Functions

1. What is a function?
- A function is a named block of code that performs a specific task. It runs only when it is called.
2. What is a function definition?
- A function definition is the full function code, including the return type, name, parameters, and body.
Example:
```c
int add(int a, int b)
{
    return a + b;
}
```
3. What is a function call?
- A function call tells C to run the function.
Example:
```c
result = add(2, 3);
```
4. What is a parameter?
- A parameter is a variable listed in the function definition.
Example:
```c
int add(int a, int b)
```
5. What is an argument?
- An argument is the actual value sent into the function call.
Example:
```c
add(2, 3);
```
6. What does `return` do?
- return sends a value back to the caller and ends the function.
7. What does the return type tell C?
- It tells C what type of value the function gives back.
Example:
```c
int add(int a, int b)
```
This function returns an int.
8. What does `void` mean before a function name?
- It means the function does not return a value.
9. What does `void` mean inside the parentheses?
- It means the function takes no parameters.
Example:
```c
int getNumber(void)
```
means getNumber takes no input.
10. What is a function prototype?
- A function prototype tells the compiler that a function exists before the full function definition appears.
Example:
```c
int add(int a, int b);
```
11. Why do we put prototypes before `main`?
- Because if main calls a function before C has seen its definition, the compiler needs the prototype to know the function exists.
12. Can functions be written after `main` if there is a prototype?
- Yes
13. Can C functions be defined inside other functions?
- No
14. What is wrong with defining a function inside `main`?
C does not allow normal functions to be defined inside another function. Functions must be separate.
Wrong:
```c
int main()
{
    int add(int a, int b)
    {
        return a + b;
    }
}
```
Correct:
```c
int main()
{
    return 0;
}

int add(int a, int b)
{
    return a + b;
}
```
15. What does call by value mean?
- Call by value means the function receives a copy of the argument, not the original variable.
16. If a function changes its parameter, does the original variable in `main` change?
- No. The original variable in main does not change because the function only changed its copy.
17. What does this prototype mean?

```c
int square(int x);
```
- It means there is a function named square that takes one int parameter and returns an int.
18. What does this function return?

```c
int add(int a, int b) {
    return a + b;
}
```
- It returns the sum of a and b.
19. Why are functions useful?
- Functions are useful because they let you split a program into smaller reusable parts. They reduce repeated code and make programs easier to read, test, and fix.
20. What is the main thing to remember from K&R 4.1?
- The main thing is that functions let you organize code into separate named pieces. A function can take parameters, use arguments, return a value, and be declared with a prototype before main.

Big thing to remember from your calculator mistake:
```c
Normal parameters are copies.
Changing a parameter inside a function does not change the original variable in main.
```
Your most important correction:
```c
parameter = variable in function definition
argument = value sent during function call
```