# Mini Quiz - 3.4 Switch

1. What does `switch` do?
- switch chooses what code to run based on one exact value.
2. What kind of values is `switch` best for?
- menu choices , letter grades , day numbers , simple commands
3. What does `case` mean?
- case means: if the switch value equals this exact value, run this code.
4. What does `break` do inside a switch?
- break exits the switch.
5. What happens if you forget `break`?
- C will fall through and run the next case’s code, even if that case does not match.
6. What is fall-through?
- Fall-through is when C keeps running into the next case because there is no break.
7. What does `default` do?
- default runs if no case matches.
8. Is `default` required?
- No
9. Can `switch` check ranges like `score >= 90`?
- No
10. Which is better for ranges: `switch` or `else-if`?
- else-if
11. Which is better for exact menu choices: `switch` or `else-if`?
- switch
12. What does this mean?

```c id="jzd2nv"
case 1:
```
- Run this case if the switch value equals the integer 1.
13. What does this mean?

```c id="8b2srn"
case 'A':
```
- Run this case if the switch value equals the character 'A'.
14. Why should beginners usually put `break` after every case?
- So C doesn't matched multiple case or fall through
15. What is the main idea of K&R 3.4?
- The main idea of K&R 3.4 is that switch is used for multi-way decisions based on one exact value. Each case checks one constant value, default handles no match, and break is usually needed to stop fall-through.