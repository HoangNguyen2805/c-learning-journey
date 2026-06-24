# Mini Quiz - 3.5 Loops: While and For

1. What does a loop do?
- A loop repeats code while a condition is true.
2. What are the three common parts of a loop?
- start / initialization
- condition
- update
3. What does a `while` loop check?
- It checks a condition.
4. Does a `while` loop check the condition before or after running the body?
- Before
5. What happens if a loop condition never becomes false?
- Infinite loop
6. What is an infinite loop?
- A loop that never stops because the condition never becomes false.
7. Why is this dangerous?

```c
int i = 1;

while (i <= 5) {
    printf("%d\n", i);
}
```
- Because i never changes, so i <= 5 stays true forever.
8. What is the missing part in the loop above?
- The update:
```c
i++;
```
9. What is the general format of a `for` loop?
```c
for (start; condition; update)
{
    statements;
}
```
10. In a `for` loop, what goes in the first part?
- Initialization / starting value.

Example:
```c
i = 1;
```
11. In a `for` loop, what goes in the second part?
- Condition.
```c
i <= 5
```
12. In a `for` loop, what goes in the third part?
- Update,
```c
i++
```
13. When is `for` usually better than `while`?
- When you know the start, end, and update clearly, like counting from 1 to 10.
14. When is `while` usually better than `for`?
- When you do not know exactly how many times the loop will run.
- Example: repeat while input is invalid.
15. Can a `while` loop and a `for` loop do the same job?
- Yes.
16. What does this mean?

```c
for (;;) {
    printf("Hello\n");
}
```
- It is an infinite loop.
17. What does the comma operator allow inside a `for` loop?
- It allows more than one expression in one part of the for loop.
- Example:
```c
for (i = 0, j = 10; i < j; i++, j--)
```
18. What happens here after each loop?

```c
i++, j--
```
- i increases by 1, and j decreases by 1.
19. Why does K&R use comma operators with loops?
- To update more than one variable in the same for loop.
20. What is the main thing to remember from K&R 3.5?
- Loops repeat code. while checks a condition before running, and for is useful when start, condition, and update belong together.

- Your answered ones are mostly right. Main spelling/wording fix:
```c
meet → met
meat → met
```
Better:
```c
repeat intul the condition is not met anymore.
```