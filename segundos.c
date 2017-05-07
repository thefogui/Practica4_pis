#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "rw_pid.h"

int seg = 0;
char buffer[12];

void handler_seg(){
	seg = 0;
	sprintf(buffer, "seg: %02d\n", seg);
	write(1, buffer, strlen(buffer));

}

void pause_process(){
	signal(SIGCONT, handler_seg);
	pause();
}

void sumar(){
	seg++;
	kill(getpid(), SIGUSR1);
	signal(SIGCONT, handler_seg);
}

int main(void){
	int writeFlag, pidInt;
	pid_t pid;
    pid = getpid(); //Identificador del proceso padre

	writeFlag = writePid("segundos.pid", pid);
	pidInt = readPid("segundos.pid");
	pause_process();

	signal(SIGALRM, sumar);
	alarm(1);

	return 0;
}
