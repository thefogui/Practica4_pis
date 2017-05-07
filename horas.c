#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "rw_pid.h"

int horas = 0;
char buffer[12];

void handler_hour(){
	horas = 0;	

	sprintf(buffer, "\nhora: %02d\n", horas);
	write(1, buffer, strlen(buffer));
}

void pause_process(){
	signal(SIGCONT, handler_hour);
	pause();
}


void sumar_h(){
	if(minutos > 60){
		minutos=0;
		horas++
		signal(SIGCONT, sumar_hora);
	}	
}

int main(void){
	int writeFlag, pidInt;

	pid_t pid;
    pid = getpid(); //Identificador del proceso padre

	writeFlag = writePid("horas.pid", pid);
	pidInt = readPid("horas.pid");
	pause_process();
	return 0;
}
