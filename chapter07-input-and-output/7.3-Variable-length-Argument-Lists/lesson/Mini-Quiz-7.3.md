# Mini-Quiz 7.3 - Variable-length Argument Lists

1. Name the four <stdarg.h> tools and one sentence each on their job.

2. Why must a variadic function have at least one named parameter?

3. In minprintf, explain how the function knows (a) how many arguments follow and (b) their types.

4. You pass a `float` to a variadic function. What type must the matching va_arg use, and why?

5. Same question for a `char` argument.

6. What does `*++p` accomplish inside minprintf's switch? Trace it on the format "x%dy".

7. Write the skeleton of `int product_n(int count, ...)` — just the va_ lines and loop shape, computing the product of count ints.

8. What happens (conceptually) if the caller writes `minprintf("%d %d", 5)` — one spec too many? Why can't minprintf detect it?

9. To build your own `die(fmt, ...)` that prefixes "fatal: " and forwards to fprintf(stderr, ...), which library function must you use and why can't plain fprintf work?

10. Where must va_end appear relative to the function's returns, and what does forgetting it risk (per the standard, not your machine's mercy)?
