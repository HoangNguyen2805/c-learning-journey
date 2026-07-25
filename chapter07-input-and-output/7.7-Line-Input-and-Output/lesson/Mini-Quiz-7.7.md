# Mini-Quiz 7.7 - Line Input and Output

1. Give fgets's three parameters and its return value in both the success and end-of-file cases.

2. How many characters can `fgets(line, 100, fp)` store at most, counting the terminator? Where does the '\n' go if the line fits?

3. Why is gets() fundamentally unfixable while fgets is safe? What single parameter embodies the difference?

4. List the newline behaviors: fgets, fputs, gets, puts — which keep/strip/add '\n'?

5. Write the standard two-line snippet that removes a trailing newline from a string read by fgets.

6. Input file line: 80 chars + '\n'. Your buffer: `char line[32]`. How many fgets calls consume the line, and which call's stored string contains the '\n'?

7. Using the answer to 6: why is "number of fgets calls" the wrong way to count lines, and what check fixes the count?

8. In the book's fgets source, explain the purpose of `--n > 0` in the loop condition and of the final `(c == EOF && cs == s)` test.

9. Why is fgets+sscanf more robust than fscanf for record parsing? What happens to each on a malformed line?

10. Build `int mygetline(char *line, int max)` on top of fgets exactly as the book does — write it out.
