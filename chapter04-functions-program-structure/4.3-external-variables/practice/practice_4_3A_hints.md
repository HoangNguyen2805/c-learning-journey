# Practice 4.3A - Hints

<details>
<summary>HINT - Suggested Order</summary>

## 1. Externals, above main()

```c
int score = 0;
int actionCount = 0;
```

## 2. Prototypes

```c
void addPoints(int amount);
void subtractPoints(int amount);
void showScore(void);
void resetScore(void);
```

## 3. Menu, same shape as before

```c
do {
    // menu, scanf choice
    switch (choice) {
        case 1:
            // ask amount
            addPoints(amount);
            actionCount++;
            printf("Score is now: %d\n", score);
            break;
        case 2:
            // ask amount
            if (score - amount < 0) {
                printf("Cannot go below zero.\n");
                continue;
            }
            subtractPoints(amount);
            actionCount++;
            printf("Score is now: %d\n", score);
            break;
        case 3:
            showScore();
            break;
        case 4:
            resetScore();
            actionCount++;
            break;
        case 0:
            printf("Total actions performed: %d\n", actionCount);
            printf("Quitting.\n");
            break;
        default:
            printf("Invalid choice.\n");
    }
} while (choice != 0);
```

## 4. The functions - no score parameter, no return

```c
void addPoints(int amount) {
    score = score + amount;
}
```

</details>

<details>
<summary>EXPLANATION</summary>

The whole point: score is visible to every function below because it's
declared outside all of them. No passing it in, no returning it out -
each function just touches it directly.

</details>