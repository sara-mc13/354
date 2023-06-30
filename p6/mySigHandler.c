////////////////////////////////////////////////////////////////////////////////
// Main File:        mySigHandler.c
// This File:        mySigHandler.c
// Other Files:      sendsig.c division.c
// Semester:         CS 354 Fall 2022
//
// Author:           Sara Chin
// Email:            chin6@wisc.edu
// CS Login:         schin
//
//////////////////////////// 80 columns wide ///////////////////////////////////

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>

int seconds = 4;
int userSigCounter = 0;

void sigalrm_handler(int sigNum) {
    pid_t process_id = getpid();
    time_t curtime;
    time(&curtime);

    printf("PID: %d ",process_id);
    printf("CURRENT TIME: %s", ctime(&curtime));

    // //redeclares the sigaction
    // struct sigaction print_pid_time; //declares sigaction
    // memset(&print_pid_time, 0, sizeof(print_pid_time));
    // print_pid_time.sa_handler = sigalrm_handler; //sets handler	
    
    //resets the alarm
    alarm(seconds); 
}

void sigusr1_handler(int sigNum) {
    printf("SIGUSR1 handled and counted!\n");
	userSigCounter++;
}

void  sigint_handler (int sigNum) {
	printf("\nSIGINT handled.\n");
	printf("SIGUSR1 was handled %i times. Exiting now.\n", userSigCounter);
	exit(0);
}

int main(int argc, char *argv[]) {
    // instructions to user
	printf("PID and time will be printed every 4 seconds\n");
	printf("Enter Ctrl-C to end the program.\n");

    //sets up SIGALRM to go off in #seconds
    alarm(seconds);

    //SIGALRM struct
    struct sigaction sigalrm; //declares sigaction
    memset(&sigalrm, 0, sizeof(sigalrm));
    sigalrm.sa_handler = sigalrm_handler; //sets handler
    //error checking
    if (sigaction(SIGALRM, &sigalrm, NULL) < 0){
		perror("Error handling");
		exit(0);
	}
    
    //SIGUSR1 struct
    struct sigaction sigusr1;
    memset(&sigusr1, 0, sizeof(sigusr1));
    sigusr1.sa_handler = sigusr1_handler;
    if (sigaction(SIGUSR1, &sigusr1, NULL) < 0) {
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

    while (1){
    }
    return 0;
}