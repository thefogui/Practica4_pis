#include <stdio.h>
#include <string.h>
#include "rw_pid.h"

int main(void){
	int writeFlag, pidInt;

	pid_t pid;
    pid = getpid(); //Identificador del proceso padre

	writeFlag = writePid("horas.pid", pid);
	pidInt = readPid("horas.pid");

	while(1);
	return 0;
}
