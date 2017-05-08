#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "rw_pid.h"

int seg = 0;
int pidPrincipal = 0;

void handler_alarm(){
    int minutos_pid;
    seg += 1;
    pidPrincipal = readPid("principal.pid");
    printf("%d\n", pidPrincipal);
    kill(pidPrincipal, SIGUSR1);
    if(seg = 60){
        seg = 0;
        minutos_pid = readPid("minutos.pid");
        kill(minutos_pid, SIGCONT);
    }
}

void handler_seg(){
	seg = 0;
	printf("Here\n");
    while(1) {
        signal(SIGALRM, handler_alarm);
        alarm(1);
    }
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
