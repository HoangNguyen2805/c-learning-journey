# Mini Quiz - 4.2 Functions Returning Non-integers

1. Can a function return something other than `int`?
- Yes , double , float , char , ...
2. Where is the return type written in a function definition?
- Before the function name.
3. What does this function return?

```c id="n7a7lt"
double average(double a, double b);
```
- double
4. What does this function return?

```c id="sgy1yi"
char getGrade(int score);
```
- char
5. What does this function return?

```c id="c2t28t"
void printMessage(void);
```
- nothing
6. Why is a prototype important for a function returning `double`?
- Because the compiler needs to know the function returns a double before the function is called.

Without the correct prototype, C may treat the return value incorrectly and you can lose decimal information or get wrong results.
7. Should the prototype return type match the function definition return type?
- Yes
8. What can happen if a function returns `int` but the calculation produces a decimal?
- The decimal part is lost.
9. What does `return` do?
- return sends a value back to the function caller and ends the function.
10. Can the value after `return` be converted to the function return type?
- Yes
11. What does K&R's `atof` example convert?
- atof converts a string of characters into a floating-point number.
Example idea:
```c
"123.45" → 123.45
```
12. What type does `atof` return?
- double
13. What does this prototype mean?

```c id="pob2td"
double atof(char s[]);
```
- It means:
There is a function named atof.
It takes a character array/string as input.
It returns a double.
14. Why should beginners always write prototypes before `main`?
- So the compiler knows the function’s name, return type, and parameter types before main calls it.
A prototype tells the compiler what the function looks like before the full definition appears later.
Not exactly “remind main.” It tells the compiler, not main.
15. What is the main thing to remember from K&R 4.2?
- Functions do not have to return only int.
The return type matters. If a function should return a decimal, use double or float, and make sure the prototype, definition, and returned value all match.
Main memory:
```bash
Function return type controls what kind of value comes back.
Prototype must match the function definition.
```