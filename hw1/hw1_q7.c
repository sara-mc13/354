#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *x = malloc(sizeof(int) * 5);
    for(int i = 0; i < 5; i++) {
        *(x+i) = i;
    }
  int *y = x + 2;
  printf("%d %d %d" , x, y, y-x);
    return 0; 
}