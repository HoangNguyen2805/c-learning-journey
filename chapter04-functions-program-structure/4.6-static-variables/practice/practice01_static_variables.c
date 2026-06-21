/*
Practice 01 - Static Variables

Goal:
Understand K&R 4.6 Static Variables using the calculator idea.

This practice is NOT about memorizing the full calculator.
It is about understanding why K&R uses static.

--------------------------------------------------
Part 1: Static inside a function
--------------------------------------------------

Create a function named countCalls.

Inside countCalls:

1. create a static int variable named count
2. start count at 0
3. increase count by 1
4. print count

In main:

1. call countCalls three times

Expected idea:

First call prints 1
Second call prints 2
Third call prints 3

Question to answer in comments:

Why does count not reset to 0 every time?

--------------------------------------------------
Part 2: Static outside a function
--------------------------------------------------

Create private stack data.

Use these names:

sp
val

Requirements:

1. create a symbolic constant MAXVAL
2. create static int sp
3. create static double val[MAXVAL]
4. create a function named push
5. create a function named pop
6. in main, use push and pop to calculate 10 + 20

Expected result:

Result: 30.0

Important:

main should NOT directly change sp or val.

main should only use:

push(...)
pop()

Question to answer in comments:

Why are sp and val static?

--------------------------------------------------
Part 3: Explain the K&R idea
--------------------------------------------------

Add comments explaining:

1. static inside a function
2. static outside a function
3. internal name
4. external name
5. why sp and val should be private in stack.c
6. why buf and bufp should be private in getch.c
7. why other files should use functions instead of touching private variables directly

Rules:

- Do not use scanf.
- Do not use pointers.
- Do not use structs.
- Do not try to build the full calculator yet.
*/