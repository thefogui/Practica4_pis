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
char buffer[12];
int minutos_pid;

void handler_alarm(){
    seg += 1; //incrementa la variable
    pidPrincipal = readPid("principal.pid");
    if(pidPrincipal == 1){
        write(2,"There was an error reading pid principal from segundos\n", 70);
    }
    kill(pidPrincipal, SIGUSR1); //envia una señal al programa principal
    if(seg = 60){
        seg = 0; // si segundos llega a 60 se resetea
        minutos_pid = readPid("minutos.pid");
        if(minutos_pid == 1){
            write(2,"There was an error reading pid minutos from segundos\n", 80);
        }
        kill(minutos_pid, SIGCONT); //y envia una señal SIGCONT a minutos
    }
}

void handler_seg(){
	seg = 0;
    while(1) {
        //recibe una señal de alarma a cada segundo
        //cuando hay señal llama la variable
        signal(SIGALRM, handler_alarm);
        alarm(1);
    }
}

void pause_process(){
    //se queda en pause mientras no hay señal SIGCONT
   signal(SIGCONT, handler_seg);
   pause();
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
	pause_process();
	return 0;
}
