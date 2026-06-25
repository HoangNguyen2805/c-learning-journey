# Mini Quiz - 3.8 Goto and Labels

1. What does `goto` do?
- goto makes the program jump to a labeled place in the code.
2. What is a label?
- lable is goto [dstination] : - its A label is a named destination that goto can jump to. of where you want to end up at
3. What symbol comes after a label name?
- :
4. What does this mean?

```c
done:
```
- This is a label named done.
5. What does this mean?

```c
goto done;
```
- Jump to the label named done.
6. Why can `goto` make code hard to read?
- Because it can jump around the program instead of following normal top-to-bottom order.
7. Should beginners use `goto` often?
- no
8. What should you usually use instead of `goto` when possible?
- Use if, else, loops, break, continue, and functions instead.
9. What does `break` do?
- break exits the nearest loop or switch.
10. Does `break` leave one loop or all nested loops?
- Only one loop: the nearest loop that contains the break.
11. When can `goto` be useful?
- goto can be useful for jumping out of multiple nested loops.
12. Why does K&R include `goto`?
- Because C has goto, and there are rare situations where it can be useful, especially escaping deeply nested loops or handling cleanup.
13. What is the main warning from K&R 3.8?
- Do not overuse goto because it can make code confusing and hard to follow.
14. What is the main thing to remember from this section?
- goto jumps to a label, but you should usually avoid it unless it makes the code simpler, like escaping nested loops.