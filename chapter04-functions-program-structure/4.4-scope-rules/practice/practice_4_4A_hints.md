# Practice 4.4A - Hints

<details>
<summary>HINT - How fib(int n) should work internally (iterative, no arrays)</summary>

You need the Nth Fibonacci number, where fib(1)=1, fib(2)=1, fib(3)=2, etc.

You only need to remember the last TWO numbers at any point - not the
whole sequence (which is why you don't need an array yet):

```c
int fib(int n) {
    int a = 1;   // represents fib(1)
    int b = 1;   // represents fib(2)
    int next;
    int i;

    if (n == 1 || n == 2) {
        return 1;
    }

    for (i = 3; i <= n; i++) {
        next = a + b;
        a = b;
        b = next;
    }

    return b;
}
```

Walk through this by hand for n=5 before trusting it - confirm it gives 5.

</details>

<details>
<summary>HINT - main()'s loop structure</summary>

```c
int main() {
    int n;   // LOCAL n - how many the user wants

    printf("Enter how many Fibonacci numbers to generate: ");
    scanf("%d", &n);

    printf("Fibonacci sequence:\n");

    int i;
    for (i = 1; i <= n; i++) {
        printf("%d\n", fib(i));
        n_increment_here;   // <- think about this carefully
    }

    printf("Total Fibonacci numbers generated: %d\n", n /* which n? */);

    return 0;
}
```

Careful: inside main(), does writing just "n" refer to the local n or
the external n? Why? (Reread the shadowing section of your 4.4 lesson.)

</details>

<details>
<summary>EXPLANATION - The actual trap this practice sets</summary>

Because main() declares its OWN local "n", main() can NEVER directly
touch the external "n" by just writing "n" inside main() - the local
one always wins (shadows it) for the entire body of main().

This means: if the requirement is "increment the EXTERNAL n counter,"
and you're inside main() where local n already shadows it... you have
a real problem. You need a way to reach the external n specifically.

Think about this: is there a function (other than main) where writing
just "n" WOULD correctly refer to the external one? What would that
function need to look like, and where would you call it from inside
main()'s loop?

This is the entire point of the exercise - realizing that once a local
variable shadows an external one, you can't just "reach past" it from
inside that same function. You need a different function whose body
doesn't redeclare n.
</details>