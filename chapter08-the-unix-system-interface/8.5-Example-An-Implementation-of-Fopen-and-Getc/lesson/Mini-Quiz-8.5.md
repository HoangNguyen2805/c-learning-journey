# Mini-Quiz 8.5 - An Implementation of Fopen and Getc

1. List the five members of K&R's FILE struct and one sentence on each one's job.

2. What are stdin, stdout, stderr in this implementation — where do they live and how are the macros defined?

3. Decode the flag values _READ 01, _WRITE 02, _UNBUF 04, _EOF 010, _ERR 020. Why powers of two (in octal!)?

4. Walk through the getc macro on a buffer with cnt=3: what happens to cnt and ptr, and which path runs? Then with cnt=0?

5. Why is getc a macro rather than a function in this design? What cost is being avoided on the fast path?

6. In fopen, how is a "free slot" recognized, and what happens when all OPEN_MAX slots are busy?

7. Explain the "a" (append) branch of fopen: why TWO possible syscalls, and why the lseek?

8. _fillbuf allocates fp->base lazily. When exactly, and what advantage does lazy allocation give a program that opens many files but reads few?

9. In _fillbuf, after `fp->cnt = read(...)`, the code does `if (--fp->cnt < 0)`. Distinguish what cnt==-1 vs cnt<-1 means and which flag each sets. How do the feof/ferror macros report these later?

10. (Integration) Name the earlier section that supplied each ingredient: the struct, the typedef, the flag bits, the fd, the read call, and the lseek in append mode.
