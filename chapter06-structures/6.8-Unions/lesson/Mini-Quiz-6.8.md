# Mini-Quiz 6.8 - Unions

1. In one sentence each: how do a struct and a union differ in (a) memory layout and (b) how many members are usable at once?

2. If a union has members `char c;` (1 byte), `int i;` (4), `double d;` (8), what is the minimum `sizeof` the union? What decides its alignment?

3. What does "it is the programmer's responsibility" mean for unions, per K&R? What goes wrong in:
```c
u.fval = 3.14f;
printf("%d", u.ival);
```

4. Describe the tagged-union pattern: what two pieces does it combine, and what discipline must every write and read follow?

5. Why is a plain `union { int; float; char*; }` initialization `= { 5 }` guaranteed to set the int? Which C99 feature lifts this restriction?

6. Can you assign one union variable to another with `=`? Compare two with `==`? (One yes, one no — which and why?)

7. A symbol table entry needs: name (char*), plus a value that is EITHER an int constant OR a float constant OR a string. Sketch the struct+union declaration.

8. Give one legitimate use of unions and one questionable use, and say why the second is non-portable.

9. `pu` is a pointer to a union with member `fval`. Write two equivalent expressions to access `fval` through `pu`.

10. (Prediction) In Example 3 of the lesson code, `&u.ival` and `&u.fval` print the same address. Explain why this MUST be true from the definition of a union.
