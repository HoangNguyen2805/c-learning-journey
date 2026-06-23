# Mini Quiz - 2.8 Increment and Decrement Operators

1. What does `++` do?
- Increase the value of the variable by 1.
2. What does `--` do?
- Decrease the value of the variable by 1.
3. What does this mean?

```c
x++;
```
- It means use x, then increase x by 1.
4. What does this mean?

```c
x--;
```
- It means use x, then decrease x by 1.
5. What is the difference between `x++` and `++x`?
- x++ mean use old variable first then increase that old variable by 1.
- ++x mean increase the variable by 1 first then use the new variable.
6. What does post-increment mean?
- use old variable first then increase that old variable by 1.
7. What does pre-increment mean?
- increase the variable by 1 first then use the new variable.
8. What is the result?

```c
int x = 5;
int y = x++;
```
- x will increase to 6 , but y will equal to 5.
9. After the code above, what is `x`?
- x = 6
10. After the code above, what is `y`?
- y = 5
11. What is the result?

```c
int x = 5;
int y = ++x;
```
- x will increase to 6 and y is also = 6
12. After the code above, what is `x`?
- x = 6
13. After the code above, what is `y`?
- y = 6
14. What does post-decrement mean?
- use old variable first then decrease that old variable by 1.
15. What does pre-decrement mean?
- decrease the variable by 1 first then use the new variable.
16. What is the result?

```c
int x = 5;
int y = x--;
```
- x = 4
  y = 5
17. What is the result?

```c
int x = 5;
int y = --x;
```
- x = 4 
  y = 4
18. Can you write this?

```c
5++;
```
- No
19. Why is `5++` wrong?
- ++ and -- only work on variables, not fixed constants like 5.
20. Why should beginners avoid complicated expressions with multiple `++` operators?
- They are hard to read and can lead to confusing or unsafe code.