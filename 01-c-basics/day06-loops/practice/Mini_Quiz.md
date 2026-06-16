Day 06 Mini Quiz - Loops

1. What does a loop do?
   A. Stops the program
   B. Repeats code
   C. Deletes code
   D. Only prints numbers

Answer: B. Repeats code

2. What is the output?

int i = 1;

while (i <= 3) {
printf("%d\n", i);
i++;
}

A. 1 2 3
B. 1 2 3 4
C. 0 1 2
D. Infinite loop

Answer: A. 1 2 3

3. What happens if you forget i++ in this loop?

int i = 1;

while (i <= 5) {
printf("%d\n", i);
}

A. It prints once
B. It skips the loop
C. Infinite loop
D. Error always

Answer: C. Infinite loop

4. Which loop runs at least one time no matter what?
   A. for
   B. while
   C. do while
   D. if

Answer: C. do while

5. What does break do?
   A. Skips one loop round
   B. Stops the whole loop
   C. Adds 1
   D. Starts the loop over

Answer: B. Stops the whole loop

6. What does continue do?
   A. Stops the whole program
   B. Stops the whole loop
   C. Skips the current loop round
   D. Prints the answer

Answer: C. Skips the current loop round

7. What is the output?

for (int i = 1; i <= 5; i++) {
if (i == 3) {
continue;
}

```
printf("%d\n", i);
```

}

A. 1 2 3 4 5
B. 1 2 4 5
C. 3 only
D. 1 2 only

Answer: C. 3 only
Correct: B. 1 2 4 5

8. What is the output?

for (int i = 1; i <= 5; i++) {
if (i == 4) {
break;
}

```
printf("%d\n", i);
```

}

A. 1 2 3
B. 1 2 3 4 5
C. 4 5
D. 1 2 3 4

Answer: A. 1 2 3

9. What does this mean?

sum += number;

A. sum = number
B. number = sum
C. sum = sum + number
D. sum = sum - number

Answer: C. sum = sum + number

10. In Practice 06, why check number == 0 before even/odd count?
    A. Because 0 is negative
    B. Because 0 means stop, so we should not count it
    C. Because % cannot use 0
    D. Because 0 is odd

Answer: B. Because 0 means stop, so we should not count it