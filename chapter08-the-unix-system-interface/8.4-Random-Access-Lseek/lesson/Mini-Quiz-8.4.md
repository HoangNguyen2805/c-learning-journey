# Mini-Quiz 8.4 - Random Access lseek

1. Give lseek's three parameters, the meaning of each origin value (0/1/2), and its return value in success and failure.

2. Write the calls for: (a) rewind, (b) jump to end, (c) back up 8 bytes from wherever you are, (d) position on the final byte.

3. How do you get "tell" (current position) out of lseek without moving?

4. Fixed 64-byte records: write the two calls that fetch record k. Why must the offset math be done in long?

5. Explain the book's get() — what does it combine, and what does it return in each of its outcome paths?

6. Why does record-based random access beat sequential scanning for "fetch record 90000 of 100000"? Give both complexities.

7. What happens when you lseek 100 bytes past EOF and write 5 bytes? What do the intervening bytes read as?

8. Name the stdio counterparts to lseek and "tell".

9. You've been reading a file with getc (buffered stdio) and now lseek its descriptor directly. What goes wrong and why?

10. (Prediction) File contains "HELLO WORLD". Code: lseek(fd,6L,0); write(fd,"C",1); lseek(fd,0L,0); read 11 bytes. What string do you get?
