# Mini-Quiz 6.5 - Self-referential Structures

1. Why is `struct tnode { struct tnode next; }` illegal but `struct tnode { struct tnode *next; }` fine? Think about sizes.

2. State the BST invariant. For the insert sequence "now", "is", "the", "time" — draw (in text) the resulting tree.

3. In addtree, why does the caller write `p->left = addtree(p->left, w)` instead of just calling `addtree(p->left, w)`? What case makes the assignment essential?

4. `root` must start as what value, and what does the first addtree call do with it?

5. Why does in-order traversal (left, self, right) of a BST print words in alphabetical order? What order would (self, left, right) give?

6. Why must addtree store `mystrdup(w)` rather than `w` itself, given how getword works?

7. What are the two things `mystrdup` must do, and why is the `+1` in `malloc(strlen(s)+1)` critical?

8. What input pattern turns the BST into an O(n)-per-operation structure? Describe the resulting shape.

9. treefree must free children BEFORE the parent (post-order). What goes wrong with pre-order freeing?

10. (Complexity) With n distinct words: give best-case and worst-case time to build the whole tree, and the space used by the tree itself.
