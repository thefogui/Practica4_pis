#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "rw_pid.h"

#define SIZE 100

//enviar pid al fichero rw_pid.c rw_pid(arg)

int main(void){
	int len;
	int hh, mm, ss;
	char buffer[SIZE];

	pid_t pid;
    pid = getpid(); //Identificador del proceso padre

	writePid("principal.pid", pid);

	ss = 23;
	mm = 9;
	hh = 0;

	sprintf(buffer, "%02d:%02d:%02d\n", hh, mm, ss);

	len = strlen(buffer);
	write(1, buffer, len);
	while(1);
	return 0;
}
