# Mini-Quiz 5.10 - Command-line Arguments

Answer in your own words / code. No compiler until you've committed to answers.

1. For the command `./sort -r data.txt`, what are the values of `argc`, `argv[0]`, `argv[1]`, `argv[2]`, and `argv[3]`?

2. Why is `argv` declared as `char *argv[]` and not `char argv[]`? What is the actual type of `argv[1]`?

3. What is guaranteed to be stored at `argv[argc]`? How can this let you loop over arguments without using `argc` at all?

4. A user runs `./add 5 7` and the program does `printf("%d", argv[1] + argv[2]);`. What is wrong, and what should the code do instead?

5. Explain the difference between `(*++argv)[0]` and `*++argv[0]`. Which one moves to the next argument, and which one moves within the current argument?

6. Why does the K&R pointer-style echo loop `while (--argc > 0) printf("%s", *++argv);` naturally skip the program name?

7. Write the guard code a program should run before touching `argv[1]`, including a helpful "usage" message.

8. Is it safe to modify `argc` and `argv` inside `main` (e.g., `argc--`, `argv++`)? Why or why not?

9. `char **argv` and `char *argv[]` in a parameter list: same or different? Explain using what you learned in 5.3.

10. (Code reading) What does this print when run as `./prog -abc`?
```c
char c;
while ((c = *++argv[0]))
    putchar(c), putchar('\n');
```
