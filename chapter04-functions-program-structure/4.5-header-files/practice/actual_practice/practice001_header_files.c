/*
Practice 01 - Header Files

Goal:
Understand how a header file works with multiple .c files.

You will create 3 files:

1. student_utils.h
2. student_utils.c
3. practice01_header_files.c

The goal is to see this result:

Total score: 170
Average score: 85.00

---

## FILE 1: student_utils.h

This is the HEADER file.

A header file announces functions before they are used.

Write this structure in student_utils.h:

#ifndef STUDENT_UTILS_H
#define STUDENT_UTILS_H

int addScores(int a, int b);
double averageScore(double a, double b);

#endif

What this means:

#ifndef STUDENT_UTILS_H
means "if STUDENT_UTILS_H has not been defined yet"

#define STUDENT_UTILS_H
means "define STUDENT_UTILS_H now"

#endif
means "end the header guard"

The prototypes go INSIDE the header guard.

Header guard structure:

#ifndef NAME_H
#define NAME_H

function prototypes go here

#endif

Important:
Do not put full function bodies in student_utils.h.

Correct for header file:

int addScores(int a, int b);

Wrong for header file:

int addScores(int a, int b) {
return a + b;
}

---

## FILE 2: student_utils.c

This is the source file that contains the REAL function code.

At the top, include your header:

#include "student_utils.h"

Then define the two functions.

Use this structure:

#include "student_utils.h"

int addScores(int a, int b) {
return ______;
}

double averageScore(double a, double b) {
return ______;
}

What to fill in:

addScores should return a + b.

averageScore should return (a + b) / 2.0.

Important:
This file does the real work.

---

## FILE 3: practice01_header_files.c

This is the main program.

It uses the functions and prints the result.

At the top, include:

#include <stdio.h>
#include "student_utils.h"

Then write main.

Use this structure:

#include <stdio.h>
#include "student_utils.h"

int main() {
int total;
double average;

```
total = addScores(80, 90);
average = averageScore(80, 90);

printf("Total score: %d\n", total);
printf("Average score: %.2f\n", average);

return 0;
```

}

Important:
This file shows the visible result because it uses printf.

---

## How the files work together

student_utils.h:
announces the functions

student_utils.c:
defines the real functions

practice01_header_files.c:
calls the functions and prints the result

---

## Compile command

Run this in the folder that contains the 3 files:

gcc practice01_header_files.c student_utils.c -o practice01_header_files

Why not compile student_utils.h?

Because .h files are included, not compiled directly.

Wrong:

gcc student_utils.h

Correct:

gcc practice01_header_files.c student_utils.c -o practice01_header_files

---

## Run command

./practice01_header_files

Expected output:

Total score: 170
Average score: 85.00

---

## What happens when compiling

When you run:

gcc practice01_header_files.c student_utils.c -o practice01_header_files

C does this:

1. Reads practice01_header_files.c
2. Sees #include "student_utils.h"
3. Learns that addScores and averageScore exist
4. Reads student_utils.c
5. Finds the real code for addScores and averageScore
6. Connects the function calls to the real functions
7. Builds one program named practice01_header_files

---

## What to remember

.h file:
function announcements / prototypes

.c file:
real function code

header guard:
prevents the same header from being included twice

#include "student_utils.h":
brings the function announcements into the .c file

visible result:
only happens when main calls the functions and printf prints them

Rules:

* Do not use scanf.
* Do not use pointers yet.
* Do not compile the .h file directly.
* Do not put full function bodies in the header file.
  */

#include <stdio.h>
#include "student_utils.h"

int main() {
    int total;
    double average;


    total = addScores(80, 90);
    average = averageScore(80, 90);

    printf("Total score: %d\n", total);
    printf("Average score: %.2f\n", average);

    return 0;


}