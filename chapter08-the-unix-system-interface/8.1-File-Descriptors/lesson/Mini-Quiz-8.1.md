# Mini-Quiz 8.1 - File Descriptors

1. What IS a file descriptor (its type and what it identifies)? Who hands you descriptors 0, 1, and 2?

2. Map each: 0, 1, 2 → which standard stream?

3. When the shell runs `prog < in.txt > out.txt`, describe what happens to descriptors before prog starts. Does prog's code see the filenames?

4. Why is it valuable that error output has its OWN descriptor (2)? Reconnect to 7.6.

5. "On UNIX, peripherals are files." What uniformity benefit does this design buy for the read/write interface?

6. Contrast FILE* and an fd across: type, creation call, and buffering.

7. What does fileno(fp) return? What would you expect fileno of the first file YOU open to be, and why?

8. When mixing printf (buffered) and write(1,...) (unbuffered), what ordering hazard exists and which call tames it?

9. isatty(1) returns 1 in one situation and 0 in another from this chapter's perspective — which situations?

10. (Concept) The C library's getc/putc are built ON descriptors. Which chapter section will show that structure explicitly, and what struct member will hold the fd?
