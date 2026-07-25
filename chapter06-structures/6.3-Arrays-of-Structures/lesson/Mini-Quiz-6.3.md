# Mini-Quiz 6.3 - Arrays of Structures

1. What problem do arrays of structures solve compared to "parallel arrays"? Give the failure mode of parallel arrays.

2. Write the initializer for a 3-row `struct key` array holding ("do",0), ("for",0), ("if",0).

3. Explain each part of: `#define NKEYS (sizeof keytab / sizeof keytab[0])`. Why does it self-update when rows are added?

4. What type does `sizeof` produce, and which printf conversion prints it portably?

5. In `keytab[mid].word`, which operator applies first and why? What precedence group do `[]` and `.` share?

6. Binary search on keytab requires what precondition on the data? What happens if one row is out of order?

7. Compare linear vs binary search for the keyword table: give time complexities and state roughly how many comparisons each needs for 32 keywords (worst case).

8. Why can `sizeof(struct key)` be greater than `sizeof(char*) + sizeof(int)`?

9. In the book's getword, why does the function return the character itself when input doesn't start with a letter?

10. (Code prediction) `struct score a[2] = {{"x",1},{"y",2}}; a[0] = a[1];` — legal? What is `a[0].name` afterward, and why does this work even though arrays normally can't be assigned?
