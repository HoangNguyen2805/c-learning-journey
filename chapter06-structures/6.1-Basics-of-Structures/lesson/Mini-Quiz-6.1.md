# Mini-Quiz 6.1 - Basics of Structures

1. What is the difference between declaring `struct point { int x; int y; };` and defining `struct point pt;`? Which one reserves memory?

2. In `struct point`, what is `point` called, and what is it for?

3. Write one line that defines a `struct point` named `origin` initialized to (0, 0).

4. `struct rect r;` contains two `struct point` members `pt1` and `pt2`. Write the expression for the y-coordinate of r's pt2.

5. List the four legal operations on a structure as a whole unit.

6. Why doesn't `if (a == b)` compile for two structs? How do you test equality instead?

7. After:
```c
struct point a = {5, 6};
struct point b = a;
a.x = 100;
```
what is `b.x`, and why?

8. Arrays can't be assigned with `=`, but structs can. What does struct assignment actually do under the hood?

9. What happens (syntactically) if you forget the semicolon after a struct declaration's closing brace, right before `int main()`?

10. When would you use a tagless struct `struct { ... } v;` instead of a tagged one? What can't you do later with the tagless version?
