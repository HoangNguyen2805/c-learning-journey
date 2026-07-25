# Mini-Quiz 7.2 - Formatted Output printf

1. List the five optional parts between % and the conversion character, in order.

2. Predict output exactly (mark spaces with _): `printf(":%8.3f:", 3.14159);`

3. What's the difference between width and precision for a STRING conversion? For an INT?

4. Predict: `printf(":%-12.5s:", "programming");`

5. Why is `printf(userinput)` dangerous while `printf("%s", userinput)` is safe?

6. Show two ways to print a number right-justified in a field whose width is only known at runtime.

7. What do these produce for the value 255: `%#x`, `%08d`, `%+d`?

8. What does printf return, and when might a program actually use it?

9. sprintf writes into a caller-supplied buffer. What responsibility does that put on the caller, and what bug results from ignoring it?

10. (Debug) A student writes `printf("%d", 3.14);`. What's wrong, why can't printf itself catch it, and who CAN catch it on your machine?
