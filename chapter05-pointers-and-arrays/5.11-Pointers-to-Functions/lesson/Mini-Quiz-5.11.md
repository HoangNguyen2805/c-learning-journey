# Mini-Quiz 5.11 - Pointers to Functions

1. Explain the difference between these two declarations:
```c
int *f(int);
int (*f)(int);
```

2. Given `int max(int a, int b);` — write the two statements that (a) declare a suitable function pointer `fp`, and (b) make it point at `max`. No calls yet.

3. What is the difference between `fp = max;` and `fp = max(2,3);`? What ends up stored in each case?

4. K&R calls through a pointer as `(*comp)(a, b)`. Modern C also allows `comp(a, b)`. Why did K&R's style make the code's meaning more explicit?

5. Why does the generic qsort in 5.11 declare its array as `void *v[]` instead of `char *v[]`? What property of `void *` makes this work?

6. What "contract" must any comparison function follow to be usable by the sort (think: what do its return values mean)?

7. Write the declaration of an array named `handlers` holding 4 pointers to functions that take a `char` and return `void`.

8. In the book's sort, `numeric ? numcmp : strcmp` selects a comparator at runtime. What would you have to write instead if function pointers didn't exist? Why is that worse as comparators multiply?

9. (Code reading) What does this print?
```c
int twice(int x){ return 2*x; }
int (*p)(int) = twice;
printf("%d\n", p(p(5)));
```

10. Dispatch tables (arrays of function pointers) can replace long switch statements. Give one advantage and one disadvantage of the table approach.
