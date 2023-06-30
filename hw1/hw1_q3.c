#include <stdio.h>
#include <string.h>

/*
int main(void) {
	char destination[] = "spiderman";
	char source[] = "batman";
	strcpy(destination, source);
        printf("%s %s %d %d", destination, source, strlen(destination), sizeof(source));
	return 0;
}
*/

int main(void) {
	char destination[16] = "batman";
	char source[] = "spiderman";
	strcat(destination, source);
        printf("%s %s %d %d", destination, source, sizeof(destination), sizeof(source));
	return 0;
}