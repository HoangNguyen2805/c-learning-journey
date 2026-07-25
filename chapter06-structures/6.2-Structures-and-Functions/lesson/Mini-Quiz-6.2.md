# Mini-Quiz 6.2 - Structures and Functions

1. Name the three ways a function can receive structure data, and rank them by copy cost for a large struct.

2. In K&R's `addpoint`, the code modifies parameter `p1` directly. Why is this safe for the caller?

3. `makepoint` returns a local variable `temp`. Locals die at return — so why is returning `temp` legal and correct here?

4. Why does `*pp.x` fail to compile when `pp` is a `struct point *`? Fix it two different ways.

5. When should you pass `struct big *p` instead of `struct big b`, even if the function never modifies it?

6. Translate to plain English what each does (`p` is a struct pointer with members `len` (int) and `str` (char*)):
   - `++p->len`
   - `*p->str++`
   - `(*p->str)++`

7. Write the signature of a function `midpoint` that takes two `struct point` BY VALUE and returns their midpoint as a `struct point`.

8. Rewrite this to use the arrow operator: `(*rp).pt1.x = 0;`

9. What does declaring a parameter `const struct rect *rp` promise, and why is it good practice for read-only pointer params?

10. (Code prediction)
```c
struct point p = {1,1};
scale_copy(p, 5);      /* by value  */
scale_ptr(&p, 5);      /* by pointer */
printf("%d", p.x);
```
What prints, and why?
