# Mini-Quiz 6.7 - Typedef

1. Does `typedef int Length;` create a new type? What exactly does it create? Can a `Length` and an `int` be assigned to each other?

2. What's the mental trick for reading any typedef? (Hint: pretend the keyword isn't there — what would the declaration declare?)

3. After `typedef char *String;`, what are the types of `a` and `b` in `String a, b;`? Contrast with `#define String char *` followed by `String a, b;`.

4. Write a typedef making `Comparator` mean "pointer to function taking two `void*` and returning int". Then declare an array `cmps` of 5 Comparators.

5. In the book's Treenode typedef, why must the struct still carry the tag `tnode` even though we typedef a name for it?

6. Name the two purposes K&R gives for typedef, with one example each.

7. `typedef int Row[4];` — what is `Row m[3];`? Give its total element count and what `sizeof(Row)` equals in terms of sizeof(int).

8. Which tool processes typedef, and which processes #define? Why does that make typedef "smarter"?

9. Standard library names like `size_t` and `ptrdiff_t` are typedefs. What problem does that solve when code moves between platforms?

10. (Code reading) Is this legal? What is `x`?
```c
typedef struct { int a; } Anon;
Anon x = { 5 };
```
What can't you do with this struct that a tagged one allows? (Think: self-reference.)
