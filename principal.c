#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "rw_pid.h"

#define SIZE 100


int hh, mm, ss, len;
char buffer[SIZE];

void handler(){
	int pidSegundos, pidMinutos, pidHoras;
	write(1, "Signal SIGCONT received - iniciando contador\n", 44);

	//leemos los PID de los procesos
	pidSegundos = readPid("segundos.pid");
	pidMinutos = readPid("minutos.pid");
	pidHoras = readPid("horas.pid");

	//reactivamos los procesos
	kill(pidHoras, SIGCONT);
	kill(pidMinutos, SIGCONT);
	kill(pidSegundos, SIGCONT); 
}




void pause_process(){
	signal(SIGCONT, handler);
	pause();
}

void sumar_seg(){
	ss ++;
}

void sumar_min(){
	mm ++;
}

void sumar_hora(){
	hh ++;
}

void imprimir_contador(){

	sprintf(buffer, "%02d:%02d:%02d\n", hh, mm, ss);

	len = strlen(buffer);
	write(1, buffer, len);
}


int main(void){
	int writeFlag, pidInt;
	

	pid_t pid;
    pid = getpid(); //Identificador del proceso padre
	printf("%d\n", pid);
	writeFlag = writePid("principal.pid", pid);
	pidInt = readPid("principal.pid");

	ss = 0;
	mm = 0;
	hh = 0;

	sprintf(buffer, "%02d:%02d:%02d\n", hh, mm, ss);

	len = strlen(buffer);
	write(1, buffer, len);
	pause_process();

	signal(SIGUSR1, sumar_seg);
	signal(SIGUSR2, sumar_min);

	signal(SIGALRM, imprimir_contador);
	alarm(1);

	return 0;
}
