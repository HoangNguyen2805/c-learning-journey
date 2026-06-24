/*
Practice 01 - Else-If

Goal:
Practice the main ideas from K&R 3.3 Else-If.

Requirements:

1. Include stdio.h.

2. Create an int variable:
   - score

3. Use an if / else-if / else chain to print:
   - "A" if score is at least 90
   - "B" if score is at least 80
   - "C" if score is at least 70
   - "Fail" otherwise

4. Create another int variable:
   - temperature

5. Use an if / else-if / else chain to print:
   - "Hot"
   - "Warm"
   - "Cool"
   - "Cold"

6. Add one example showing why order matters.

7. Add comments explaining:
   - if
   - else if
   - else
   - why order matters
   - why only one branch runs

Rules:
- Do not use scanf.
- Do not use loops.
- Do not use switch yet.
- Do not copy the lesson file exactly.
- Write it from memory first, then check your notes.
*/

#include <stdio.h>

int main() {

   // 2.
   int score = 40;

   // 3.
   if (score >= 90) {
      printf("A\n");
   } else if (score >= 80) {
      printf("B\n");
   } else if (score >= 70) {
      printf("C\n");
   } else {
      printf("Fail\n");
   }
   
   // 4.
   int temperature = 76;
   

   // 5.
   if (temperature >= 90)
      printf("Hot\n");
   else if (temperature >= 70)
      printf("Warm\n");
   else if (temperature >= 50)
      printf("Cool\n");
   else
      printf("Cold\n");

   // 6.
   int temperatureC = 25;

   if (temperatureC >= 32)
      printf("Hot\n");
   else if (temperatureC >= 21)
      printf("Warm\n");
   else if (temperatureC >= 10)
      printf("Cool\n");
   else
      printf("Cold\n");

   // 7.
   // if checks the first condition.
   // else if checks another condition only if the previous condition was false.
   // else runs only when all previous conditions are false.
   // Order matters because C checks from top to bottom.
   // Only one branch runs because once C finds the first true condition,
   // it runs that block and skips the rest of the chain.
   return 0;
}