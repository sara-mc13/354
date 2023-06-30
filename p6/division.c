////////////////////////////////////////////////////////////////////////////////
// Main File:        mySigHandler.c
// This File:        division.c
// Other Files:      sendsig.c mySigHandler.c
// Semester:         CS 354 Fall 2022
//
// Author:           Sara Chin
// Email:            chin6@wisc.edu
// CS Login:         schin
//
//////////////////////////// 80 columns wide ///////////////////////////////////

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int opCount = 0;

void  sigfpe_handler (int sigNum) {
    printf("Error: a division by 0 operation was attempted.\n");
    printf("Total number of operations completed successfully: %i\n", opCount);
    printf("The program will be terminated.");
    exit(0);
}

void  sigint_handler (int sigNum) {
	printf("\nTotal number of operations completed successfully: %i\n", opCount);
	printf("The program will be terminated.\n");
	exit(0);
}

int main() {
    //SIGFPE struct
    struct sigaction sigfpe;
    memset(&sigfpe, 0, sizeof(sigfpe));
    sigfpe.sa_handler = sigfpe_handler;
    if (sigaction(SIGFPE, &sigfpe, NULL) < 0) {
        perror("Error handling");
        exit(0);
    }

    //SIGINT struct
    struct sigaction sigint;
    memset(&sigint, 0, sizeof(sigint));
    sigint.sa_handler = sigint_handler;
    if (sigaction(SIGINT, &sigint, NULL) < 0) {
        perror("Error handling");
        exit(0);
    }

    while (1) {
        char buffer[100];

		printf("Enter first integer: ");
		fgets(buffer, 100, stdin);
		int firstNum = atoi(buffer);

		printf("Enter second integer: ");
		fgets(buffer, 100, stdin);
		int secondNum = atoi(buffer);

		int answer = firstNum / secondNum;
		int remainder = firstNum % secondNum;
		printf("%i / %i is %i with a remainder of %i\n", firstNum, secondNum, answer, remainder);
		opCount++;
    }
    return 0;
}