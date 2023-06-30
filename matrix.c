#include <stdio.h>
#define MAX_ROW 3
#define MAX_COL 5
// void Print_Array(int *a){}
void Print_Array(int a[]){

    //////////
    //Example below shows chaging the pointer
    /////////
    //int x = 3;
    //a = &x;
    for(int i = 0; i < 5; i++){
        printf("function: %d at adress: %p\n", a[i], &a[i]);
    }
    return;
}

void Print_Matrix(int m[][3]){
    printf("in function \n");
    for(int i = 0; i < MAX_ROW; i++){
        for(int j = 0; j < MAX_COL; j++){
            printf("%d\t", *(*(m+i)+j) );
        }
        printf("\n");
    }
    printf("\n");

}


int main(){

    //How array access works inside the compiler
    int arr[] = {0,1,2,3,4,5};
    arr[3] = 9;
    printf("%d\n\n", arr[3]);


    // 0xd100 + 3 * 4 = 0xd10c
    // base adress of array + 3* sizeof(int)     --> short = 6 bites vs int 8 bytes
    // base address of array +index * sizeof(type)
    //
    // programers access arrays without needing the sizeof
    // arr[3]
    // arr+3                 --> gives address of the 3rd element
    // *(arr+3)              --> data/element of 3rd element
    // arr[3] = 3[arr]       --> works but bad style

    for(int i = 0; i < 5; i++){
        printf("main: %d at adress: %p\n", arr[i], &arr[i]);
    }

    //Print_Array(arr);




// declare the matrix
int m[MAX_ROW][MAX_COL];
// initialize the matrix 
for (int i=0; i<MAX_ROW; i++) 
for (int j=0; j<MAX_COL; j++)
m[i][j] = 10 * (i+1) + (j+1);
// print the matrix
for (int i=0; i<MAX_ROW; i++) {
    for (int j=0; j<MAX_COL; j++)
        printf("%d\t",m[i][j]);
    printf("\n");
    }
    printf("\n");

// where are all the number stored?
for (int i=0; i<MAX_ROW; i++)
for (int j=0; j<MAX_COL; j++)
printf("m[%d][%d] = %d at address %p\n", i,j, m[i][j], &m[i][j]);
printf ("m = %p and is at address %p",m, &m);
printf("\n");
// */

Print_Matrix(m);
    


}