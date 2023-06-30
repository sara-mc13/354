#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct {
    char  title[55];
    char *author;
    int   pages;
} Book;

typedef struct {
    int   numBooks;
    Book *books[22];
} Shelf;

int main(void) {
    Shelf bookShelf[11];
    Book book;
    bookShelf[3].books[7] = NULL;
    //statement(s) added here 
    bookShelf[3].books[7] = malloc(sizeof(Book));
    strcpy(bookShelf[3].books[7]->author, "Seuss");
    printf("%s", bookShelf);
}