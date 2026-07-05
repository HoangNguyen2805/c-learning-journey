/*
Practice 4.11.3 - Macro-based Utility Functions

Problem:
Write a single-file program that:
1. Define function-like macros for: max, min, square, abs, swap
2. Test them with various inputs and edge cases
3. Compare macro results with actual function implementations
4. Use #ifdef DEBUG to conditionally print debug output

This practices:
- Function-like macros with proper parentheses
- Testing macros with expressions
- Conditional compilation (#ifdef)
- Edge cases and gotchas with macros
*/

#include <stdio.h>

#define DEBUG

// Define your macros here
// #define max(a, b) ...
#define max(a, b) ((a) > (b) ? (a) : (b))
// #define min(a, b) ...
#define min(a, b) ((a) < (b) ? (a) : (b))
// #define square(x) ...
#define square(x) ((x) * (x))
// #define abs(x) ...
#define abs(x) ((x) < 0 ? -(x) : (x))
// #define swap(a, b) ... (tricky!)
#define swap(a, b) ((a = b) && (b == a)) // or #define swap(a, b) ((a) ^= (b), (b) ^= (a), (a) ^= (b))
/*
With a = 5, b = 3:
Step 1: int temp = a; → temp = 5 (save the original a)
Step 2: a = b; → a = 3 (now a has b's value)
Step 3: b = temp; → b = 5 (now b has the original a, which we saved in temp)
Result: a = 3, b = 5 ✓ (swapped correctly)
The key is: you MUST save a FIRST (temp = a) before you overwrite it with b.
*/
// Actual functions (for comparison)
int max_func(int a, int b) {
    return a > b ? a : b;
}

int min_func(int a, int b) {
    return a < b ? a : b;
}

int square_func(int x) {
    return x * x;
}

int abs_func(int x) {
    return x < 0 ? -x : x;
}

// No Function at least before chapter 5 can do swap.
/*
Swap with pointer (not learn until chapter 5):
void swap_func(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
*/
int main() {
    int a = 5, b = 3;
    
#ifdef DEBUG
    printf("=== Testing Macros vs Functions ===\n\n");
#endif
    
    // Test max macro vs function
    printf("max(5, 3) macro = %d, function = %d\n", max(a, b), max_func(a, b));
    printf("max(-10, -2) macro = %d, function = %d\n", max(-10, -2), max_func(-10, -2));
    
    // Test min macro vs function
    printf("min(5, 3) macro = %d, function = %d\n", min(a, b), min_func(a, b));
    
    // Test square macro with expressions (test parentheses!)
    printf("square(5) macro = %d, function = %d\n", square(a), square_func(a));
    printf("square(2 + 3) macro = %d, function = %d\n", square(2 + 3), square_func(2 + 3));
    
    // Test abs macro
    printf("abs(-10) macro = %d, function = %d\n", abs(-10), abs_func(-10));
    printf("abs(7) macro = %d, function = %d\n", abs(7), abs_func(7));

    // Test swap macro
    int x = 5, y = 3;
    printf("Before swap: x = %d, y = %d\n", x, y);
    swap(x, y);
    printf("After swap: x = %d, y = %d\n", x, y);
    
    return 0;
}

/*
## Why functions can't swap (without pointers)

### The Problem

If you try to write a swap function:

```c
void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

int x = 5, y = 3;
swap(x, y);        // Does this swap x and y?
printf("%d %d\n", x, y);  // Still prints: 5 3 (NOT swapped!)
```

**Why doesn't it work?**

When you call `swap(x, y)`, the function receives **copies** of `x` and `y`, not the original variables.

```text
Original variables:     Function receives:
x = 5                   a = 5 (copy of x)
y = 3                   b = 3 (copy of y)
```

The function swaps `a` and `b` (the copies), but the original `x` and `y` remain unchanged.

### The Solution: Pointers (Chapter 5)

Pointers allow functions to modify the **original** variables, not copies. That's why you need pointers for swap:

```c
void swap(int *a, int *b) {  // pointers
    int temp = *a;
    *a = *b;
    *b = temp;
}
```

But pointers are Chapter 5 material, so we'll come back to this.

### Why macros work for swap

Macros do **text substitution**, not function calls. So:

```c
#define swap(a, b) { int temp = a; a = b; b = temp; }

int x = 5, y = 3;
swap(x, y);  // This expands to the macro code directly on x and y
// x and y ARE actually swapped
```

The macro directly modifies `x` and `y` — no copies involved.

This is one reason **macros can be powerful but dangerous** — they bypass normal function rules.
*/