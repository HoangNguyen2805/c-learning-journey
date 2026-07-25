# Mini-Quiz 7.4 - Formatted Input scanf

1. Why does scanf need & on an int variable but not on a char array?

2. What does scanf return (two distinct cases)? Write a loop that reads doubles until input stops being numeric OR ends.

3. What's the difference between `%f` in printf and `%f` in scanf regarding argument type? Why the asymmetry?

4. A blank in the FORMAT string matches what in the input? What about the letter `x` in the format?

5. Which conversion does NOT skip leading whitespace? Show the one-character fix to make it skip.

6. Predict: `sscanf("3.14", "%d.%d", &a, &b)` — what are the return value, a, and b?

7. What does `%*d` do, and give a realistic use for reading "rank name score" while ignoring rank.

8. Why can plain `scanf("%s", buf)` overflow buf, and what format change fixes it for `char buf[20]`?

9. User types "abc" when your loop does `while (scanf("%d",&n)==1)`. Explain the infinite-loop danger if you retry after failure and the line+sscanf cure.

10. Parse "12:34:56" into three ints — write the exact sscanf call including its success check.
