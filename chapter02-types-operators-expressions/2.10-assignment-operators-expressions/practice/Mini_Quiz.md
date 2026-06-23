# Mini Quiz - 2.10 Assignment Operators and Expressions

1. What does the assignment operator `=` do?
- Assign the variable with value.
2. What must be on the left side of an assignment?
- A variable , or something to hold the value
3. Why is this wrong?

```c
10 = x;
```
- 
4. What does this do?

```c
x = 10;
```
- Assign 10 to x , mean 2 is worth the value of 10.
5. In C, does an assignment expression have a value?

6. What happens here?

```c
y = (x = 5);
```
- x = 5 and y = the value of x so y also = 5.
7. After this code, what is `x`?

```c
y = (x = 5);
```
- x = 5
8. After this code, what is `y`?

```c
y = (x = 5);
```
- y = 5
9. What does this mean?

```c
a = b = c = 0;
```
- a , b and c all equal to 0
10. Does chained assignment happen left to right or right to left?
- Assignment happens right to left.
11. What does `+=` mean?

12. What does `-=` mean?

13. What does `*=` mean?

14. What does `/=` mean?

15. What does `%=` mean?

16. What does this mean?

```c
x += 5;
```

17. What does this mean?

```c
x *= 3;
```

18. What does this mean?

```c
x *= y + 1;
```

19. Is `x *= y + 1` the same as `x = x * (y + 1)`?

20. Is `x *= y + 1` the same as `x = x * y + 1`?

21. What does `&=` mean?

22. What does `|=` mean?

23. What does `^=` mean?

24. What does `<<=` mean?

25. What does `>>=` mean?

26. Why are compound assignment operators useful?

27. What is the main idea of K&R 2.10?
