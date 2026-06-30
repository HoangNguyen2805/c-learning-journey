# 4.7 Quiz - Register Variables

## Question 1
True or False: "register" guarantees the compiler will make that variable faster.

## Question 2
What is the ONE real, enforced rule about register variables (not just a
suggestion, but something the compiler will actually refuse to compile
if you break it)?

## Question 3
```c
register int x = 5;
printf("%p\n", &x);
```
Does this code compile successfully? Why or why not?

## Question 4
Why is "register" rarely used in modern C, even though K&R discusses it
as if it's important?

## Question 5
True or False: register can only be used on local variables, never on
function parameters.