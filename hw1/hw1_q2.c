#include <stdio.h>
#include <stdlib.h>


void modify(int **x, int m, int n) {
       for (int i = 0; i < m; i++) {
           for (int j = 0; j < n; j++) {
               x[i][j] = 0;
               printf("%d", x[i][j]);
           }
           printf("\n");
       }
   }


/*
void modify(int *x[], int m, int n) {
       for (int i = 0; i < m; i++) {
           for (int j = 0; j < n; j++) {
               x[i][j] = 0;
               printf("%d", x[i][j]);
           }
           printf("\n");
       }
   }
   */

/*
void modify(int x[5][5], int m, int n) {
       for (int i = 0; i < m; i++) {
           for (int j = 0; j < n; j++) {
               x[i][j] = 0;
               printf("%d", x[i][j]);
           }
           printf("\n");
       }
   }
   */

int main(void) {
    int *x[5];

    for(int i = 0; i < 5; i++) {
        x[i] = malloc(sizeof(int) * 5);
    }
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            x[i][j] = i * j;
        }
    }
    modify(x, 5, 5);


    return 0; 
}