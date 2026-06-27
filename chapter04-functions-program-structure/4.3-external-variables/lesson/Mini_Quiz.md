# 4.3 Mini Quiz - External Variables

1. Where is an external variable declared?
- Outside of all function.
2. Can a local variable inside one function be seen by a different function?
- No
3. If a void function changes an external variable using "total = total + x;", does main() need to capture a return value for that change to take effect?
- Yes
fix: This one's wrong, and it's worth re-examining given everything we just traced through. The function is void — it has no return statement at all, and main() isn't capturing anything from it. The update happens the instant total = total + x; runs, inside the function — fully independent of whether main() does anything afterward. Go back to your own walkthrough from a minute ago: did main() ever need to "capture" anything for x to become 5, then 12? What's the correct answer here?
4. If two separate functions each return a value, but main() never stores those return values in a variable, what happens to those returned values?
- Loss
5. What actually causes an external variable to update — the return statement, or the assignment statement inside the function?
- the assignment statement inside the function
6. True or False: in C, you can define one function's body inside another function's body.
- F
7. What's one real downside of using external variables too much, according to the lesson?
- Hard to read.
8. If addFive() and addTen() both modify the same external total, and main() calls addFive() then addTen(), what is the FINAL value of total after both calls — does it depend on what each function returns?
- 15, YES
fix:8. Half right — the 15 is correct (0+5+10=15), but the "YES" is wrong, and this is the same misconception as #3. The final value of total is 15 regardless of whether addFive/addTen return anything at all — even if they were void with no return, total would still be 15, because the update happens through the internal assignment (total = total + ...), not through what gets returned to main(). Does the final total depend on what each function returns, or does it depend only on what each function assigns to total internally?