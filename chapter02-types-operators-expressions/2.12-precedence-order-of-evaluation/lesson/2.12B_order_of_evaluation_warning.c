#include <stdio.h>

int main() {
    int i = 5;
    int x;

    printf("Order of evaluation warning:\n");

    x = i;
    i++;
    x = x + i;
    i++;

    printf("Safe separated steps:\n");
    printf("x = %d\n", x);
    printf("i = %d\n", i);

    printf("\nAvoid expressions like:\n");
    printf("x = i++ + i++;\n");
    printf("printf(\"%%d %%d\\n\", i, i++);\n");

    printf("\nReason:\n");
    printf("C may not evaluate parts in the order you expect.\n");

    return 0;
}