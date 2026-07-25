# Mini-Quiz: Section 5.7 — Multi-dimensional Arrays

**Q1:** Given `int a[3][4];`, how many integers are allocated?
- A) 3
- B) 4  
- C) 7
- D) 12

**Q2:** If you want to pass `int a[3][4]` to a function, which is **NOT** valid?
- A) `void f(int a[3][4]) { }`
- B) `void f(int a[][4]) { }`
- C) `void f(int a[3][]) { }`
- D) `void f(int (*a)[4]) { }`

**Q3:** In a 2D array declared `char data[5][10]`, elements are stored in _____ order (the rightmost subscript varies fastest).
- A) column-major
- B) row-major
- C) random
- D) backwards

**Q4:** What does `daytab[leap][i]` access in K&R's date example?
- A) days in month `i` of year `leap`
- B) the leap year indicator
- C) days in month `i`, adjusted for leap years by row
- D) undefined behavior

**Q5:** If a 2D array is initialized like:
```c
int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
```
what is `a[1][2]`?
- A) 3
- B) 5
- C) 6
- D) undefined

**Q6:** When passing a 2D array to a function, which dimension can be omitted?
- A) The first (rows)
- B) The second (columns)
- C) Both
- D) Neither

**Q7:** What is the size in bytes of `int matrix[5][4]` on a system where `int` is 4 bytes?
- A) 20
- B) 40
- C) 80
- D) 100

**Q8:** In a 2D array, the formula for accessing element `[i][j]` is:
- A) base + i + j
- B) base + (i * cols + j) * sizeof(element)
- C) base + j * i
- D) depends on the compiler

**Q9:** Why does `daytab[0][0]` start with 0 (padding) in K&R's example?
- A) it's a bug
- B) to make month numbers 1-12 instead of 0-11
- C) to align memory
- D) no particular reason

**Q10:** If you declare `int a[2][3][4]`, how many dimensions does this array have?
- A) 2
- B) 3
- C) 4
- D) 9

---

## Answer Key (For Self-Check)

1. **D** (3 × 4 = 12)
2. **C** (first dimension can be omitted, not the others)
3. **B** (row-major order)
4. **C** (days in month `i`, with row indicating leap year)
5. **C** (a[1][2] is 6)
6. **A** (first dimension can be omitted)
7. **C** (5 × 4 × 4 = 80 bytes)
8. **B** (classic row-major calculation)
9. **B** (allows natural 1-12 month indexing)
10. **B** (three dimensions: 2, 3, and 4)
