#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

int main(void){
	int len;
	int hh, mm, ss;
	char buffer[SIZE];

	pid_t pid;
	int filePid;
    pid = getpid(); //Identificador del proceso padre

	filePid = open("principal.pid", O_WRONLY, S_IRWXU); //O_WRONLY : flag de apenas esciptura
														//S_IRWXU : el usuario puede rwx el 
														//fichero cuando creado
	if(filePid < 0)
		return -1														

	write(filePid);
	ready(filePid);

	if(close(filePid) < 0) //cierra el fichero retorna -1 en caso de error
        return 1; 

	ss = 23;
	mm = 9;
	hh = 0;

	sprintf(buffer, "%02d:%02d:%02d\n", hh, mm, ss);

	len = strlen(buffer);
	write(1, buffer, len);
	while(1);
	return 0;
}
