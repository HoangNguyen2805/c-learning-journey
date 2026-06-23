# Mini Quiz - 2.7 Type Conversions

1. What does type conversion mean?
- Changing data type from one kind to another kind
2. Can C convert types automatically?
- Yes
3. What is the result of this?

```c
10 / 3
```
- 3
4. Why does `10 / 3` not give `3.333`?
- Because both values are integers, so C does integer division.
5. How can you make division give a decimal result?
- Make at least one value a floating-point value, like 10.0 / 3 or 10 / 3.0.
6. What is a cast?
- A cast temporarily converts a value to another type.
7. What does this mean?

```c
(double) a
```
- It temporarily treats the value of a as a double.
8. What is the result type when an `int` and a `double` are used together?
- double
9. What happens in this expression?

```c
10 + 3.5
```
- 13.5 , 10 is converted to double, and the result is 13.5.
10. Are characters stored using integer codes?
Yes
11. What does this do?

```c
'7' - '0'
```
- It converts the character digit '7' into the integer value 7.
12. What is the result of this?

```c
'7' - '0'
```
- 7
13. Why can a `char` be printed with `%d`?
- Because a char is stored as an integer character code.
14. What is assignment conversion?
- When C converts a value to match the type of the variable it is being assigned to.
15. What happens here?

```c
double price = 9.99;
int dollars = price;
```
- The double value 9.99 is converted to int.
16. What value does `dollars` get?
- 9
17. What information is lost when converting `double` to `int`?
- Decimnal and all the digits after the decimal.
18. Why can converting from a larger type to a smaller type be dangerous?
- Losing or filter out information. Turn it into miss information.The smaller type may not be able to hold all the information, so data can be lost or changed.
19. Which is safer: converting `int` to `double`, or converting `double` to `int`?
- converting `int` to `double`
20. What is the main thing to remember from K&R 2.7?
-  C can convert types automatically, but you must be careful because some conversions can lose information.