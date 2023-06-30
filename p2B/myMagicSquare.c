///////////////////////////////////////////////////////////////////////////////
// Copyright 2020 Jim Skrentny
// Posting or sharing this file is prohibited, including any changes/additions.
// Used by permission, CS 354 Spring 2022, Deb Deppeler
////////////////////////////////////////////////////////////////////////////////
// Main File:        myMagicSquare.c
// This File:        myMagicSquare.c
// Other Files:      (name of all other files if any)
// Semester:         CS 354 Fall 2022
// Instructor:       deppeler
//
// Author:           Sara Chin
// Email:            chin6@wisc.edu
// CS Login:         schin
//
/////////////////////////// OTHER SOURCES OF HELP //////////////////////////////
//                   Fully acknowledge and credit all sources of help,
//                   including Peer Mentors, Instructors, and TAs.
//
// Persons:          Identify persons by name, relationship to you, and email.
//                   Describe in detail the the ideas and help they provided.
//
// Online sources:   Avoid web searches to solve your problems, but if you do
//                   search, be sure to include Web URLs and description of
//                   of any information you find.
////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure that represents a magic square
typedef struct {
    int size;           // dimension of the square
    int **magic_square; // pointer to heap allocated magic square
} MagicSquare;

/* TODO:
 * Prompts the user for the magic square's size, reads it,
 * checks if it's an odd number >= 3 (if not display the required
 * error message and exit), and returns the valid number.
 */
int getSize() {
    printf("Please enter square size. Size must an odd number larger than or equal to 3");
    int size;
    scanf("%d", &size);
    if(size<3 || size%2==0){
        printf("ERROR: Magic square's size must be an odd number greater than or equal to 3!");
        exit(1);
    }
    return size;
}
   
/* TODO:
 * Makes a magic square of size n using the alternate
 * Siamese magic square algorithm from assignment and
 * returns a pointer to the completed MagicSquare struct.
 *
 * n the number of rows and columns
 */
MagicSquare *generateMagicSquare(int n) {
    //dynamically allocating memory for pointer of MagicSquare object
    MagicSquare *square=malloc(sizeof(MagicSquare));
    if(square==NULL){
        printf("invalid");
        exit(1);
    }
    //storing size of the magic square
    (*square).size=n;
    //dynamically allocating memory for 2D array
    (*square).magic_square=malloc(sizeof(int*) * n);
    if((*square).magic_square==NULL){
        printf("invalid");
        exit(1);
    }

    for(int i=0;i<n;i++){
        *((*square).magic_square + i) = malloc(sizeof(int) * n);
    }
//initializing elements of 2D array to 0
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        (*(*((*square).magic_square + i) + j))=0;
    }
}
//initialing row to 0
    int row=0;
    //initialing col to n/2
    int col=n/2;
 
    for(int moves=1;moves<=n*n;moves++){

        (*(*(square->magic_square + row) + col)) = moves;
        //move up and right(north east)
        row = row -1;
        col = col + 1;
        //if multiple of size, move down from position of the multiple
        if(moves%n==0){
            row = row + 2;
            col = col -1;

        }


        else{
            //if column out of bounds set to 0
            if(col==n) col=0;
            //if column is out of bounds, set to last row
            else if(row<0) row=n-1;
        }
    }
    //a pointer to the completed MagicSquare struct
    return square;
}

/* TODO:  
 * Opens a new file (or overwrites the existing file)
 * and writes the square in the specified format.
 *
 * magic_square the magic square to write to a file
 * filename the name of the output file
 */
void fileOutputMagicSquare(MagicSquare *magic_square, char *filename) {

    FILE *fp=fopen(filename,"w");
    if(fp==NULL){
        exit(1);
    }
    fprintf(fp,"%i",magic_square->size);
    fprintf(fp, "\n");
    for(int i=0;i<magic_square->size;i++){
        for(int j=0;j<magic_square->size;j++){
            if(j!=0) fprintf(fp,",");
            fprintf(fp,"%i",*(*(magic_square->magic_square + i) + j));
        }
        fprintf(fp, "\n");
    }
    if(fclose(fp)!=0){
        printf("Error: can't close file!");
        exit(1);
    }
}

/* TODO:
 * Generates a magic square of the user specified size and
 * output the quare to the output filename
 *
 * Add description of required CLAs here
 */
int main(int argc, char **argv) {
    // TODO: Check input arguments to get output filename
    if(argc!=2){
         fprintf(stderr,"Wrong number of command line arguments");
         exit(1);
    }

    // Get magic square's size from user
    int size;
    size=getSize();

    FILE *fp=fopen(*(argv+1),"w");
    if(fp==NULL){
        fprintf(stderr,"Can't not open or create file. \n");
        exit(1);
    }


    // Generate the magic square
   // MagicSquare *answer=malloc(sizeof(MagicSquare));
    MagicSquare *answer=generateMagicSquare(size);
   
    // Output the magic square
    //char *fp = *(argv + 1);

    fileOutputMagicSquare(answer,*(argv + 1));

    fclose(fp);

    for(int i=0;i<size;i++){
        free(*((*answer).magic_square + i));
        *((*answer).magic_square + i)=NULL;
    }
    free((*answer).magic_square);
    (*answer).magic_square=NULL;
    free(answer);
    answer=NULL;


    return 0;
}

