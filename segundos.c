#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "rw_pid.h"

int seg = 0;

void handler_seg(){
	seg = 0;
	printf("Here\n");
}

void pause_process(){
	signal(SIGCONT, handler_seg);
	pause();
}

int main(void){
	int writeFlag, pidInt;
	pid_t pid;
    pid = getpid(); //Identificador del proceso padre

	writeFlag = writePid("segundos.pid", pid);
	pidInt = readPid("segundos.pid");
	pause_process();
	return 0;
}
