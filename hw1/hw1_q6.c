#include <stdio.h>

int main (void) {
    int i = 11;
    int* ptr1 = &i;
    int** ptr2 = &ptr1;
    int*** ptr3 = &ptr2;

    printf("%p, %p, %p, %p\n", ptr1, ptr2, ptr3, &ptr3);

    printf("addr ptr1 = %p\n", &ptr1);
    printf("value ptr1 = %p\n", ptr1);
    printf("addr ptr2 = %p\n", &ptr2);
    printf("value ptr2 = %p\n", ptr2);
    printf("addr ptr3 = %p\n", &ptr3);
    printf("value ptr3 = %p\n", ptr3);

    return 0;
}