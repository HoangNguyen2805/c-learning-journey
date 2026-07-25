# Mini-Quiz 7.8 - Miscellaneous Functions

1. What must be true about `s` before calling `strcat(s, t)` — two conditions?

2. strncpy(s, t, n) has a famous gotcha when strlen(t) >= n. What is it, and what one line repairs it?

3. Write an expression using strrchr that yields a pointer to a filename's extension (".txt" from "a.b/c.txt"), and say what it returns if there's no dot.

4. Why do the ctype functions take/return int rather than char? (Connect to getchar/EOF.)

5. What guarantee does ungetc give about pushback depth? Give the argument order and one use case from your getword work.

6. malloc vs calloc: two differences (arguments and initialization).

7. State three rules about free() from the book (what you may free, when, order/repetition).

8. Why does `ip = (int *) calloc(n, sizeof(int))` document intent better than untyped assignment, per K&R's presentation?

9. Write the frand macro for [0,1) and explain why the naive `rand()/RAND_MAX` (integer division) fails.

10. Your tests need "random" data that's identical on every run. Which call arranges that, and where does it go?
