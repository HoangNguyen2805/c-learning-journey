/*
Practice 7.4.2 - CSV Gradebook Parser

Problem:
stdin holds CSV records:  name,score1,score2,score3

    ada,90,85,95
    bob,70,,80          <- missing field: reject line
    cyrus,100,90,80

Output a report sorted by AVERAGE descending:

    1. ada     avg 90.0  [90 85 95]
    2. cyrus   avg 90.0  [100 90 80]
    ...
    parsed=2 rejected=1

Requirements:
- Read lines (your mygetline), parse with
      sscanf(line, "%15[^,],%d,%d,%d", name, &a, &b, &c)
  The %[^,] set-conversion reads up-to-but-not-including a comma - new tool!
  Require exactly 4 conversions; else reject.
- Store records in struct student { char name[16]; int s[3]; double avg; }
  array, max 32; then insertion-sort by avg desc (ties: name asc - your
  6.3.2 comparator logic returns!).
- Averages as double; print %.1f.

DSA/Algorithm Focus: parsing + records + multi-key insertion sort (cumulative!)
Best approach: parse-validate-store O(n); sort O(n^2); print O(n).
Complexity: O(n^2) total (n<=32 - fine); O(n) space.
Constraints: reject overlong names via the %15 width; guard array overflow.

Hints (Socratic):
- Why does %s fail for CSV but %[^,] work? What terminates each?
- "bob,70,,80": which conversion fails first, and what count does sscanf give?
- Could you sort with your 5.11 function-pointer isort instead of writing
  a new one? What would the comparator's signature need to be?
*/

#include <stdio.h>
#include <string.h>

#define MAXSTU 32
#define MAXLINE 256

struct student {
    char name[16];
    int s[3];
    double avg;
};

int mygetline(char *line, int max);

int main(){
    // Student writes code here
    return 0;
}

int mygetline(char *line, int max){
    // Student writes code here
    return 0;
}
