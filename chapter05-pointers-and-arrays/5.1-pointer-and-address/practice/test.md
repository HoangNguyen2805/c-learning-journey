Good question — that tests understanding.
If you do:
```c
int x = 5, y = 10;
int *a = &x;
int *b = &y;

x = 100;  // change x
y = 200;  // change y

printf("%d %d\n", *a, *b);  // what prints?
```
What do you think *a and *b print? Why?

answer = a is 100 and b is 200

Verifying pointer dereferencing and memory alignment conceptsVerifying pointer dereferencing and memory alignment concepts
Exactly right! ✅

Because *a means "go to the address a points to and get the value" — and that address is where x lives. So when x changes to 100, *a shows 100.

This is the key insight for the swap function: *a and *b always reflect the current values at those addresses.

Now write the swap function. You already have the right idea with temp. Just use *a and *b to access and modify the values at those addresses.

Try it.