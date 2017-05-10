/*
#@Author Vitor Carvalho y Rocío Márquez
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "rw_pid.h"


int pidPrincipal;
int init = 0;
char buffer[12];
int minutos;

void handler_term(){
	exit(-1);
}

void handler_hour(){
	if(init == 0){
		minutos = 0;
		pidPrincipal = readPid("principal.pid");
		if(pidPrincipal == 1){
			write(2, "Error reading pid principal from horas.c\n", 60);
		}
		init = 1; //cambia el valor si no es el primer sigcont que recibe
	}else{
		minutos += 1; //se incremneta si recibe un SIGCONT
		if(minutos == 60){
			minutos = 0;
			kill(pidPrincipal, SIGCONT); //Envia un sigcont al principal
		}
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
	signal(SIGCONT, handler_hour);
	signal(SIGTERM, handler_term);
	
	while(1){
		pause();
	}
	return 0;
}
