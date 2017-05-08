#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "rw_pid.h"

#define SIZE 100

void handlerSeg() {
	printf("Alarm every sec");
}

void handler(int sign){
	int pidSegundos, pidMinutos, pidHoras;
	write(2, "Signal SIGCONT received\n", 43);
	pidSegundos = readPid("segundos.pid");
	pidMinutos = readPid("minutos.pid");
	pidHoras = readPid("horas.pid");
	kill(pidSegundos, SIGCONT);
	kill(pidHoras, SIGCONT);
	kill(pidMinutos, SIGCONT);
}

void pause_process(){
	while(1){
		signal(SIGCONT, handler);
		signal(SIGUSR1, handlerSeg);
		pause();
	}
}

int main(void){
	int len, writeFlag, pidInt;
	int hh, mm, ss;
	char buffer[SIZE];

	pid_t pid;
    pid = getpid(); //Identificador del proceso padre
	printf("%d\n", pid);
	writeFlag = writePid("principal.pid", pid);
	pidInt = readPid("principal.pid");

	ss = 23;
	mm = 9;
	hh = 0;

	sprintf(buffer, "%02d:%02d:%02d\n", hh, mm, ss);

	len = strlen(buffer);
	write(1, buffer, len);
	pause_process();
	return 0;
}
