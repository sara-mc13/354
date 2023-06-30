////////////////////////////////////////////////////////////////////////////////
// Main File:        mySigHandler.c
// This File:        sendsig.c
// Other Files:      mySigHandler.c division.c
// Semester:         CS 354 Fall 2022
//
// Author:           Sara Chin
// Email:            chin6@wisc.edu
// CS Login:         schin
//
//////////////////////////// 80 columns wide ///////////////////////////////////

#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char* argv[]) {
	if (argc != 3) {
		printf("Usage: sendsig <signal type> <pid>\n");
		exit(0);
	}
	pid_t pid = atoi(argv[2]);
	int result = strcmp(argv[1],"-i");
	if (result > 0) {
		if (kill(pid, SIGUSR1) == -1) {
			perror("Error handling");
			exit(0);
		}
	} else if (result == 0) { 
		if (kill(pid, SIGINT) ==-1) {
			perror("Error handling");
			exit(0);
		}
	} else {
		perror("Invalid result");
		exit(0);
	}
	return 0;
}