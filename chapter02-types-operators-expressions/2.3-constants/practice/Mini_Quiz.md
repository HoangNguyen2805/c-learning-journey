# Mini Quiz - 2.3 Constants

1. What is a constant in C?
- A fixed value that does not change while the program runs.
2. What is an integer constant?
- A whole-number constant.
3. What is a decimal constant?
- A base-10 whole-number constant using digits 0-9.
4. What prefix makes an integer constant octal?
- A leading 0.
5. What prefix makes an integer constant hexadecimal?
- 0x or 0X.
6. What suffix means long?
- L
7. What suffix means unsigned?
- U
8. What suffix means unsigned long?
- UL
9. Why is uppercase `L` better than lowercase `l`?
- Uppercase L is easier to read and does not look like the number 1.
10. What is a floating-point constant?
- A decimal-number constant, like 3.14, 1.5e3, or 10.0.
11. What does scientific notation mean in C?
- A number written using e or E to mean “times 10 to a power.”
12. What does `1.5e3` mean?
- 1.5 * 10^3, which is 1500.
13. What suffix can mark a floating constant as `float`?
- F or f
14. What suffix can mark a floating constant as `long double`?
- L or l
15. What is a character constant?
- One character written inside single quotes.
16. What quotes are used for a character constant?
- Single quotes: 'A'
17. What is a string constant?
- Text written inside double quotes, ending automatically with '\0'.
18. What quotes are used for a string constant?
- Double quotes: "Hello"
19. What is the difference between `'A'` and `"A"`?
- 'A' is one character. "A" is a string with A and '\0'.
20. What is an escape sequence?
- A special character written with a backslash, like \n or \t.
21. What does `\n` mean?
- Newline
22. What does `\t` mean?
- Horizontal tab.
23. What does `\v` mean?
- Vertical tab.
24. What does `\b` mean?
- Backspace.
25. What does `\r` mean?
- Carriage return.
26. What does `\f` mean?
- Form feed.
27. What does `\a` mean?
- Alert / bell.
28. What does `\\` mean?
- Backslash character.
29. What does `\"` mean?
- Double quote character.
30. What does `\'` mean?
- Single quote character.
31. What does an octal escape sequence look like?
- \ooo, where ooo are octal digits.
32. What does a hexadecimal escape sequence look like?
- \xhh, where hh are hexadecimal digits.
33. What does `#define` do?
- It creates a symbolic name that the preprocessor replaces before compiling.
34. Does `#define` use `=`?
- No.
35. Does `#define` use a semicolon?
- No.
36. What is a symbolic constant?
- A fixed value represented by a name, usually created with #define.
37. What is an enum constant?
- A named integer value inside an enum.
38. What value does the first enum name usually get by default?
- 0
39. How can you manually set the first enum value?
- Use =, like LOW = 1.
40. Is `const` a data type?
- No.
41. What is `const`?
- A qualifier that makes a variable read-only after initialization.
42. Why does K&R 2.3 focus more on constant values than `const` variables?
- Because 2.3 is about literal constant values like integers, characters, strings, and enums. const is more about declarations.