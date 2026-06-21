/*
Practice 01 - C Preprocessor

Goal:
Practice the main ideas from K&R 4.11 The C Preprocessor.

Requirements:

1. Create two symbolic constants using #define:
   - MAX_SCORE
   - PASSING_SCORE

2. In main:
   - create an int variable named score
   - compare score with PASSING_SCORE
   - print whether the student passed or failed

3. Create a function-like macro named cube.

4. cube should calculate x * x * x.

5. Use parentheses correctly in the macro.

6. In main:
   - call cube with a number
   - print the result

7. Add a DEBUG macro.

8. Use #ifdef DEBUG to print a debug message.

9. Use #ifndef RELEASE to print a message if RELEASE is not defined.

10. Add comments explaining:
    - what the preprocessor is
    - what #include does
    - what #define does
    - why #define does not use = or ;
    - what a function-like macro is
    - why macro parentheses matter
    - what #ifdef means
    - what #ifndef means
    - what #endif does
    - what a header guard is

Rules:
- Do not use scanf.
- Do not use pointers.
- Do not use structs.
- Do not use advanced macros.
- Keep this practice simple.
*/