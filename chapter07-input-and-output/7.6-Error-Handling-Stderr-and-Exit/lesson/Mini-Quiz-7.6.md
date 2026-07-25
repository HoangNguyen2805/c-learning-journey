# Mini-Quiz 7.6 - Error Handling stderr and Exit

1. Explain the disaster scenario when error messages go to stdout in `./prog > data.out`. Two distinct harms occur — name both.

2. Which stream do these belong on: (a) the computed report, (b) "warning: line 12 skipped", (c) a progress bar? Justify (c).

3. Why do good tools prefix messages with argv[0] rather than a hardcoded name?

4. What exit status conventionally means success? How does the SHELL use exit statuses (give one operator or variable)?

5. State two things exit() does beyond ending the program, and why the flushing part matters for files opened "w".

6. Difference between `exit(1)` called in a helper function vs `return 1` in main — when are they equivalent, when is exit the only option?

7. Both end-of-input and an I/O error make getc return EOF. Which two functions disambiguate, and what does each report?

8. Why does the book's cat check `ferror(stdout)` before exiting? What real-world condition would trip it?

9. Write a variadic `die(const char *fmt, ...)` signature + its two key body lines (forwarding and exiting). Which header(s) do you need?

10. (Shell) Show the command line that runs ./prog sending results to r.txt and errors to e.txt separately.
