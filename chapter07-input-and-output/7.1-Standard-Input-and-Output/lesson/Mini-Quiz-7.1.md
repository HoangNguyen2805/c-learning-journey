# Mini-Quiz 7.1 - Standard Input and Output

1. What is a "text stream", and what character delimits its lines?

2. Explain what the shell does differently for `./prog data.txt` versus `./prog < data.txt`. In which case does `data.txt` appear in argv?

3. Why must the variable receiving getchar() be `int` and not `char`? What specific failure happens otherwise?

4. Write the canonical filter loop that copies stdin to stdout unchanged.

5. What does `sort < scores.txt | head -3 > top.txt` do, step by step? How many programs run?

6. Your program both reads with getchar and prints prompts with printf. When you redirect stdout to a file, where do the prompts go? Is that ever a problem? (Foreshadowing 7.6...)

7. Name four functions/macros from `<ctype.h>` and what they test or convert.

8. Why is `tolower(c)` more portable than `c + 'a' - 'A'`?

9. The "filter" pattern underlies tools like cat, wc, tr. What three phases does every filter share?

10. (Prediction) Input is `Hi 5!\n` piped into the 7.1A example program. What exact transformed text does it echo, and what are the five tallies?
