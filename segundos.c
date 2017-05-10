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
#include <sys/wait.h>
#include "rw_pid.h"

int seg = 0;
int pidPrincipal = 0;
char buffer[12];
int minutos_pid;

void handler_term(){
	exit(-1);
}

void handler_alarm(){
    kill(pidPrincipal, SIGUSR1); //envia una señal al programa principal  
    kill(minutos_pid, SIGCONT); //y envia una señal SIGCONT a minutos
}

void handler_seg(){
	pidPrincipal = readPid("principal.pid");
	if(pidPrincipal == 1){
        	write(2,"There was an error reading pid principal from segundos\n", 70);
    	}
	minutos_pid = readPid("minutos.pid");
	if(minutos_pid == 1){
            write(2,"There was an error reading pid minutos from segundos\n", 80);
        }
}

int main(void){
	int writeFlag, pidInt;
	pid_t pid;
    	pid = getpid(); //Identificador del proceso padre

	writeFlag = writePid("segundos.pid", pid);
	if(writeFlag == 1){
		write(2,"There was an error writing pid segundos\n", 60);
	}
	pidInt = readPid("segundos.pid");
	if(pidInt == 1){
		write(2,"There was an error reading pid segundos\n", 70);
	}
	signal(SIGCONT, handler_seg);
	pause();
	
	signal(SIGALRM, handler_alarm);
	signal(SIGTERM, handler_term);
	//se queda en pause mientras no hay señal SIGCONT
	while(1){   
		alarm(1);
		pause();
	}
	return 0;
}
