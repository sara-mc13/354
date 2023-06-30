#include <stdio.h>

int main(){

    // Variable that holds a memory address
    int x = 5;
    int* p; // Type followed by * declares a pointer

    p = &x; // assign P the memory address of x
    // *p references the pointer p and goes and fetches that data
    printf("x = %d, &x = %p, p = %p, &p = %p, *p = %d \n", x, &x, p, &p, *p );

    x = 7;
    printf("x = %d, &x = %p, p = %p, &p = %p, *p = %d \n", x, &x, p, &p, *p );

    *p = 9;
    printf("x = %d, &x = %p, p = %p, &p = %p, *p = %d \n", x, &x, p, &p, *p );

    int y = 2;
    printf("x = %d, &x = %p, p = %p, &p = %p, *p = %d , y = %d, &y = %p \n", x, &x, p, &p, *p, y, &y );

    p = &y;
    *p = 4;
    printf("x = %d, &x = %p, p = %p, &p = %p, *p = %d , y = %d, &y = %p \n", x, &x, p, &p, *p, y, &y );


    int arr[4] = {10, 20, 30, 40};
    arr[0] = 15;

    for(int i = 0; i <4; i++){
        printf("arr[%d] = %d at adress %p \n", i , arr[i], &arr[i]);
    }

    p = arr;
    printf("*p = %d\n", *p);
    printf("p[0] = %d \n", arr[0]);
    printf("p[1] = %d \n", arr[1]);
    // *p == arr[0]

    // Pointer arithmatic
    p = p +1;
    printf("p[0] = %d \n", *p);
    //printf("");

   // p = &x;
   // printf("p[1] = %d \n", arr[1]);
  //  printf("p[4] = %d \n", arr[4]);

    return 0;
}