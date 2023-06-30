#include <stdio.h>
#include <stdlib.h>
#define ROWS 3
#define COLS 3


int main() {
    int a[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                printf("a[%d][%d] = %d\t", i, j, a[i][j]);
            }
        printf("\n");
    }
    printf("\n");


    
    //Reserve memory in heap for the rows of 3 integers
    int *row0 = malloc(3*sizeof(int));
    int *row1 = malloc(3*sizeof(int));
    int *row2 = malloc(3*sizeof(int));

    // Make space for pointers. A pointer of pointers
    // int * --> make it into pointer array
    int **T = malloc(3*sizeof(int *)); 

    //Make pointers of pointers point to the front of each row
    T[0] = row0;
    T[1] = row1;
    T[2] = row2;


    for(int j = 0; j < ROWS; ++j){
        for(int i = 0; i < COLS; ++i){
            //T[j][i] = a[j][i];
            //This gets us to the right row *(T+j)
            *(*(T+j)+i) = a[j][i];
        }
        printf("\n");
    }

    for(int j = 0; j < ROWS; ++j){
        for(int i = 0; i < COLS; ++i){
            printf("T[%d][%d] = %d\n", j,i,T[j][i]);
        }
        printf("\n");
    }
    printf("\n");



    return 0;
}