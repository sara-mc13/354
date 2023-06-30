#include <stdio.h>

int count = 10;

void func(int a) {
    count++;
    printf("%d  ", a);
}
int main(void) {
    func(count);
    func(count);
    printf("\n");
    return 0;
}