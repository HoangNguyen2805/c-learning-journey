# Mini Quiz - 2.5 Arithmetic Operators

1. What does an arithmetic operator do in C?
- It performs math operations like addition, subtraction, multiplication, division, and remainder.
2. What operator is used for addition?
- +
3. What operator is used for subtraction?
- -
4. What operator is used for multiplication?
- *
5. What operator is used for division?
- /
6. What operator is used for remainder?
- %
7. What is the result of this?

```c
10 + 3
```
- 13
8. What is the result of this?

```c
10 - 3
```
- 7
9. What is the result of this?

```c
10 * 3
```
- 30
10. What is the result of this?

```c
10 / 3
```
- 3 not 3.3333
11. Why is `10 / 3` not `3.333`?
- Because both number is a interger, change it to 10.0 / 3 or 10 / 3.0
Fix: Because both numbers are integers, so C does integer division. To get a decimal answer, use 10.0 / 3 or 10 / 3.0.
12. What is the result of this?

```c
10 % 3
```
- 1
13. What does `%` mean?
- Modulo - mean extra number during division. % is the remainder operator. It gives the leftover amount after integer division.
14. Can `%` be used with `float` or `double`?
- No
15. What is wrong with this?

```c
double result = 10.5 % 3.2;
```
- % only works with integers. It does not work with float or double.
16. What is wrong with this?

```c
int result = 10 / 0;
```
- You can NOT devided by 0. Division by zero is not allowed.
17. What is wrong with this?

```c
int result = 10 % 0;
```
- You can NOT devided by 0. Remainder by zero is not allowed.
18. What happens first in this expression?

```c
10 + 2 * 5
```
- 2 * 5 happens first because multiplication has higher precedence than addition.
19. What is the result of this?

```c
10 + 2 * 5
```
- 20
20. Why should negative numbers with `%` be used carefully when following K&R?
- Because older C rules were less consistent about the sign of the remainder with negative numbers. It is safer to avoid relying on % with negative numbers unless you know your compiler’s rule.