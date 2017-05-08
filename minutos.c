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
char buffer[12];
int seg;
int min;

void handler_min(){
    //si es la primera vez que ha recibido un SIGCONT init pasa a ser 1
    if(init == 0){
        minutos = 0;
        init = 1;
    }else{
        minutos +=1; //incrementa los minutos
        pidPrincipal = readPid("principal.pid"); //leer el pid del programa principal
        if(pidPrincipal == 1){
    		write(2, "Error reading pid principal from minutos.c\n", 70);
    	}
        kill(pidPrincipal, SIGUSR2); //envia una señal al programa principal
        if(minutos == 60){ //si minutos ha llegado a 60 se resetea el resultado de la vaible
            minutos = 0;
            horas_pid = readPid("horas.pid");
            if(horas_pid == 1){
        		write(2, "Error reading pid horas from minutos.c\n", 60);
        	}
            kill(horas_pid, SIGCONT); //envia una señal SIGCONT a horas
        }
    }
}

void sumar_h(){

}

void sumar_m(){
	if(seg > 60){
		seg=0;
		min++;
		kill(getpid(), SIGUSR2);
		signal(SIGCONT, sumar_h);
	}
}

void pause_process(){
    //se queda en pause mientras no hay señal
    while(1){
        signal(SIGCONT, handler_min);
	    pause();
    }
}

int main(void){
	int writeFlag, pidInt;

	pid_t pid;
    pid = getpid(); //Identificador del proceso padre
    //escribe el pide del processo
	writeFlag = writePid("minutos.pid", pid);
    if(writeFlag == 1){
		write(2, "Error writing pid minutos\n", 44);
	}
    //leer el pi ddel processo
	pidInt = readPid("minutos.pid");
    if(pidInt == 1){
		write(2, "Error reading pid minutos\n", 44);
	}
    pause_process();
	return 0;
}
