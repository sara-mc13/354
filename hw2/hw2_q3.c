#include <stdio.h>

typedef struct {
    char firstname[22];
    char lastname[22];
    char position[22];
} Teammate;

typedef struct {
    int      size;
    char     name[22];
    Teammate roster[33];
} Team;

int main(void) {
    Team team;
    //strcpy((*team.roster).lastname,"Chin");
    team.roster[0].lastname = "Chin";
    printf("%s", (*team.roster).lastname);
}
    