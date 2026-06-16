## Lesson 06F - Cumulative Loop Patterns

This lesson is not a brand-new loop type.

This lesson is about combining everything:

```text
while
for
do while
break
continue
if / else
scanf
sum
count
%
```

A real loop program usually does more than one thing.

It can:

```text
repeat input
check if value should stop
skip bad values
count things
add totals
print final result
```

## Pattern 1 - loop + break

Use `break` when the user enters a stop value.

Example:

```c
if (number == 0) {
    break;
}
```

Meaning:

```text
If user enters 0, stop the loop completely.
```

Memory rule:

```text
break = stop the whole loop now
```

## Pattern 2 - loop + continue

Use `continue` when you want to skip one bad input but keep looping.

Example:

```c
if (number < 0) {
    continue;
}
```

Meaning:

```text
If number is negative, skip this round and go to the next input.
```

Memory rule:

```text
continue = skip only this loop round
```

## Pattern 3 - loop + sum

Use `sum += number;` to add each accepted number.

Example:

```c
sum += number;
```

Meaning:

```text
sum = sum + number
```

Example:

```text
sum starts at 0

number = 5
sum = 0 + 5 = 5

number = 8
sum = 5 + 8 = 13
```

Memory rule:

```text
sum += number means add number into the total
```

## Pattern 4 - loop + count

Use `count++` to count something.

Example:

```c
count++;
```

Meaning:

```text
count = count + 1
```

Example:

```text
count starts at 0

first valid number found:
count becomes 1

second valid number found:
count becomes 2
```

Memory rule:

```text
count++ means add 1 to the count
```

## Pattern 5 - even / odd inside loop

Use `% 2` to check even or odd.

Example:

```c
if (number % 2 == 0) {
    evenCount++;
} else {
    oddCount++;
}
```

Meaning:

```text
If number divided by 2 has remainder 0, it is even.
Otherwise, it is odd.
```

Examples:

```text
10 % 2 = 0, even
7 % 2 = 1, odd
```

## Big memory rule

```text
break = stop the whole loop
continue = skip only this round
sum += number = add number to total
count++ = add 1 to count
number % 2 == 0 = even
number % 2 != 0 = odd
```
