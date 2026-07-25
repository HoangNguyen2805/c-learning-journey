/*
Practice 6.1.2 - Student Record with Nested Structs

Problem:
Model a student record and operate on it with pure member access:

  struct date   { int day; int month; int year; };
  struct student {
      char name[50];
      int  id;
      struct date enrolled;
      double gpa;
  };

Tasks in main:
  1. Define two students with full initializer lists (nested braces for date).
  2. Print each as:  [1042] Ada Lovelace  enrolled 15/03/2024  GPA 3.90
  3. Copy student s1 into s3 with one assignment; change s3.gpa; prove s1 unchanged.
  4. Compare the two ORIGINAL students' enrollment dates member by member and
     print who enrolled earlier (year first, then month, then day).
  5. Give the earlier student a +0.1 GPA bonus (cap at 4.0).

DSA/Algorithm Focus: record types + lexicographic comparison (multi-key ordering)
Best approach: cascade of if/else on year, month, day - exactly how dictionary
order works, and how compound-key sorting will work later.
Complexity: O(1) everything.
Constraints: strings only via initializer + %s printing (no strcpy needed yet);
no functions besides main.

Hints (Socratic):
- Why must year be compared BEFORE month? What breaks if you check day first?
- s3 = s1 copies the char array inside too. Why does this work for a struct
  when plain array assignment is illegal?
- Where exactly does the 4.0 cap check belong - before or after adding?
*/

#include <stdio.h>

struct date {
    int day;
    int month;
    int year;
};

struct student {
    char name[50];
    int id;
    struct date enrolled;
    double gpa;
};

int main(){
    // Student writes code here
    return 0;
}
