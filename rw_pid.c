#include "rw_pid.h"

int writePid(char *path, pid_t pid){
    int filePid;

    filePid = open(path, O_WRONLY | S_IRWXU); //O_WRONLY : flag de apenas esciptura
								                //S_IRWXU : el usuario puede rwx el
								                //fichero cuando creado

    if(filePid < 0)	return-1;
    write(filePid, &pid, sizeof(pid));
    if(close(filePid) < 0) //cierra el fichero retorna -1 en caso de error
        	return 1;
    return 0;
}

int readPid(char *path, pid_t pid){
    int filePid;

    filePid = open(path, O_WRONLY | S_IRWXU); //O_WRONLY : flag de apenas esciptura
								                //S_IRWXU : el usuario puede rwx el
								                //fichero cuando creado

    if(filePid < 0)	return-1;
    ready(filePid, &buffer, SIZE);
    if(close(filePid) < 0) //cierra el fichero retorna -1 en caso de error
        	return 1;
    return 0;
}
