# Mini-Quiz: Section 5.8 — Initialization of Pointer Arrays

**Q1:** Given:
```c
static char *name[] = {"Jan", "Feb", "Mar"};
```
What is the type of `name[1]`?
- A) `char`
- B) `char *`
- C) `char **`
- D) `int`

**Q2:** How does the compiler determine the size of `static char *names[] = {...}`?
- A) from the first initializer
- B) by counting initializers in braces
- C) it cannot; you must specify size
- D) it's always 255

**Q3:** When you write:
```c
char *p = month_name(3);
```
and `month_name` returns `name[3]`, what is `p` pointing to?
- A) the pointer stored in `name[3]`
- B) the first character of the month name
- C) the address of `name[3]` itself
- D) garbage

**Q4:** The `static` keyword in `static char *name[]` ensures:
- A) the array is read-only
- B) the array is only accessible within this function
- C) the array is initialized only once
- D) the array cannot be modified

**Q5:** What is the main advantage of using `char *name[]` over `char name[][15]`?
- A) faster access
- B) simpler syntax
- C) saves memory (no wasted space)
- D) more type-safe

**Q6:** In the declaration `static char *name[] = {"January", "February", ...};`, where are the actual strings stored?
- A) in the `name` array
- B) in read-only memory (string literal pool)
- C) on the stack
- D) in a separate malloc'd block

**Q7:** What is `*name[0]` (dereference of first element)?
- A) the first element of the array
- B) the first character of the first string
- C) the entire first string
- D) undefined

**Q8:** If `month_name(13)` is called and 13 is invalid, the function should:
- A) crash
- B) return NULL
- C) return `name[0]` ("Illegal month")
- D) undefined behavior is OK

**Q9:** How much memory does `static char *months[12]` allocate (assuming 8-byte pointers)?
- A) 96 bytes (12 × 8 bytes for pointers)
- B) varies (depends on string lengths)
- C) unknown without knowing the strings
- D) 12 × 255 bytes

**Q10:** Which is a correct use of `month_name`?
- A) `month_name(6)` returns a string starting with 'J'
- B) `month_name(0)` returns an error
- C) `month_name` modifies its internal array
- D) `month_name` allocates new memory each time

---

## Answer Key (For Self-Check)

1. **B** (name[1] is `char *`)
2. **B** (compiler counts initializers)
3. **B** (points to first char of month name)
4. **C** (initialized once, reused)
5. **C** (saves memory, no wasted space)
6. **B** (in read-only string literal pool)
7. **B** (dereference gives first char)
8. **C** (returns "Illegal month")
9. **A** (96 bytes for pointers only; strings are elsewhere)
10. **A** (month_name(6) returns "June")
