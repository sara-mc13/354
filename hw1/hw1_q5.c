#include <stdio.h>
#include <stdlib.h>

void update(int *x) {
    int *a;
    a = malloc(sizeof(int));
    a = x;
    *x = 1;
    printf("%d ", *a);
}

int main(void) {
    int a = 4;
    int *b = &a;
    printf("%d ", *b);
    update(b);
    printf("%d ", *b);
    return 0;
}