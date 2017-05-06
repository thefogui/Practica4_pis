#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "rw_pid.h"

int minutos = 0;

void handler_min(){
 	minutos = 0;
	printf("Here\n");
}

void pause_process(){
	signal(SIGCONT, handler_min);
	pause();
}

int main(void){
	int writeFlag, pidInt;

	pid_t pid;
    pid = getpid(); //Identificador del proceso padre

	writeFlag = writePid("minutos.pid", pid);
	pidInt = readPid("minutos.pid");
	pause_process();
	return 0;
}
