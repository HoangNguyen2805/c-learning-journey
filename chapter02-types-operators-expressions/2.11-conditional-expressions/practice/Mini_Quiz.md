# Mini Quiz - 2.11 Conditional Expressions

1. What does a conditional expression do?
- It checks a condition and chooses one of two values.
2. What operator is used for a conditional expression?
- ? :
3. What is the general format of a conditional expression?
- (condition) ? value_if_true : value_if_false
4. What part is checked first?
- The condition.
5. What happens if the condition is true?
- The left side of : will execute
6. What happens if the condition is false?
The right side of : will execute
7. In C, what value means false?
- 0
8. In C, what kind of value means true?
- 1 or non-zero
9. What does this do?

```c
max = (a > b) ? a : b;
```
- if a biger than b then max = a
- if a smaller than b then max = b
10. What does this do?

```c
min = (a < b) ? a : b;
```
- if a smaller than b then max = a
- if a biger than b then max = b
11. What is the result if `a = 10` and `b = 20`?

```c
max = (a > b) ? a : b;
```
- max gets 20.
12. What is the result if `a = 10` and `b = 20`?

```c
min = (a < b) ? a : b;
```
- min gets 10.
13. Can a conditional expression be used inside assignment?
- Yes
14. Can a conditional expression be used inside `printf`?
- Yes
15. What does this print if `score = 85`?

```c
printf("%s\n", score >= 70 ? "Pass" : "Fail");
```
- Pass
16. What does this print if `score = 50`?

```c
printf("%s\n", score >= 70 ? "Pass" : "Fail");
```
- Fail
17. Why should the two possible results usually be compatible types?
- Because the conditional expression must produce one final value, so both choices should be types C can safely work with.
18. Why are parentheses helpful in conditional expressions?
- Help priorities the order of operation. They make the condition clear and help avoid confusion with operator precedence.
19. Is this conditional expression the same as an if/else statement?

```c
max = (a > b) ? a : b;
```
- Yes. It is like a short if/else that chooses a value.
20. What is the main thing to remember from K&R 2.11?
- A conditional expression chooses between two values using condition ? true_value : false_value.