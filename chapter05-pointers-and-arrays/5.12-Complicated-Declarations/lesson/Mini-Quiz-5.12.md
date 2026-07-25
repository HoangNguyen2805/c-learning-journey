# Mini-Quiz 5.12 - Complicated Declarations

Translate 1-6 into English. Write 7-8 in C. Answer 9-10 conceptually.

1. `int (*p)[20];`

2. `char *table[8];`

3. `double (*func_table[4])(double, double);`

4. `int (*f(void))[10];`   (careful: what does f return?)

5. `char (*(*x())[])();`   (the book's monster - go step by step)

6. `const int *p;` vs `int *const p;` - what can change in each?

7. Declare `handlers`: an array of 6 pointers to functions taking `int` and returning `void`.

8. Declare `getmatrix`: a function taking no arguments and returning a pointer to an array of 4 ints.

9. In the dcl program, why do `dcl()` and `dirdcl()` need to call each other? Point to the grammar rule that forces mutual recursion.

10. Why does `dcl()` output the word "pointer to" AFTER calling `dirdcl()`, even though the `*` appears BEFORE the name in source code?
