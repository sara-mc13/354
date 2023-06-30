#include <stdio.h>

typedef struct {
	char name[ 11];
	char *type;
	float weight;
} Pokemon;

int main(void) {
	Pokemon *pokedex[7];
    Pokemon p;

    printf("%d\n", sizeof(p));
    //printf("%d\n", sizeof(*p));
    printf("%d\n", sizeof(pokedex[3]));
    printf("%d", sizeof(pokedex));

}