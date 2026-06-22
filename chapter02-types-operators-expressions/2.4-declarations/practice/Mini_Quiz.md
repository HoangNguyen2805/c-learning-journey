# Mini Quiz - 2.4 Declarations

1. What does a declaration tell C?
- It tell C what function this variable belong to , what type of value this variable hold.
Fix: It tells C the variable’s name and what type of value it can hold.
2. What is the difference between declaration and assignment?
- Declaration is telling C that this variable exist somewhere.
- Assignment is telling C what is the value of this variable.
Fix: Declaration creates or announces a variable. Assignment gives a value to an existing variable.
3. What is initialization?
Give the value to the variable
4. What does this do?

```c
int age;
```
It declare that age is variable that hold integer.
5. What does this do?

```c
int age = 25;
```
- It declares an integer variable named age and initializes it with 25.
6. What does this do?

```c
age = 30;
```
- It assigns the value 30 to the existing variable age.
7. Can multiple variables of the same type be declared in one line?
Yes
8. What does this mean?

```c
int lower, upper, step;
```
All 3 variable which is lower, upper and step is integer
9. Should a variable be declared before it is used?
Yes
10. What is wrong with using a local variable before giving it a value?
- It may contain an unknown garbage value.
11. What kind of value can an uninitialized local variable contain?
- An unknown garbage value.
12. What happens to external or static variables if no value is given?
- It still can be assign value later on.
Fix: They are automatically initialized to 0.
13. What does `const` mean?
- const mean fixed value of variable
Fix: const means the variable cannot be changed after it is initialized.
14. Is `const` a data type?
No
15. What is `const` called?
- contant
Fix: const is a qualifier.
16. In this declaration, what is the data type?

```c
const int MAX_SCORE = 100;
```
- integer
17. In this declaration, what is the qualifier?

```c
const int MAX_SCORE = 100;
```
- Yes, it have data type, variable and assigned value to be qualify as a declaration.
Fix: The qualifier is const.
18. Why should a `const` variable usually be initialized when declared?
- Because it need to have a value first before it can become fixed value.
Fix: Because after it is created, its value cannot be changed.
19. Is this correct?

```c
const int MAX_SCORE;
MAX_SCORE = 100;
```
- No, no value assign when declare it constant and after that yopu can't change it value by assign it to a different value.
Fix: No, No. A const variable should be initialized when it is declared
20. Why are declarations important in C?
- It help C know that what kind of variable and what value that the variable hold