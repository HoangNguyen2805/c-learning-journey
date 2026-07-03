**Q1.** In your own words, what is a "base case" and why must every
recursive function have one (or a way to eventually reach one)?
- Base case is PDA (Push Down Automaton) is like the bottom of the stack where the the stack will not touch when push (stacking) and pop (unstack) from the top, but when we unstack all it reach the bottom stack andthat mean it meat the condition to stop stacking or stop the program create infinity loop.
    A base case is the condition in a recursive function that stops it from calling itself again — instead, it just does its work and returns directly.
    Every recursive function needs one because without it, the function keeps calling itself forever, piling up more and more calls on the stack, until the stack runs out of room and the program crashes (stack overflow).

**Q2.** What's the difference between how `countdown` pops off the stack
versus how `factorial` pops off the stack? (Hint: what is each one
"holding" when it pauses?)
- countdown: when it calls countdown(n-1), that's the very last thing in the function. Once countdown(n-1) returns, there's nothing left to do — countdown(3) just ends. So while it's paused waiting, it's not "holding onto" anything — no pending calculation, no leftover work.
factorial: when it calls factorial(n-1), it's inside the expression n * factorial(n-1). Once factorial(n-1) returns a value, factorial(3) still has to multiply that result by its own n (3) before it can return. So while it's paused, factorial is holding onto something — its own value of n, waiting to multiply it against whatever comes back.
That's the difference: countdown pops off the stack with nothing left to do (this pattern is called tail recursion). factorial has to wait, do one more piece of work (the multiplication), and then pop — it's holding a pending operation on the stack the whole time it's paused.

**Q3.** True or false, and explain why: "The order in which recursive
calls finish is always the same as the order in which they were called."
- False. "Last called, first finished" (the palindrome/LIFO pattern) only holds true for calls that are directly waiting on each other — a parent and the single child it's currently paused on, like in countdown or factorial, where each call makes exactly one next call. In that case, it really is a straight chain, so call order and finish order are exact opposites.
But it breaks down for branching recursion like weird, where a call makes two sibling calls instead of one. Siblings aren't waiting on each other — the left branch fully calls, finishes, and pops off the stack before the right branch is even called. So a call made later (the right sibling) does not necessarily finish before a call made earlier (the left sibling) — they're not even overlapping in time. The reversal rule only applies locally, along a single parent-child path, not globally across the whole call tree.

**Q4.** What specifically causes a stack overflow in a recursive
function? Be precise — not just "too much recursion," but *what's
actually running out*.
- Say countdown has no base case (or the base case is broken/unreachable), like:
cvoid countdown(int n) {
    printf("%d\n", n);
    countdown(n - 1);   // no check for n <= 0, keeps going forever
}
Call countdown(5). Here's what piles up on the stack:
countdown(5)  <- frame stores n=5, plus the "return here" address
  countdown(4)  <- frame stores n=4, plus return address
    countdown(3)  <- frame stores n=3, plus return address
      countdown(2)
        countdown(1)
          countdown(0)
            countdown(-1)
              countdown(-2)
                ... keeps going, n never stops decreasing
None of these calls can pop off the stack, because none of them ever return — each one is stuck waiting on the next one, which is waiting on the next one, forever. Every new call adds another frame (a small block of memory holding that call's n, its return address, any local variables) on top of the stack.
The stack has a fixed size — say, a few megabytes. Each frame might be a few dozen bytes. So after roughly hundreds of thousands of nested calls (the exact number depends on frame size and stack size), there's no more room to add another frame. At that point, the OS/runtime detects the stack has exceeded its bounds and the program crashes with a stack overflow error — you might see something like Segmentation fault in C.
So specifically: what runs out is the memory reserved for the call stack, and why it runs out is that each unreturned recursive call permanently occupies a stack frame, and without a reachable base case, no frames ever get freed — they only accumulate.

**Q5.** For this function:
```c
int weird(int n) {
    if (n <= 0)
        return 0;
    return weird(n - 1) + weird(n - 1);
}
```
Without running it — how many total calls does `weird(3)` make
(including itself)? Does this recursion "branch" like `countdown` and
`factorial` did, or is it different? Explain the shape.
- if (3-1)+(3-1) = 2 + 2 = 4, and but that doesnt me return wierd (2) + weird (2); make n = 4, NO , its just return value 4 and then weird (1) + weird (1) then weird (0) + weird (0) meet condition and stop there, return 0. Only when it reach weird (0) + weird (0) then It'll start the additon return.
weird(3)
├── weird(2)
│   ├── weird(1)
│   │   ├── weird(0)
│   │   └── weird(0)
│   └── weird(1)
│       ├── weird(0)
│       └── weird(0)
└── weird(2)
    ├── weird(1)
    │   ├── weird(0)
    │   └── weird(0)
    └── weird(1)
        ├── weird(0)
        └── weird(0)

Let's recount together — count level by level from your own diagram:

Level 0 (top): weird(3) → how many nodes is that?
Level 1: weird(2), weird(2) → how many?
Level 2: weird(1), weird(1), weird(1), weird(1) → how many?
Level 3 (bottom): all the weird(0) nodes → count them in your diagram

-> 1+2+4+8 = 15 function call total to push or stack.
Each call makes  2 next calls, so it forms a tree instead of a chain