# Mini-Quiz 8.2 - Low Level I/O Read and Write

1. Give the full meaning of every parameter and the return value of `read(fd, buf, n)`. Enumerate the three return-value cases.

2. In the raw copy loop, why must it be `write(1, buf, n)` and never `write(1, buf, BUFSIZ)`? Construct the failing input.

3. What performance difference separates buffer sizes 1 and BUFSIZ if syscalls dominate cost? For a 1 MB file with BUFSIZ=1024, roughly how many read calls each?

4. In the unbuffered getchar, explain the cast `(unsigned char) c`. Which input byte misbehaves without it?

5. In the buffered getchar, why must buf, bufp, and n be `static`?

6. Trace the buffered getchar's very first call on input "hi": what do n, bufp, and the return value look like after it?

7. What does `--n >= 0` elegantly combine (two jobs in one expression)?

8. "The operating system knows nothing about lines." What does a newline look like to read/write, and where does line structure come from?

9. How would you build putchar's buffered cousin — what state, and WHEN must the buffer be flushed even if not full? (Think program exit.)

10. write returning a value different from its n argument indicates what? Give a real-world condition that causes it.
