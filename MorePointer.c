#include <stdio.h>

int main(){
    /*
    int x = 3;
    int *px = &x;

    int y = 3245;
    int *py = &y;
    */

    int arr[5];
    for(int i =0; i < 5; i++){
        arr[i] = 9*i +11;
    }
    for(int i =0; i < 5; i++){
        printf("%-10d at address %20p\n", arr[i], &arr[i]);
    }

    printf("arr is at adress %p\n", &arr);
    printf("arr              %p\n", arr);

    int *parr;
    parr = arr;
    //parr = &arr[0];

    printf("parr = %p, &parr = %p, *parr = %d \n", parr, &parr, *parr);


    // we can think of arrays as constant pointers
    // cant reassign them - constant
    // arr = arr2     --> Make an error on the compiler
    // They do NOT get their own memory location that stores an address

    int arr2[5];
    parr = arr2;
    for(int i =0; i < 5; i++){
        printf("parr[%d] = %d at adress %p \n", i, parr[i], &parr[i]);
    }
    //Array index notation

    for(int *pa = arr; pa != &arr[5]; pa++){
        printf("%d \n", *pa);
    }
    




    return 0;
}