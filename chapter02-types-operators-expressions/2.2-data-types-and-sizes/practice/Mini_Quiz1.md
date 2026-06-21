# Mini Quiz - 2.2 Data Types and Sizes

1. What does a data type tell C?
- It tell c what kind of value does the variable hold.
2. What type stores one character?
- char
3. What type stores text/string in C?
- char []
4. What placeholder prints one character?
- %c
5. What placeholder prints a string?
- %s
6. What type stores whole numbers?
- int , short , long , signed, unsigned are modifiers for integer types
7. What type stores decimal numbers?
- float , double
8. Which one is more precise: `float` or `double`?
- double
9. What does `short` mean?
- -32767 to 32767
Fix: short means a smaller integer type. Usually -32768 to 32767.
10. What does `long` mean?
- -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
Fix: long means a larger integer type. On my WSL/Linux system it is usually -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807.
11. What does `signed` mean?
- variable can store negative , zero , positive whole number
12. What does `unsigned` mean?
- variable can NOT store negative whole number
13. If a type has `n` bits, how many values can it represent?
- So the rule is: n bits = 2^n possible values , If a type has n bits, it can represent 2^n different values.
14. If `char` is 8 bits, how many values can it represent?
- 8 bits = 2^8 = 256 values
15. What is the range of an 8-bit `unsigned char`?
- 0 to 255
16. What is the range of an 8-bit `signed char`?
- -128 to 127
17. What happens when unsigned arithmetic goes past the maximum value?
- the value become 0
Fix: It wraps around modulo 2^n. If it is at the maximum value and you add 1, it becomes 0.
18. What does `sizeof(type)` show?
- It show how many bits per the data type.
Fix: It shows how many bytes a data type uses.
19. What placeholder should be used to print a `sizeof` result?
- %zu
20. Which header gives integer limits?
- <limits.h>
21. Which header gives floating-point limits?
- <float.h>
22. What does `CHAR_BIT` tell us?
- Number of bits in one char. Usually 8.
23. What does `INT_MAX` tell us?
- Largest value for int. Usually 2147483647.
24. What does `FLT_MAX` tell us?
- Largest positive float value. Around 3.402823e+38.
25. What header allows `bool`, `true`, and `false`?
- <stdbool.h>
26. What does `true` print as in C?
- non-zero
Fix: true usually prints as 1.
27. What does `false` print as in C?
- zero 0
Fix: false prints as 0.