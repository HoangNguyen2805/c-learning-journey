# Day 03 Mini Quiz - scanf

Answer without looking at notes first.

## Questions

1. What is `scanf` used for?

Answer:  user input

2. What is the difference between `printf` and `scanf`?

Answer: printf is for printting output
        scanf is for incer input

3. In this code, what is `%d` used for?

```c
scanf("%d", &age);
```

Answer: identify the user input as a interger, like whole nuber

4. Why do we use `&age` in `scanf`?

Answer: to asign value into age variable
Correct: Because scanf("%d") expects an int pointer, not a bool pointer. So we read 1 or 0 into an int first, then copy it into the bool variable. & is an pointer that guild value into the correct Variable.

5. What is wrong with this?

```c
scanf("%.2f", &price);
```

Answer: don't need .2

6. For `float`, what should `scanf` use?

Answer: %f

7. For `double`, what should `scanf` use?

Answer:  %f
Correct: %lf

8. Why do we write a space before `%c` here?

```c
scanf(" %c", &grade);
```

Answer: to get rid of previuos /0
CORRECT: The space before %c skips leftover Enter, spaces, or tabs from previous input.

9. What does `%c` read?

Answer: single lettter

10. What does `%s` read?

Answer: multiplpe letter or string

11. Why does `char[]` usually not use `&` in `scanf`?

```c
scanf("%s", name);
```

Answer: dont know
correct: Because the array name already acts like the address of the first character.

12. What does this mean?

```c
char name[50];
```

Answer: allow to strore a word that have naximum 49 didgit

13. What hidden character ends a C string?

Answer: 0/
Correct: \0

14. Why do we read bool input into an `int` first?

Answer:because we can not asign value into bool' variable
Correct: Because scanf("%d") expects an int pointer, not a bool pointer. So we read 1 or 0 into an int first, then copy it into the bool variable.

15. What is wrong with this order?

```c
int studentInput;
bool isStudent;

isStudent = studentInput;
scanf("%d", &studentInput);
```

Answer: asignt valua into bool's variable bf set it equivalent to interger's variable, when we know we can not store value into bool's variable
