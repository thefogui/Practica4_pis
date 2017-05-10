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

#define SIZE 100

int hh, mm, ss, len, init;
char buffer[SIZE];

void sumar_seg(){
	ss ++;
	if(ss == 60 )
		ss = 0;
}

void sumar_min(){ //falta comprobar 60
	if(mm == 60)
		mm = 0;	
	mm ++;
}

void sumar_hora(){
	hh ++;
}

void handler(){
	if(init == 0){
		int pidSegundos, pidMinutos, pidHoras;
		write(1, "Signal SIGCONT received - iniciando contador\n", 60);

		//leemos los PID de los procesos
		pidSegundos = readPid("segundos.pid");
		pidMinutos = readPid("minutos.pid");
		pidHoras = readPid("horas.pid");

		//reactivamos los procesos
		kill(pidHoras, SIGCONT);
		kill(pidMinutos, SIGCONT);
		kill(pidSegundos, SIGCONT);
		init++;	
	}else{
		sumar_hora();	
	}
}

void handlerSeg() {
	sumar_seg();
}

void handlerMin(){
	sumar_min();
}

void imprimir_contador(){
	//definimos el formato de la cdena
	sprintf(buffer, "%02d:%02d:%02d\n", hh, mm, ss);
	len = strlen(buffer);
	//se imprime con la funcion write
	write(1, buffer, len);
}

void handlerTerm(){
	int pidSegundos, pidMinutos, pidHoras;
	//leemos los PID de los procesos
	pidSegundos = readPid("segundos.pid");
	pidMinutos = readPid("minutos.pid");
	pidHoras = readPid("horas.pid");
	//envia una señal de finalizacion a todos los otros processos
	kill(pidHoras, SIGTERM);
	kill(pidMinutos, SIGTERM);
	kill(pidSegundos, SIGTERM);
	exit(-1); //finaliza el processos
}

int main(void){
	int writeFlag, pidInt;
	pid_t pid;
	ss=0;
	mm=0;
	hh=0;
	init = 0;
    	pid = getpid(); //Identificador del proceso padre
	//escribe y leer el pid si hay error imprime por pantalla
	//por medio de la funcion write
	if(writePid("principal.pid", pid) == 1){
		write(2, "There was an error writing principal.pid", 50);
	}
	pidInt = readPid("principal.pid");
	if(pidInt == 1){
		write(2, "There was an error reading principal.pid", 50);
	}
	signal(SIGCONT, handler); //si hay un SIGCONT envia un SIGCONT a los otros processos
	signal(SIGUSR1, handlerSeg); //si hay SIGUSR1 los segundos se suman 1
	signal(SIGUSR2, handlerMin); //si hay SIGUSR2 los minutos se suman 1
	signal(SIGTERM, handlerTerm); //finaliza todo los processos
	signal(SIGALRM, imprimir_contador); //imprime en contador
	while(1){	
		pause();
	}	// se queda en pause esperando una señal
	return 0;
}
