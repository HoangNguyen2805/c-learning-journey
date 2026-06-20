#include <stdio.h>

int main() {
    int x = 5;
    int y = x++;

    int a = 5;
    int b = ++a;

    int m = 5;
    int n = m--;

    int p = 5;
    int q = --p;

    printf("Post-increment:\n");
    printf("int x = 5;\n");
    printf("int y = x++;\n");
    printf("x = %d\n", x);
    printf("y = %d\n", y);

    printf("\nPre-increment:\n");
    printf("int a = 5;\n");
    printf("int b = ++a;\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    printf("\nPost-decrement:\n");
    printf("int m = 5;\n");
    printf("int n = m--;\n");
    printf("m = %d\n", m);
    printf("n = %d\n", n);

    printf("\nPre-decrement:\n");
    printf("int p = 5;\n");
    printf("int q = --p;\n");
    printf("p = %d\n", p);
    printf("q = %d\n", q);

    return 0;
}