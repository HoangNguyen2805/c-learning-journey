/*
Practice 01 - Relational and Logical Operators

Goal:
Practice the main ideas from K&R 2.6 Relational and Logical Operators.

Requirements:

1. Include stdio.h.

2. Create int variables:

   * age
   * score
   * a
   * b

3. Print examples using relational operators:

   * >
   * >=
   * <
   * <=
   * ==
   * !=

4. Print examples using logical operators:

   * &&
   * ||
   * !

5. Print examples showing:

   * 0 means false
   * nonzero means true
   * !0 gives true
   * !1 gives false

6. Print one example showing arithmetic before comparison:

   * 10 + 5 > 12

7. Add comments explaining:

   * relational operator
   * logical operator
   * difference between = and ==
   * AND
   * OR
   * NOT
   * short-circuit evaluation

Rules:

* Do not use scanf.
* Do not use if/else.
* Do not use loops.
* Do not copy the lesson file exactly.
* Write it from memory first, then check your notes.
  */

  #include <stdio.h>

  int main() {

   // 2.
   int age = 25;
   printf("Age = %d\n", age);
   int score = 100;
   printf("Score = %d\n", score);
   int a = 10;
   printf("a = %d\n", a);
   int b = 19;
   printf("b = %d\n", b);

   printf("\n0 -> False\n");
   printf("1 -> True ( Or any non-zero )\n");

   // 3.
   printf("\nb > a: %d\n", a > b);
   printf("b >= a: %d\n", b >= a);
   printf("b < a: %d\n", b < a);
   printf("a <= b: %d\n", a <= b);
   printf("age = score: %d\n", age == score);
   printf("age != score: %d\n", age != score);

   // 4.
   printf("\nAND logic 2 wrong = 0.\n");
   printf("age >= score && score < age: %d\n", age >= score && score < age );
   printf("AND logic 1 wrong = 0.\n");
   printf("age <= score && score < age: %d\n", age <= score && score < age );
   printf("AND logic 2 right = 1.\n");
   printf("age <= score && score > age: %d\n", age <= score && score > age );

   printf("\nOR logic 2 wrong = 0.\n");
   printf("age >= score && score < age: %d\n", age >= score || score < age );
   printf("OR logic 1 wrong and 1 right = 1.\n");
   printf("age <= score && score > age: %d\n", age <= score || score > age );
   printf("OR logic 2 right = 1.\n");
   printf("age <= score && score > age: %d\n", age <= score || score > age );
   
   printf("\nNOT logic Not == True mean: 0 False\n");
   printf("!(Age == 25): %d\n", !(age == 25));
   printf("NOT logic Not == False mean: 1 True\n");
   printf("!(Age != 25): %d\n", !(age != 25));

   // 5.
   printf("\n0 means false: %d\n", 0 != 0);
   printf("5 is nonzero, so it means true: %d\n", 5 != 0);
   printf("!0 gives true: %d\n", !0);
   printf("!1 gives false: %d\n", !1);

   // 6.
   printf("\n10 + 5 > 12: %d\n", 10 + 5 > 12);
   

   return 0;
  }