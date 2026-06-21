/*
Practice 01 - Header Files

Goal:
Practice the main ideas from K&R 4.5 Header Files.

Requirements:

1. Create a header file named:

   * student_utils.h

2. In student_utils.h:

   * add a header guard
   * write prototypes for two functions:

     * int addScores(int a, int b);
     * double averageScore(double a, double b);

3. Create a source file named:

   * student_utils.c

4. In student_utils.c:

   * include student_utils.h
   * define addScores
   * define averageScore

5. Create a main file named:

   * practice01_header_files.c

6. In practice01_header_files.c:

   * include stdio.h
   * include student_utils.h
   * call addScores
   * call averageScore
   * print the results

7. Add comments explaining:

   * header file
   * function prototype
   * #include
   * header guard
   * .h file
   * .c file
   * why function definitions usually do not go in headers

Compile idea:
gcc practice01_header_files.c student_utils.c -o practice01_header_files

Rules:

* Do not use scanf.
* Do not use pointers yet.
* Do not put full function bodies in the header file.
* Write it from memory first, then check your notes.
  */
