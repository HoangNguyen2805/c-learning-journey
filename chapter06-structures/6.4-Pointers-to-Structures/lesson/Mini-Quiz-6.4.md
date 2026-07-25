# Mini-Quiz 6.4 - Pointers to Structures

1. The pointer version of binsearch returns `struct key *`. What value signals "not found", and why is it a better sentinel than -1 was for indices?

2. Why is `mid = (low + high) / 2` illegal for pointers, while `mid = low + (high-low)/2` is fine? Name the two legal pointer-arithmetic operations involved.

3. What is special about `&tab[n]`? What may you do with it, and what must you never do?

4. If `sizeof(struct key)` is 16, how many bytes does `p++` advance when `p` is a `struct key *`? What does `high - low` measure — bytes or structs?

5. Rewrite this index loop as a pointer loop:
```c
for (i = 0; i < NKEYS; i++)
    if (keytab[i].count > 0)
        printf("%d %s\n", keytab[i].count, keytab[i].word);
```

6. Predict the state after each line (`p` starts at row 0, counts all 0):
```c
++p->count;
(++p)->count;
p++->count;
```
Where is p, and which counts changed?

7. What does `*p->word` fetch? And `*p->word++` — which pointer moves?

8. In the loop `while (low < high)` with `high = mid` on the less-than branch: why `mid` and not `mid - 1`? What range convention is in play?

9. Why might `sizeof(struct key)` exceed the sum of its members' sizes? What is this called?

10. Give one advantage of the pointer version over the index version of binsearch, and one situation where you'd still prefer indices.
