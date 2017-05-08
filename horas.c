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
char buffer[12];
int minutos;

void handler_hour(){
	if(init == 0){
		horas = 0;
	}else{
		init = 1;
		horas += 1;
		pidPrincipal = readPid("principal.pid");
		if(pidPrincipal == 1){
			write(2, "Error reading pid principal from horas.c\n", 60);
		}
		kill(pidPrincipal, SIGCONT);
		if(horas == 24){
			horas = 0;
		}
	}
}

void pause_process(){
	while(1){
		signal(SIGCONT, handler_hour);
		pause();
	}
}

void sumar_hora(){
	if(minutos > 60){
		minutos=0;
		horas++;
		signal(SIGCONT, sumar_hora);
	}
}

int main(void){
	int writeFlag, pidInt;

	pid_t pid;
    pid = getpid(); //Identificador del proceso padre

	writeFlag = writePid("horas.pid", pid);
	if(writeFlag == 1){
		write(2, "Error writing pid horas\n", 43);
	}
	pidInt = readPid("horas.pid");
	if(pidInt == 1){
		write(2, "Error reading pid horas\n", 44);
	}
	pause_process();
	return 0;
}
