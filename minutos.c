#include <stdio.h>
#include <string.h>
#include "rw_pid.h"

int main(void){
	int writeFlag, pidInt;

	pid_t pid;
    pid = getpid(); //Identificador del proceso padre

	writeFlag = writePid("minutos.pid", pid);
	pidInt = readPid("minutos.pid");	
	
	while(1);
	return 0;
} 
