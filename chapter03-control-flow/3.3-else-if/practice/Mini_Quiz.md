# Mini Quiz - 3.3 Else-If

1. What does `else if` do?
- It checks another condition only if the previous if or else if condition was false.
2. When does C check an `else if` condition?
- From top to bottom , After the previous if or else if condition is false and before else
3. Are conditions checked from top to bottom?
- Yes
4. In an if / else-if / else chain, how many branches can run?
- Only one branch.
5. Is `else` required?
- no
6. What happens if there is no `else` and none of the conditions are true?
- Nothing runs in that chain.
7. Why does order matter in an else-if chain?
- Because C stops at the first true condition, so earlier conditions can block later ones.
8. Why is this order wrong for grades?

```c
if (score >= 70)
    printf("C\n");
else if (score >= 80)
    printf("B\n");
else if (score >= 90)
    printf("A\n");
```
- Because if statement condition is undervalue compare to else if, so if condition can alway be satisfy and never get a chance to else if.
- a score like 95 already satisfies score >= 70, so C prints C and never reaches the 80 or 90 checks.
9. What should usually come first: the most specific condition or the weakest condition?
- the most specific condition
10. What is the difference between an else-if chain and separate if statements?
- An else-if chain runs only one matching branch. Separate if statements are checked independently.
11. Can separate if statements run more than one branch?
- Yes.
12. What is the main idea of K&R 3.3?
- else if lets C choose one branch from several conditions, checked from top to bottom.