#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "rw_pid.h"

int horas = 0;
int pidPrincipal;
int init = 0;

void handler_hour(){
	if(init == 0){
		horas = 0;
		printf("Here\n");
	}else{
		horas += 1;
		//TODO: buscar que señal recibe el principal
		kill(pidPrincipal, SIGUSR1);
		if(horas == 24){
			horas = 0;
		}
	}
}

void pause_process(){
	signal(SIGCONT, handler_hour);
	pause();
}

int main(void){
	int writeFlag, pidInt;

	pid_t pid;
    pid = getpid(); //Identificador del proceso padre

	writeFlag = writePid("horas.pid", pid);
	pidInt = readPid("horas.pid");
	pidPrincipal = readPid("principal.pid");
	pause_process();
	return 0;
}
