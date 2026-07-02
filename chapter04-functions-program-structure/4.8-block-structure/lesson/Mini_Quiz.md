# 4.8 Quiz - Block Structure

Predict the output BEFORE running any code.

## Question 1
```c
int main() {
    int x = 1;

    {
        int x = 2;
        {
            int x = 3;
            printf("%d\n", x);
        }
        printf("%d\n", x);
    }

    printf("%d\n", x);
    return 0;
}
```
What prints, in order?
- 3 
  2
  1
## Question 2
```c
int main() {
    int i = 0;

    for (i = 0; i < 3; i++) {
        int result = i * 2;
        printf("%d\n", result);
    }

    printf("%d\n", result);   // is this valid?
    return 0;
}
```
Does this compile? Why or why not?
- No, because variable result only belong to thr for loop block. Main doesn't result exist.
## Question 3
True or False: in C, you can define a function inside another function.
- F
## Question 4
```c
int main() {
    {
        int temp = 42;
    }
    {
        int temp = 99;
        printf("%d\n", temp);
    }
    return 0;
}
```
What prints? Are the two `temp` variables the same variable or different?
- print out 99, both temp are different variable in different block
## Question 5
Where exactly does a block variable's scope END?
- Close brace }