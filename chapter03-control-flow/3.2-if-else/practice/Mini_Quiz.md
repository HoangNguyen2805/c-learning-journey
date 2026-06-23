# Mini Quiz - 3.2 If-Else

1. What does an `if` statement do?
- It checks a condition and runs a statement/block only if the condition is true.
2. What does `else` do?
- else runs when the if condition is false.
3. In C, what value means false?
- 0
4. In C, what kind of value means true?
- 1 or non-zero.
5. What happens if an `if` condition is true?
- The statement or block under the if runs.
6. What happens if an `if` condition is false and there is no `else`?
- Nothing runs for that if.
7. What happens if an `if` condition is false and there is an `else`?
- The statement or block under else runs.
8. What symbols are used to create a block?
= { }
9. Why are braces useful with `if` statements?
- They group multiple statements together so they all belong to the if or else.
10. Without braces, how many statements belong to an `if`?
- Only one statement.
11. What is a nested `if`?
- An if statement inside another if statement.
12. What is the dangling else problem?
- It happens when it is unclear which if an else belongs to.
13. Which `if` does an `else` match?
- The nearest unmatched if.
14. Why is this wrong?

```c
if (score >= 70);
    printf("Pass\n");
```
- The semicolon ends the if early, so printf runs no matter what.
15. What is the safer beginner rule for writing nested `if` statements?
- Always use braces { } so it is clear which statements belong to each if or else.