# Mini-Quiz: Section 5.9 — Pointers vs. Multi-dimensional Arrays

**Q1:** Given:
```c
int a[10][20];    /* declaration 1 */
int *b[10];       /* declaration 2 */
```
How much memory is allocated for each **at compile time**?
- A) Both allocate 200 ints
- B) Declaration 1 allocates 200 ints; declaration 2 allocates 10 pointers
- C) Both allocate just 10 pointers
- D) Neither allocates anything until runtime

**Q2:** In `int a[10][20]`, what must a function receiving it know to calculate addresses?
- A) only the number of rows (10)
- B) only the number of columns (20)
- C) both rows and columns
- D) neither; it can figure it out

**Q3:** With `int *b[10]`, the rows can have:
- A) different lengths
- B) the same length (must be 20)
- C) no elements until initialized
- D) unpredictable lengths

**Q4:** When you access `b[i][j]` on a pointer array `int *b[10]`, this means:
- A) calculate row stride from a fixed column count
- B) dereference `b[i]` to get a pointer, then offset by `j`
- C) access a contiguous 2D block
- D) undefined behavior

**Q5:** For storing variable-length strings efficiently, which is better?
- A) `char strings[100][50]` (2D array)
- B) `char *strings[100]` (pointer array)
- C) both are equally good
- D) depends on the alphabet used

**Q6:** The key difference between `int a[10][20]` and `int *b[10]` is:
- A) they use the same memory layout
- B) `a` is contiguous; `b` is not initialized and rows can vary
- C) `b` is faster
- D) `a` can only store 10 elements

**Q7:** How is `a[i][j]` calculated for a true 2D array?
- A) `*(a + i * j)`
- B) `*(a + i * cols + j)` where `cols` is known
- C) `a[i] + j` (array addition)
- D) implementation-dependent

**Q8:** How is `b[i][j]` calculated for a pointer array?
- A) `*(b + i * cols + j)`
- B) `*(*(b + i) + j)` (double dereference)
- C) same as 2D array
- D) not predictable

**Q9:** Which scenario requires a pointer array, not a 2D array?
- A) storing 100 integers in a 10×10 grid
- B) storing month names of different lengths (Jan, February, Mar...)
- C) storing exam scores for 30 students, 5 exams each
- D) storing a chess board (8×8)

**Q10:** If you want to pass `int a[10][20]` to a function, and you omit the column count, what happens?
- A) the compiler adjusts automatically
- B) compilation succeeds but gives wrong results at runtime
- C) compilation fails (error)
- D) the function only receives the first element

---

## Answer Key (For Self-Check)

1. **B** (true 2D allocates 200 ints; pointer array allocates 10 pointers only)
2. **B** (needs column count to calculate row stride)
3. **A** and **C** (rows can differ in length, must be initialized manually)
4. **B** (dereference pointer, then offset)
5. **B** (pointer array saves memory)
6. **B** (`a` is contiguous; `b` is flexible and uninitialized)
7. **B** (classic row-major calculation)
8. **B** (double dereference through pointer array)
9. **B** (strings of different lengths need flexibility)
10. **C** (compilation fails without column count)
