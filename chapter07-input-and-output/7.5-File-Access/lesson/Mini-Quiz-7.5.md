# Mini-Quiz 7.5 - File Access

1. What is a FILE*? Do you ever manipulate its members directly in Chapter 7 code?

2. Describe the behavioral difference between opening an EXISTING file with "r", "w", and "a".

3. Why must every fopen be followed by a NULL check? Give two distinct real-world causes of failure.

4. Express getchar and putchar in terms of getc/putc and the standard streams.

5. In the book's cat: what does it do when run with NO filename arguments, and why is that convention powerful in a shell?

6. Why does cat call fclose inside the loop rather than once at the end?

7. Beyond OS limits on open files, what does fclose do for a file opened for WRITING that makes skipping it dangerous?

8. Write the three lines that open "log.txt" for appending, write "run %d\n" with variable r, and close it — with the NULL check.

9. filecopy takes two FILE* parameters instead of two filenames. Name two call sites from the book/example that this flexibility enables.

10. (Prediction) A file holds "hello". You fopen it with "w", immediately fclose, then read it. What's in the file, and which single step destroyed the data?
