# Day 06 - Loops in C

## What is a loop?

A loop repeats code.

Without a loop:

```c
printf("Hello\n");
printf("Hello\n");
printf("Hello\n");
```

With a loop:

```c
int i = 1;

while (i <= 3) {
    printf("Hello\n");
    i++;
}
```

Output:

```text
Hello
Hello
Hello
```

## Why loops are important

Loops help us repeat tasks without writing the same code many times.

Loops are useful for:

```text
printing numbers
repeating practice
reading many inputs
counting
summing numbers
searching arrays later
solving LeetCode problems
```

## The 3 main loops in C

```text
while loop
for loop
do while loop
```

## Loop parts
<>
Most loops have 3 important parts:

```text
1. Start value
2. Condition
3. Update
```

Example:

```c
int i = 1;

while (i <= 5) {
    printf("%d\n", i);
    i++;
}
```

Parts:

```text
int i = 1      start value
i <= 5         condition
i++            update
```

## Counter variable

A counter variable keeps track of how many times the loop runs.

Common counter names:

```text
i
j
k
count
```

Example:

```c
int i = 1;
```

`i` is the counter.

## while loop

A `while` loop repeats while the condition is true.

Basic format:

```c
while (condition) {
    code;
}
```

Example:

```c
int i = 1;

while (i <= 5) {
    printf("%d\n", i);
    i++;
}
```

Output:

```text
1
2
3
4
5
```

Meaning:

```text
Start i at 1.
While i is less than or equal to 5, print i.
After each print, add 1 to i.
Stop when i becomes 6.
```

## while loop step by step

Code:

```c
int i = 1;

while (i <= 5) {
    printf("%d\n", i);
    i++;
}
```

Steps:

```text
i = 1, condition true, print 1, i becomes 2
i = 2, condition true, print 2, i becomes 3
i = 3, condition true, print 3, i becomes 4
i = 4, condition true, print 4, i becomes 5
i = 5, condition true, print 5, i becomes 6
i = 6, condition false, stop
```

## Infinite loop

An infinite loop never stops.

Bad:

```c
int i = 1;

while (i <= 5) {
    printf("%d\n", i);
}
```
mean:
i = 1

check: 1 <= 5 true
print 1

i is still 1

check: 1 <= 5 true
print 1

i is still 1

check: 1 <= 5 true
print 1
-> Missing update i++; so i = 1 forever, and as long as i stay at 1 (not increase up to to 5), the while loop stay on and loop printing forever.

Problem:

```text
i never changes
i is always 1
condition is always true
loop never stops
```

Fix:

```c
int i = 1;

while (i <= 5) {
    printf("%d\n", i);
    i++;
}
```

Memory rule:

```text
If the loop condition depends on a variable, that variable usually needs to change inside the loop.
```

## for loop

A `for` loop puts start, condition, and update in one line.

Basic format:

```c
for (start; condition; update) {
    code;
}
```

Example:

```c
for (int i = 1; i <= 5; i++) {
    printf("%d\n", i);
}
```

Output:

```text
1
2
3
4
5
```

Parts:

```text
int i = 1      start
i <= 5         condition
i++            update
```

## for loop vs while loop

These two do the same thing.

while loop:

```c
int i = 1;

while (i <= 5) {
    printf("%d\n", i);
    i++;
}
```

for loop:

```c
for (int i = 1; i <= 5; i++) {
    printf("%d\n", i);
}
```

Use `for` when you know how many times you want to loop.

Use `while` when you want to loop until something happens.

## do while loop

A `do while` loop runs the code first, then checks the condition.

Basic format:

```c
do {
    code;
} while (condition);
```

Example:

```c
int i = 1;

do {
    printf("%d\n", i);
    i++;
} while (i <= 5);
```

Output:

```text
1
2
3
4
5
```

## Important: do while runs at least once

Example:

```c
int i = 10;

do {
    printf("%d\n", i);
    i++;
} while (i <= 5);
```

Output:

```text
10
```

Why?

```text
do while runs the code first.
Then it checks the condition.
```

So even though `10 <= 5` is false, it still prints once.

## break

`break` stops a loop immediately.

Example:

```c
for (int i = 1; i <= 10; i++) {
    if (i == 5) {
        break;
    }

    printf("%d\n", i);
}
```

Output:

```text
1
2
3
4
```

When `i` becomes 5, `break` stops the loop.

Memory rule:

```text
break = leave the loop now
```

## continue

`continue` skips the rest of the current loop round and jumps to the next round.

Example:

```c
for (int i = 1; i <= 5; i++) {
    if (i == 3) {
        continue;
    }

    printf("%d\n", i);
}
```

Output:

```text
1
2
4
5
```

Why?

```text
When i is 3, continue skips printf.
Then the loop moves to i = 4.
```

Memory rule:

```text
continue = skip this round, go to next round
```

## break vs continue

```text
break     = stop the whole loop
continue  = skip only this round
```

Example:

```text
break at 3:
1
2
stop

continue at 3:
1
2
4
5
```

## Using scanf inside loops

Loops can ask for input multiple times.

Example:

```c
int number;

for (int i = 1; i <= 3; i++) {
    printf("Enter number: ");
    scanf("%d", &number);

    printf("You entered %d\n", number);
}
```

This asks for 3 numbers.

## Sum with loop

Example:

```c
int number;
int sum = 0;

for (int i = 1; i <= 3; i++) {
    printf("Enter number: ");
    scanf("%d", &number);

    sum += number;
}

printf("Sum: %d\n", sum);
```

If input is:

```text
10
20
30
```

Output:

```text
Sum: 60
```

## Counting even numbers

Example:

```c
int number;
int evenCount = 0;

for (int i = 1; i <= 5; i++) {
    printf("Enter number: ");
    scanf("%d", &number);

    if (number % 2 == 0) {
        evenCount++;
    }
}

printf("Even count: %d\n", evenCount);
```

This uses:

```text
scanf
for loop
if
%
++
```

## Off-by-one mistake

Off-by-one means the loop runs one time too many or one time too few.

Example:

```c
for (int i = 1; i < 5; i++) {
    printf("%d\n", i);
}
```

Output:

```text
1
2
3
4
```

It does not print 5 because condition is:

```text
i < 5
```

If you want 1 through 5, use:

```c
for (int i = 1; i <= 5; i++) {
    printf("%d\n", i);
}
```

Memory rule:

```text
i < 5 gives 1 to 4
i <= 5 gives 1 to 5
```

## Common mistake 1: forgetting update

Wrong:

```c
int i = 1;

while (i <= 5) {
    printf("%d\n", i);
}
```

Problem:

```text
i never changes
infinite loop
```

Correct:

```c
int i = 1;

while (i <= 5) {
    printf("%d\n", i);
    i++;
}
```

## Common mistake 2: semicolon after loop

Wrong:

```c
for (int i = 1; i <= 5; i++);
{
    printf("Hello\n");
}
```

The semicolon ends the loop early.

Correct:

```c
for (int i = 1; i <= 5; i++) {
    printf("Hello\n");
}
```

## Common mistake 3: wrong condition

Wrong if I want 1 to 5:

```c
for (int i = 1; i < 5; i++) {
    printf("%d\n", i);
}
```

This prints only 1 to 4.

Correct:

```c
for (int i = 1; i <= 5; i++) {
    printf("%d\n", i);
}
```

## Common mistake 4: using = instead of == inside loop condition

Wrong:

```c
if (i = 3) {
    printf("Three\n");
}
```

Correct:

```c
if (i == 3) {
    printf("Three\n");
}
```

Memory rule:

```text
= means assign
== means compare
```

## Common mistake 5: break vs continue confusion

`break` stops the loop.

`continue` skips one round.

```text
break = stop
continue = skip
```

## What I need to remember

```text
Loop = repeat code

while = repeat while condition is true
for = repeat with start, condition, update in one line
do while = run once first, then check condition

counter variable = tracks loop number

i++ means i = i + 1

break = stop loop
continue = skip current round

Avoid infinite loops:
make sure the loop variable changes

for loop format:
for (start; condition; update) {
    code;
}

while loop format:
while (condition) {
    code;
}

do while format:
do {
    code;
} while (condition);
```
