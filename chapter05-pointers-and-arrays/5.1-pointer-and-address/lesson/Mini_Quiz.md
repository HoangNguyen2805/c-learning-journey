**Q1.** Declare a pointer variable that points to an integer. What does the * mean in the declaration?
```c
    int *p;
```
- In a declaration, * means "this variable is a pointer to this type." It's part of the syntax that declares a pointer, not an operation. Once declared, using *p elsewhere (outside a declaration) means "dereference — go to that address and access the value."

**Q2.** If `int x = 10;` and `int *p = &x;`, what is the value of `*p`? And what does `&p` mean?
- Value of `*p` is 10. `&p` mean address of p to assign value to p.

**Q3.** Write code that changes the value of `x` (from Q2) by dereferencing the pointer `p`, without directly using the name `x`.
```c
    int x = 10;
    int *p = &x;

    *p = 100;      // dereference p and set the value to 100
    printf("%d\n", *p);   // prints 100
    printf("%d\n", x);    // also prints 100
```
changed x without using the name x — by dereferencing p (which points to x's address).

**Q4.** Why does `scanf("%d", &n)` need the `&`? What would happen without it?
- `&` mean way to get to the variable's address, with out `&` , we can't go in the location of n to replace the value with the assigned one.

**Q5.** What's the difference between `void *` and `int *`?
- `void *` is mean pointer point at any data type's value.
- `int *` is mean pointer point at integer's value.

**Q6.** If `p` and `&x` hold the same address (like in the example), and you do `*p = 500;`, what happens to `x`? Why?
- When you do *p = 500;, you're changing the value at the address p points to. Since p points to x's address, x becomes 500. Because *p and x refer to the same memory location — they're two different ways to access the same variable.

**Q7.** True or false: "A pointer always points to the same address once it's assigned." Explain.
- True. 

**Q8.** What does `(void *)&x` do? Why would you use it?
- Casting - if x is an integer, `(void *)&x` help x at that moment can be any data type, doesn't have to be integer.
- (void *)&x is a cast for printf. It tells printf "print this as a generic pointer address." Not about changing types permanently — just for that one printf call.