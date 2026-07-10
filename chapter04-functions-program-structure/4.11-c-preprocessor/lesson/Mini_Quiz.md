**Q1.** The preprocessor runs **before** or **after** the compiler? And what's one thing it does that changes the code before compilation?
- before , #include <stdio.h> -> ALLOW YOU TO USE FUNCTION LIEK PRINTF OR SCANF

**Q2.** What's the difference between `#include <stdio.h>` and `#include "my_header.h"`? When would you use each?
- `#include <stdio.h>` is allow you to use function that `stdio.h`'s library have.
- `#include "my_header.h"` is user file. 
- < > searches in standard library directories, while " " searches in your current/project directory first.

**Q3.** Write a correct `#define` for a constant called `BUFFER_SIZE` with value `256`. Then write an **incorrect** version and explain why it's wrong.
- Correct:
```c
    #define BUFFER_SIZE 256
```
- Incorrect:
```c
    #define BUFFER_SIZE = 256;  // WRONG — no = or ;
```

**Q4.** Why do function-like macros need parentheses around their parameters and the whole expression? Give an example of what goes wrong without them.
- Q5 — without parentheses, square(2 + 3) becomes 2 + 3 * 2 + 3 = 13 (wrong). With parentheses ((2+3) * (2+3)) = 25 (right). That's why parentheses matter — operator precedence.

**Q5.** What does this code print, and why?
```c
#define square(x) x * x
printf("%d\n", square(2 + 3));
```
- 13
- 2 + 3 * 3 + 2

**Q6.** Explain the difference between `#ifdef` and `#ifndef`. When would you use each?
- `#ifdef` - if define - use when do something if condition is define.
- `#ifndef` - if Not define - use when do something if condition is undefine.

**Q7.** Write a header guard for a file called `student_utils.h`. What problem does it solve?
- my own header is `" "`. It help tell the preprocessor to look in that directory first.
```c
#include "student_utils.h"
```

**Q8.** True or false: "Macros are safer than functions because they don't require type checking." Explain your answer.
- FALSE. Macros are LESS safe because they don't check types. Functions are safer.

**Q9.** What does `__FILE__` do, and when is it useful?
- __FILE__ prints the filename, not line number. It's useful for debug messages like printf("Error in %s\n", __FILE__).

**Q10.** If you define a macro with `#define DEBUG`, what would you write to remove that definition later?
- You defined:
```c
    #define DEBUG
```
To remove that definition, you write:
```c
#undef DEBUG
```
- After #undef DEBUG, the name DEBUG is no longer defined, so #ifdef DEBUG would be false.
Example:
```c
#define DEBUG
printf("Debug is defined\n");  // This runs

#undef DEBUG
// DEBUG is no longer defined

#ifdef DEBUG
    printf("Debug is still defined\n");  // This does NOT run
#endif
```