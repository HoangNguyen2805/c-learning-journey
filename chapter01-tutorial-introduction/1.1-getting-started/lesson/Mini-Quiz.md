# Mini-Quiz: Section 1.1 — Getting Started

Answer the following questions to test your understanding. Check your answers against the answer key below.

---

## Questions

### Question 1: What does `#include <stdio.h>` do?

Explain what this line does and why it's necessary for using `printf()`.

---

### Question 2: What function must every C program have?

Name the function that every C program must contain and explain why.

---

### Question 3: What does `printf()` do?

Describe what the `printf()` function does and how you would use it to print "Hello" on the screen.

---

### Question 4: Explain the difference between `\n` and `;`

What is the difference between these two symbols, and where does each one go?

---

### Question 5: What does `return 0;` mean?

Explain what this statement does and what the `0` value means.

---

### Question 6: Describe the compile-and-run workflow

List the steps to write C code, compile it, and run the executable. Include the `gcc` command and the run command.

---

### Question 7: What is the difference between a `.c` file and an executable?

Explain what each file type contains and which one you write, which one the compiler creates.

---

### Question 8: What does the `-o` flag in `gcc` do?

Explain the purpose of the `-o` flag in the command: `gcc program.c -o program`

---

### Question 9: What does `./program` mean?

Explain what the `./` part means and why you need it to run a program in the current directory.

---

### Question 10: [FROM K&R] Write and test a program that prints your name and favorite hobby

Write a complete C program that uses `printf()` to print:
- Your name (one line)
- Your favorite hobby (another line)

Include `#include <stdio.h>`, `main()`, and `return 0;`. Compile and test it.

---

## Answer Key

### Answer 1

`#include <stdio.h>` tells the C compiler to include the standard input/output header file. This gives your program access to the `printf()` function (and other I/O functions). Without this line, you cannot use `printf()`.

---

### Answer 2

Every C program must have a `main()` function (or `int main()`). This is the function where the program starts executing. When you run a C program, the operating system looks for `main()` and begins running code from there.

---

### Answer 3

`printf()` prints text (a string) to the screen. Example:
```c
printf("Hello");
```
This prints the word `Hello`. To add a newline after it, use:
```c
printf("Hello\n");
```

---

### Answer 4

- **`\n`** = newline (escape sequence). It moves the output to the next line. Goes INSIDE the string.
  - Example: `printf("Line 1\nLine 2\n");`

- **`;`** = semicolon (statement terminator). It marks the end of a C statement. Goes AFTER the closing parenthesis.
  - Example: `printf("Hello\n");`

The newline is part of the text; the semicolon is part of the C syntax.

---

### Answer 5

`return 0;` ends the `main()` function and returns the value `0` to the operating system. The `0` means "success" — the program ran without errors. If the program encounters an error, it can return a non-zero value (like `1` or `2`) to signal that something went wrong.

---

### Answer 6

**Steps:**

1. **Write code** in a text editor and save as `program.c`
2. **Compile** with: `gcc program.c -o program`
   - `gcc` reads the `.c` file
   - Checks for errors
   - Creates an executable named `program`
3. **Run** with: `./program`
   - The `./` means "in the current directory"
   - Executes the program

**Example:**
```bash
gcc hello.c -o hello
./hello
```

---

### Answer 7

| File Type | Extension | Contains | Who Creates It |
|-----------|-----------|----------|-----------------|
| Source Code | `.c` | Human-readable C code | You (the programmer) |
| Executable | (no extension or `.exe`) | Compiled machine code | The `gcc` compiler |

You write the `.c` file. After compiling, the compiler creates the executable file, which is what the computer actually runs.

---

### Answer 8

The `-o` flag stands for "output" and specifies the name of the executable file to create. In the command:
```bash
gcc program.c -o program
```
- `program.c` = the source code file (input)
- `-o` = output flag
- `program` = the name to give the executable (output)

If you don't use `-o`, the compiler creates a default executable named `a.out`.

---

### Answer 9

`./program` runs the executable named `program` from the current directory.

- `./` = "look in the current directory" (shorthand for `/current/path/`)
- `program` = the name of the executable

You need `./` to tell the operating system to look in the current folder. Without it, the system looks in standard system directories (PATH), where your program doesn't exist.

---

### Answer 10: [FROM K&R]

**Sample Solution:**
```c
#include <stdio.h>

int main() {
    printf("My name is Hoang.\n");
    printf("My favorite hobby is coding.\n");
    return 0;
}
```

**Steps to test:**
1. Save this code as `about_me.c`
2. Compile: `gcc about_me.c -o about_me`
3. Run: `./about_me`

**Expected Output:**
---

## Challenge Questions (Optional)

### Challenge 1
Modify your program from Question 10 to print THREE things about yourself, each on its own line.

### Challenge 2
Write a program that prints a simple box using characters:
(Hint: Use `\n` to go to the next line, and spaces to create the box)

### Challenge 3 [FROM K&R]
Write a program that prints the sentence: `"In C, small details matter."` 

Make sure to include proper punctuation and escape characters where needed.

---

## Notes

- The K&R questions are from "The C Programming Language" by Kernighan & Ritchie
- Practice writing small programs and compiling them frequently
- Pay attention to semicolons and newlines — these are easy mistakes to make
