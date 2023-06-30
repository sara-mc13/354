#include <stdio.h>

int count = 10;

void func(int count) {
    printf("%d ", count);
    count++;
}

int main(void) {
    func(count);
    count++;
    func(count);
    printf("\n");
    return 0;
}