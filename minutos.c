#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "rw_pid.h"

int minutos = 0;
char buffer[12];

void handler_min(){
 	minutos = 0;

	sprintf(buffer, "min: %02d\n", minutos);
	write(1, buffer, strlen(buffer));
}

void pause_process(){
	signal(SIGCONT, handler_min);
	pause();
}


void sumar_m(){
	if(seg > 60){
		seg=0;
		min++
		kill(getpid(), SIGUSR2);
		signal(SIGCONT, sumar_h);
	}	
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
