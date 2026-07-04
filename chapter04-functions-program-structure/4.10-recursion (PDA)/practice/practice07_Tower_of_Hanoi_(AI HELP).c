/*
### Problem 7 - Tower of Hanoi (stretch problem, optional but recommended)

This is the single most famous recursion teaching problem in all of CS,
and a genuine DSA classic. If you want the "this is why recursion
matters" moment, do this one.

Rules: 3 pegs (A, B, C), `n` disks stacked on peg A (largest at bottom).
Move all disks to peg C, one at a time, never placing a larger disk on
top of a smaller one.

Write:
```c
void hanoi(int n, char from, char to, char aux);
```
that prints each move, like: `Move disk 1 from A to C`.

**Don't look up the solution.** Instead, think about it this way before
coding:

- If you only had **1 disk**, what's the move? (base case)
- If you had `n` disks, and you *pretend* you already know how to solve
  the `n - 1` disk version (the "leap of faith" from earlier) — what
  3-step plan would get all `n` disks from `from` to `to`, using `aux`
  as a helper peg?

Write that 3-step plan in English first, as a comment, before writing
any code.

Test with `hanoi(3, 'A', 'C', 'B')` — predict how many total moves it
should take before running (there's a clean formula, but it's fine to
just count by simulating it on paper with 3 disks if you don't know the
formula).
*/

/*
To move n disks from 'from' to 'to' using 'aux':
- Step 1: Move (n-1) disks from 'from' to 'aux' (using 'to' as helper)
- Step 2: Move the largest disk from 'from' to 'to'
- Step 3: Move (n-1) disks from 'aux' to 'to' (using 'from' as helper)

so
1. Function signature: void hanoi(int n, char from, char to, char aux);
2. Base case: if n == 1, print the move
3. Recursive case (3 steps):
    Step 1: recursive call to move n-1 disks from from to aux
    Step 2: print moving the largest disk from from to to
    Step 3: recursive call to move n-1 disks from aux to to

In main(): just call hanoi(3, 'A', 'C', 'B') and count the moves printed.

Visualize:
hanoi(3, 'A', 'C', 'B'):
  Step 1: Move 2 disks from A to B
    hanoi(2, 'A', 'B', 'C'):
      Step 1: Move 1 disk from A to C
        hanoi(1, 'A', 'C', 'B'): Print "Move disk from A to C"
      Step 2: Print "Move disk from A to B"
      Step 3: Move 1 disk from C to B
        hanoi(1, 'C', 'B', 'A'): Print "Move disk from C to B"
  Step 2: Print "Move disk from A to C"
  Step 3: Move 2 disks from B to C
    hanoi(2, 'B', 'C', 'A'):
      Step 1: Move 1 disk from B to A
        hanoi(1, 'B', 'A', 'C'): Print "Move disk from B to A"
      Step 2: Print "Move disk from B to C"
      Step 3: Move 1 disk from A to C
        hanoi(1, 'A', 'C', 'B'): Print "Move disk from A to C"

The printed moves in order:

1. Move disk from A to C
2. Move disk from A to B
3. Move disk from C to B
4. Move disk from A to C
5. Move disk from B to A
6. Move disk from B to C
7. Move disk from A to C

Total: 7 moves
*/

#include <stdio.h>
#include <string.h>

// Arrays to represent the 3 pegs (storing disk sizes)
int pegA[100], pegB[100], pegC[100];
int countA = 0, countB = 0, countC = 0;

// Function to display current state of all pegs
void displayPegs() {
    printf("\nPeg A: ");
    for (int i = 0; i < countA; i++) printf("%d ", pegA[i]);
    if (countA == 0) printf("(empty)");
    
    printf("\nPeg B: ");
    for (int i = 0; i < countB; i++) printf("%d ", pegB[i]);
    if (countB == 0) printf("(empty)");
    
    printf("\nPeg C: ");
    for (int i = 0; i < countC; i++) printf("%d ", pegC[i]);
    if (countC == 0) printf("(empty)");
    
    printf("\n");
}

// Function to move a disk from one peg to another
void moveDisk(char from, char to) {
    int disk;
    
    // Remove disk from source peg
    if (from == 'A') disk = pegA[--countA];
    else if (from == 'B') disk = pegB[--countB];
    else disk = pegC[--countC];
    
    // Add disk to destination peg
    if (to == 'A') pegA[countA++] = disk;
    else if (to == 'B') pegB[countB++] = disk;
    else pegC[countC++] = disk;
    
    printf("Move disk %d from %c to %c\n", disk, from, to);
    displayPegs();
}

// Recursive hanoi function
void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        moveDisk(from, to);
    } else {
        hanoi(n-1, from, aux, to);
        moveDisk(from, to);
        hanoi(n-1, aux, to, from);
    }
}

int main() {
    int n;
    printf("Tower of Hanoi - Enter number of disks: ");
    scanf("%d", &n);
    
    // Initialize pegA with disks (largest at bottom)
    for (int i = n; i >= 1; i--) {
        pegA[countA++] = i;
    }
    
    printf("\n=== Starting State ===\n");
    displayPegs();
    
    printf("\n=== Solving Tower of Hanoi ===\n");
    hanoi(n, 'A', 'C', 'B');
    
    printf("\n=== Puzzle Solved! ===\n");
    
    return 0;
}