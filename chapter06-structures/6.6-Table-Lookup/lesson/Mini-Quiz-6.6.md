# Mini-Quiz 6.6 - Table Lookup

1. Describe the overall shape of hashtab: what is the array made of, and what hangs off each slot?

2. Walk through `hash("hi")` by hand with the 31-multiplier formula (use ASCII h=104, i=105; you may leave the final % HASHSIZE symbolic).

3. Why is hash's return type `unsigned`, and what would risk breaking if it were plain `int`?

4. What is a collision, and how does this design resolve it? What's the alternative name for this strategy?

5. In install, why does the code call lookup FIRST before allocating anything?

6. Explain the two lines that push a new node onto a chain:
```c
np->next = hashtab[hashval];
hashtab[hashval] = np;
```
Why would swapping their order destroy the chain?

7. When install finds an existing name, it frees `np->defn` but NOT `np->name`. Why is each choice correct?

8. Give the average and worst-case complexity of lookup, and what data condition triggers the worst case.

9. Hash table (6.6) vs BST (6.5): name one operation the BST supports naturally that the hash table cannot, and one metric where the hash table wins.

10. For undef (deletion), why must you track a `prev` pointer while walking the chain? What special case does `prev == NULL` represent?
