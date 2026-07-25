# Mini-Quiz: Section 5.6 — From-Scratch Version

Keyed to the seven layers of `5.6-pointer-arrays-from-scratch.md`. If a question
stops you, the layer it came from is named — go back and reread that layer
rather than guessing.

Write your answers before checking anything. Answers are at the bottom.

---

## Layer 1 — a pointer is a variable

### 1.
```c
char c = 'A';
char *p = &c;
```

Three addresses are involved in those two lines, but only two variables exist.
Name the two variables, and say what each one holds.
- c hold 'A' and p hold address of c

### 2.
Why does it matter that `p` has its own address? What does that fact make
possible later in the section?
- p have it own address to store value of the other variable

---

## Layer 2 — a string is an address

### 3.
```c
char *s = "hello";
```

True or false, and explain: "`s` contains the text hello."
- false, it point at 'h' but helloe doesnt sit in s address.

### 4.
When `printf("%s", s)` runs, what does printf actually receive, and how does it
know when to stop printing?

---

## Layer 3 — an array of pointers

### 5.
Read this aloud in words, working outward from the name:
```c
char *words[3];
```
- three char size box in a row, each box can hold an address.

### 6.
Fill in the types:

| Expression | Type |
|---|---|
| `words` | ? |         words
| `words[1]` | ? |      is an array of 1
| `*words[1]` | ? |     pointers
| `words[1][2]` | ? |   to char
"words is an array of 3 pointers to char."

### 7.
The lesson says the array is contiguous but the strings are scattered. Which of
these are guaranteed to be next to each other in memory, and which are not?

- `&words[0]` and `&words[1]`
- `words[0]` and `words[1]`

---

## Layer 4 — why this is worth doing

### 8.
```c
char *temp;
temp = words[0];
words[0] = words[1];
words[1] = temp;
```

How many bytes of text does this copy? Explain your number.
- 2 bytes , first is [0] second is [1]

### 9.
Compare the two swap strategies. For an array of lines averaging 80 characters,
which costs more per swap, and by roughly what factor?

```c
/* strategy A */
temp = v[i];  v[i] = v[j];  v[j] = temp;

/* strategy B */
strcpy(temp, v[i]);  strcpy(v[i], v[j]);  strcpy(v[j], temp);
```

### 10.
Strategy B above has a second problem beyond speed. What is it? Think about what
`v[i]` has to be for `strcpy(v[i], v[j])` to be safe.

---

## Layer 5 — `char **`

### 11.
Explain, from the array-decay rule you already know, why these two are the same
declaration:

```c
void f(char *v[])
void f(char **v)
```

### 12.
```c
char *word = "hello";
char **wordp = &word;
```

Give the type and value of each:

- `wordp`
- `*wordp`
- `**wordp`

### 13.
If `char **` is "pointer to pointer to char", what would `char ***` be, and when
might you actually need one?

---

## Layer 6 — `*lineptr++`

### 14.
Unpack `*lineptr++` into its steps. Which operator binds tighter, is it prefix
or postfix, and what value reaches `printf`?

### 15.
```c
void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}
```

This function moves `lineptr` forward on every pass. Why does the caller's array
survive intact?

### 16.
Rewrite the function above using an index instead of pointer arithmetic. Which
version would you rather maintain, and why?

---

## Layer 7 — the program

### 17.
```c
while (fgets(line, MAXLEN, stdin) != NULL)
    lineptr[nlines++] = line;
```

This compiles. Describe exactly what the output looks like when you print all
the lines afterward, and draw or describe the memory picture that explains it.

### 18.
In `readlines`, what is the purpose of `line[len-1] = '\0'`? Name two things
that go wrong if you omit it.

### 19.
```c
p = malloc(strlen(line) + 1);
```

Why `+ 1`? What breaks without it, and would you notice immediately?

### 20.
This line compiles with no warning and sorts wrongly. What is it actually
comparing, and what order does the output come out in?

```c
if (v[i] < v[left])
    swap(v, ++last, i);
```

---

## Exercise From the Book

### [FROM K&R] Exercise 5-7
Rewrite `readlines` to store lines in an array supplied by `main`, rather than
calling `alloc` to maintain storage. How much faster is the program?

Two things to think about before writing it. First, the storage in `main` has a
different lifetime than storage from `malloc` — does that matter here? Second,
you gain one new way to fail that the malloc version did not have. What is it?

---

## Answers

### 1.
Two variables: `c`, holding the character `'A'`, and `p`, holding the address of
`c`. The three addresses are the address of `c`, the value stored in `p` (which
is that same address), and the address of `p` itself.

### 2.
Because a pointer is an ordinary variable, it can be stored in an array like any
other variable. That is the entire basis of `char *words[]` — you are making an
array out of something that happens to hold addresses.

### 3.
False. `s` contains an address. The text `hello` sits elsewhere in memory, and
`s` holds the address of its first byte.

### 4.
printf receives an address — the value of `s`. It follows that address and
prints bytes until it reaches a `\0`.

### 5.
"words is an array of 3 pointers to char." Work outward: `words`, then
`words[3]` an array of 3, then `*words[3]` of pointers, then `char *words[3]`
to char.

### 6.
| Expression | Type |
|---|---|
| `words` | `char **` when it decays; formally an array of 3 `char *` |
| `words[1]` | `char *` |
| `*words[1]` | `char` |
| `words[1][2]` | `char` |

### 7.
`&words[0]` and `&words[1]` are guaranteed adjacent — they are elements of one
array, exactly `sizeof(char *)` apart. `words[0]` and `words[1]` are addresses
of separate strings that could be anywhere, with no guaranteed relationship.

### 8.
Zero bytes of text. It copies three pointer values — 24 bytes total on a 64-bit
machine — and touches no character data at all.

### 9.
Strategy A copies 8 bytes three times: 24 bytes. Strategy B copies about 80
bytes three times: roughly 240 bytes, plus the loop overhead inside each
`strcpy`. Order of magnitude worse, and it gets worse still as lines get longer,
while A stays fixed.

### 10.
`strcpy(v[i], v[j])` writes into whatever `v[i]` points at. For that to be safe,
every allocation must be big enough to hold the longest string in the array — so
you are forced into fixed-size storage, wasting space on short lines and
breaking on long ones. That is the "complicated storage management" K&R
mentions.

### 11.
An array parameter is always converted to a pointer to its first element. The
first element of `char *v[]` is a `char *`. A pointer to a `char *` is written
`char **`. So the conversion produces exactly the second declaration.

### 12.
- `wordp` is `char **`, holding the address of the variable `word`
- `*wordp` is `char *`, the address of "hello"
- `**wordp` is `char`, the value `'h'`

### 13.
`char ***` is a pointer to a pointer to a pointer to char. You would need one to
pass a `char **` to a function that must modify it — for example, a function
that grows an array of strings and has to hand back a new base address.

### 14.
`++` binds tighter than `*` and it is postfix. So: take the current value of
`lineptr`; dereference that value to get the `char *` it points at; hand that to
printf; then advance `lineptr` one element forward. printf receives the pointer
as it was *before* the increment.

### 15.
`lineptr` is a parameter, which means the function received a copy of the
caller's pointer. Incrementing the copy does not touch the original array or the
caller's variable.

### 16.
```c
void writelines(char *lineptr[], int nlines)
{
    int i;

    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}
```
Both are correct. The index version is easier for most readers to verify at a
glance; the pointer version is idiomatic C and demonstrates that the parameter
really is a pointer. Preference is legitimate either way — but if you have to
pause and work out what `*lineptr++` does, that is a signal about which one your
future self will prefer.

### 17.
Every entry prints the same text: whatever the last line read happened to be.
`line` is a single buffer, reused on every iteration, so every element of
`lineptr` holds the same address. All the arrows point at one box, and that box
holds only the most recent line.

### 18.
`fgets` keeps the newline it read, so the stored string ends `...\n\0`. The
assignment overwrites the `\n` with `\0`. Omit it and (a) every line prints with
an extra blank line after it, and (b) `strcmp` compares the newline characters
too, which can change the sort order for lines that are prefixes of each other.

### 19.
`strlen` counts characters up to but not including the terminating `\0`. The
allocation needs room for that byte as well. Without the `+ 1`, `strcpy` writes
one byte past the end of the allocation — a heap overflow. You would very likely
*not* notice immediately; it often appears to work and corrupts something else
later, which is what makes it dangerous.

### 20.
It compares two `char *` values — memory addresses, not text. The array ends up
sorted by where each string happens to sit in memory. For string literals that
usually tracks source order; for malloc'd lines it usually tracks input order.
Either way it is a silent wrong answer with no diagnostic.
