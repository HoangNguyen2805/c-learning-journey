# 4.7 Quiz - Register Variables

## Question 1
True or False: "register" guarantees the compiler will make that variable faster.
- F

## Question 2
What is the ONE real, enforced rule about register variables (not just a
suggestion, but something the compiler will actually refuse to compile
if you break it)?
- The one real, enforced rule is: you cannot take the address of a register variable using &. The compiler will refuse to compile it. Everything else about register is just a hint the compiler can ignore — but this one rule is actually enforced.

## Question 3
```c
register int x = 5;
printf("%p\n", &x);
```
Does this code compile successfully? Why or why not?
- No, This does NOT compile successfully. Because &x tries to take the address of x, which is declared register — and that's the one hard rule from Q2. The compiler will throw an error, since register variables may not have a standard memory address (they might live in a CPU register instead), so asking for their address with & is forbidden.

## Question 4
Why is "register" rarely used in modern C, even though K&R discusses it
as if it's important?
- Modern compilers usually optimize code better by themselves. Register is rarely used in modern C because modern compilers automatically optimize variable placement themselves — they're smart enough to figure out which variables are used frequently and keep them in fast storage without being told. When K&R was written, compilers needed the programmer's help to do this. Today, the compiler does it better on its own, making the register hint redundant and unnecessary.

## Question 5
True or False: register can only be used on local variables, never on
function parameters.
- F
Where register can be used:
local variables
function parameters