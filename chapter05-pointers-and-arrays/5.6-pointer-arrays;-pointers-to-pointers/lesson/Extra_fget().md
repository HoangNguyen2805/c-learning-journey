# fgets — Borrowed From Chapter 7

This function belongs to Section 7.7, "Line Input and Output." Practice 5.6.3
needs it two chapters early, so this file covers just enough to use it. The
full treatment — `FILE *`, `fopen`, `fclose`, reading from actual files — waits
for Chapter 7.

---

## The signature

```c
char *fgets(char *line, int maxline, FILE *fp)
```

K&R's description: fgets reads the next input line, including the newline, from
file `fp` into the character array `line`, reading at most `maxline-1`
characters, and terminating the result with `'\0'`.

Three arguments:

| Argument | What it is |
|---|---|
| `line` | your buffer — where the text lands |
| `maxline` | the buffer's size, so fgets cannot overrun it |
| `fp` | where to read from |

Declared in `<stdio.h>`.

---

## What `stdin` is

`fp` is a `FILE *`, and Chapter 7 is where you learn to make one with `fopen`.
You do not need that here, because three of them already exist before `main`
starts:

```
stdin     standard input    keyboard, or whatever the shell redirects in
stdout    standard output   screen, or whatever the shell redirects out
stderr    standard error    screen, separate from stdout
```

So you pass `stdin` and skip the whole subject:

```c
fgets(line, MAXLEN, stdin)
```

### Why there is no filename anywhere

```
./sorter < input.txt
```

That `<` is the **shell's** work, not your program's. Before `main` runs, the
shell has opened `input.txt` and wired it to your program's standard input.
Your code reads `stdin` and never knows the difference.

```
./sorter                        keyboard  -> screen
./sorter < in.txt               file      -> screen
./sorter < in.txt > out.txt     file      -> file
./sorter | sort                 keyboard  -> another program
```

Identical program in all four cases. This is why Unix tools compose.

---

## What comes back

Two possibilities:

- **The buffer's address** — a line was read
- **`NULL`** — end of input, or an error

That `NULL` is your loop condition:

```c
char line[MAXLEN];

while (fgets(line, MAXLEN, stdin) != NULL) {
    /* one line is sitting in line[] right now */
}
```

Same shape as `while (*arr != '\0')` from `my_strlen` — read something, test it,
act on it, repeat until the terminating value shows up.

### Ending input by hand

Typing at the keyboard, send end-of-file yourself:

- **Linux / Mac:** `Ctrl-D` on a blank line
- **Windows:** `Ctrl-Z` then Enter

---

## The newline is still attached

This is the detail that causes bugs. `fgets` **keeps** the `\n`.

Type `cat` and press Enter, and the buffer holds:

```
+---+---+---+----+----+
| c | a | t | \n | \0 |
+---+---+---+----+----+
  0   1   2   3    4
```

`my_strlen` returns **4**, not 3. The newline is a real character and it counts.

### Stripping it

```c
int len = my_strlen(line);
if (len > 0 && line[len-1] == '\n')
    line[len-1] = '\0';
```

Overwrite the `\n` with `\0`. The terminator moves into the slot the newline
occupied, and the string is now `cat`.

```
before:  | c | a | t | \n | \0 |     strlen 4
after:   | c | a | t | \0 | \0 |     strlen 3
```

The guard `len > 0` matters because indexing `line[-1]` on an empty buffer is
undefined behavior.

### Why it has to go

Leave the newline on and `my_strcmp` treats it as a character to compare.
Sorting `cat` against `catalog`:

```
'c' == 'c'
'a' == 'a'
't' == 't'
'\n' (10) vs 'a' (97)  ->  -87
```

It happens to give the right answer here, but you are now sorting on invisible
characters, and any line that arrives without a trailing newline — the last
line of a file often does — compares differently from its neighbors. Strip it
once at read time and everything downstream is clean.

---

## The trap that defines this practice

`fgets` reuses **the same buffer** on every call. Each read overwrites the last.

```c
char line[MAXLEN];

while (fgets(line, MAXLEN, stdin) != NULL) {
    v[n++] = line;          /* WRONG */
}
```

Every slot ends up holding the same address:

```
      +---------+
  [0] |    *----+---+
      +---------+   |
  [1] |    *----+---+---->  line[]   (overwritten every read)
      +---------+   |
  [2] |    *----+---+
      +---------+
```

Print that and you get N copies of the last line read.

**Every line needs its own storage.** That is what the `malloc` in `readlines`
is for — permanent space per line, and the temporary buffer copied into it.

Worth causing deliberately once. It is a distinctive failure and you will
recognize it instantly forever after.

---

## Compared to K&R's getline

K&R's `getline` from Chapter 1 does the same job with a different contract:

| | `getline` (theirs) | `fgets` (library) |
|---|---|---|
| Returns | the length, `0` at EOF | the buffer, `NULL` at EOF |
| Newline | kept | kept |
| Need strlen after? | no — you already have it | yes |

Section 7.7 closes the loop by implementing `getline` in terms of `fgets`:

```c
int getline(char *line, int max)
{
    if (fgets(line, max, stdin) == NULL)
        return 0;
    else
        return strlen(line);
}
```

---

## Summary

| Point | Detail |
|---|---|
| Header | `<stdio.h>` |
| Call | `fgets(line, MAXLEN, stdin)` |
| Reads | one line, up to `maxline-1` characters |
| Newline | kept — strip it yourself |
| Terminator | `'\0'` added for you |
| Returns | the buffer, or `NULL` at end of input |
| Loop on | `!= NULL` |
| Buffer | reused every call — copy out before the next read |
| End input by hand | `Ctrl-D` (Unix), `Ctrl-Z` Enter (Windows) |
| Full coverage | Section 7.7 |