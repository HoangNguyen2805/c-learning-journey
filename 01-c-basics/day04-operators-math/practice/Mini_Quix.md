# Day 04 Mini Quiz - Operators and Math

Answer without looking at notes first.

## Questions

1. What does an operator do in C?

Answer: IT's help to do math and other calculation like compare , equal, bigger or smaller.

2. What are the 5 basic arithmetic operators we learned?

Answer: Addition + , Subtraction - , Multiplication * , Division / , MoD % remainder

3. What does `/` do?

Answer: Division

4. What does `%` do?

Answer: it give you the remainder of a not perfect division

5. What is the result of this?

```c
10 / 3
```

Answer: 3

6. Why is `10 / 3` not `3.33` in C?

Answer: because both value is integer data type

7. What is the result of this?

```c
10 % 3
```

Answer: 1

8. Why do we write `%%` inside `printf`?

Answer: cause a single % is represent , so inorder to displace % as part of the text we have to add another %.

9. What is wrong with this?

```c
double result = 10.5 % 3.2;
```

Answer: % % only work with integer not double and float

10. What is wrong with this?

```c
int result = 10 / 0;
```

Answer: You can't devided by 0, it's an error

11. What does this mean?

```c
x += 5;
```

Answer:x is increasing by 1 from 5
FIx: x = x + 5

12. What does this mean?

```c
x %= 4;
```

Answer:the remainder of x is 4
Fix: x = x % 4

13. What is the difference between `x++` and `++x` when used inside another expression?

Answer: x++ mean read x and increasing it by 1 and write x. While ++
Fix:
x++ means use the old value first, then add 1.
++x means add 1 first, then use the new value.

14. What are the final values?

```c
int a = 7;
int b = a++;
```

Answer: a = 7 and b = 8
Fix:
a = 8
b = 7   b get 7 then a become 8

15. What are the final values?

```c
int c = 7;
int d = ++c;
```

Answer: c = 8 and d is also = 8

16. What does precedence mean?

Answer: priorities of mathmatic operation is () then * and / the + and -

17. What happens first in this expression?

```c
10 + 2 * 5
```

Answer:*

18. What is the result?

```c
(10 + 2) * 5
```

Answer:60

19. What is the order of precedence we learned?

Answer:() then * and / the + and -


20. Why should we use parentheses sometimes?

Answer: to priorities what in the parentheses first.
