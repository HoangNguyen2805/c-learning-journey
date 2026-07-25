# Mini-Quiz 8.3 - Open, Creat, Close, Unlink

1. What are the three classic open flags, and which header defines them?

2. open and fopen both fail differently: what does each return on failure, and why the difference in type?

3. What TWO different things can creat do depending on whether the file exists? Which one destroys data?

4. Decode perms 0666 and 0644: who can do what? Why is octal the natural notation here (6.9 connection)?

5. In the book's cp, explain the check `if (write(f2, buf, n) != n)` — what failure does it catch that a missing check would silently corrupt?

6. cp uses error("cp: can't open %s", argv[1]). Trace how the variadic error() gets that argument to stderr — name the key <stdarg.h> pieces and the ONE function that accepts a va_list.

7. Why does a long-running program have to close descriptors even though exit() would close them eventually?

8. What does unlink actually remove? Which ANSI C function is its portable cousin?

9. Write the single modern open() call equivalent to creat(name, 0666).

10. (Prediction) f1 = open("x", O_RDONLY, 0) on a machine where "x" doesn't exist, then read(f1, buf, 10). What are f1 and read's return? What SHOULD the code have done between the two calls?
