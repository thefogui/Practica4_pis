#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
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
