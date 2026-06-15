# Day 05 Mini Quiz - Conditions / if else

Answer without looking at notes first.

## Questions

1. What is a condition in C?

Answer: Condition is the fact that help C make decision.

2. What does an `if` statement do?

Answer: if statement is how c make it owndecision using condition to detemine the correct decision.

3. What does this mean?

```c
if (age >= 18) {
    printf("Adult\n");
}
```

Answer: is a is older or equal to 18 , print aldult.

4. What happens to code outside the `{ }` of an `if` statement?

Answer: It'll create error, it not part of the if statement. it won't be exercute when if statement is excercute.
Fix: Code outside the if block always runs.
It does not belong to the if.
It will not create an error.

5. What does `else` do?

Answer: Else is when the condition of an if statement is false.

6. Can `else` have a condition?

Answer: No

7. What does `else if` do?

Answer: else if is the thing that when the condition of if statement is already false but there is still another condition in the else if might be true

8. Why does order matter in an `else if` chain?

Answer: Because it not right at the first if statement but it also not entirely wrong at last.
Fix:C checks else-if from top to bottom.
Once one condition is true, C runs that block and skips the rest.
So the order can change the answer.

9. What does `==` mean?

Answer: compare if the value is equivalent or not.

10. What does `=` mean?

Answer: assign value to variable

11. What is wrong with this?

```c
if (age = 18) {
    printf("Age is 18\n");
}
```

Answer: You don't check if age is 18 or not, You assign 18 to age, which is wrong

12. What does `!=` mean?

Answer: not equal to

13. What does `>=` mean?

Answer: bigger or equal to.

14. What does `<=` mean?

Answer: smaller or equal to.

15. What does `&&` mean?

Answer: AND operation. Mean 2 condition have to be True

16. What does `||` mean?

Answer: Or operation, Mean only 1 or the other have to be True

17. What does `!` mean?

Answer: NOT operation, mean flip True into False and Flip False into True.

18. In C, what number means false?

Answer: 0

19. In C, what kind of number means true?

Answer: 1
Fix: Non-zero

20. What does this condition mean?

```c
if (age >= 18 && hasID == 1)
```

Answer: if age is bigger or equal to 18 AND got to have ID at the same time.

21. What does this condition mean?

```c
if (hasCash == 1 || hasCard == 1)
```

Answer: If you have cash OR card, but you only require to have one of them.

22. What does this condition mean?

```c
if (!isRaining)
```

Answer: is raining or not
Fix: It means if it is NOT raining.
If isRaining is 0, then !isRaining is true.

23. What is a nested if?

Answer: If statemnet inside if statement.

24. When is nested if useful?

Answer: If statement inside of another if statement help you verified if both condition is true or only one condition is true.
Fix: Nested if is useful when I want to check conditions step by step and give different messages depending on which condition failed.

25. What is the simpler version of this nested if?

```c
if (age >= 18) {
    if (hasID == 1) {
        printf("You can enter.\n");
    }
}
```

Answer:
if (age >= 18 && hasID == 1) {
    printf("You can enter.\n");
}

26. What is wrong with this?

```c
if (age >= 18);
{
    printf("Adult\n");
}
```

Answer: ; is not allow in if statement
Fix:The semicolon ends the if statement too early.
Then the block runs separately, not controlled by the if.

27. What is wrong with this?

```c
if (score >= 70) {
    printf("C\n");
} else if (score >= 90) {
    printf("A\n");
}
```

Answer:if score is bigger than 70 then it already print C, it'll never get a chance to print A

28. What does this check?

```c
if (number % 2 == 0)
```

Answer: check if number is even 

29. Why do we use parentheses here?

```c
if (hasTicket == 1 && (age >= 18 || hasParent == 1))
```

Answer: because we require to have ticket but aldult doesnt need to come with parent.

30. Write the correct condition:

User can enter if they have a ticket AND they are 18 or older.

Answer:
if ( hasTicket == 1 && age >= 18 ) {
    printf("You can enter.\n");
}
