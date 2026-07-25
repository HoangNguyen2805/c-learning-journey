# Mini-Quiz 6.9 - Bit-fields

1. Why must flag mask values be powers of two? What breaks if STATIC were 03 instead of 04?

2. Write the three mask idioms on variable `f` for flag `X`: set it, clear it, test it.

3. Declare a struct with three 1-bit fields named `read`, `write`, `exec`. Why should each be `unsigned int` rather than plain `int`?

4. A 6-bit unsigned field can hold what range of values? What does storing 64 into it produce?

5. What does an unnamed field like `unsigned : 3;` do? And width `: 0`?

6. List three things about bit-fields that K&R says are implementation-dependent.

7. Why is `&flags.is_extern` illegal? What consequence does this have for functions like scanf?

8. You must parse a network packet header where bytes/bits are defined by an RFC. Masks or bit-fields — which and why?

9. How many bytes would you EXPECT `struct { unsigned a:5; unsigned b:4; unsigned c:12; }` to occupy on a 32-bit-int machine, and why can't you be certain?

10. (Prediction) A date struct packs day:5, month:4, year:12. Storing day=31, month=12, year=2026 — do all three fit? Show the max each field allows.
