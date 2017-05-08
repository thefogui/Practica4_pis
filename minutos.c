#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "rw_pid.h"

int minutos = 0;
int pidPrincipal = 0;
int init = 0;
int horas_pid;

void handler_min(){
    if(init == 0){
        minutos = 0;
        printf("Here\n");
        init = 1;
    }else{
        minutos +=1;
        pidPrincipal = readPid("principal.pid");
        kill(pidPrincipal, SIGUSR2);
        if(minutos == 60){
            minutos = 0;
            kill(horas_pid, SIGCONT);
        }
    }
}

void pause_process(){
    while(1){
        signal(SIGCONT, handler_min);
	    pause();
    }
}

int main(void){
	int writeFlag, pidInt;

	pid_t pid;
    pid = getpid(); //Identificador del proceso padre

	writeFlag = writePid("minutos.pid", pid);
	pidInt = readPid("minutos.pid");
    horas_pid = readPid("horas.pid");
    pause_process();
	return 0;
}
