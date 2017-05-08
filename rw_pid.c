#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include "rw_pid.h"

char buffer[22];

int writePid(char* path, pid_t pid){
	int file, writeFlag;
	file = open(path, O_CREAT | O_TRUNC | O_RDWR, 0666); //O_CREAT : si no existe lo crea
														//O_TRUNC
														//O_RDWR : permisos de escrtura y lectura

	if(file < 0){
		write(2, "There was an opening file, finishing writePid\n", 70);
		return 1;
	}
	writeFlag = write(file, &pid, sizeof(pid)); //escribe el pid en el fichero
	if(writeFlag < 0){
		write(2, "There was an error writing pid\n", 60);
		return 1;
	}
	if(close(file) < 0){
		write(2, "There was an error closing the file\n", 70);
		return 1;
	}
	return 0;
}

int readPid(char* path){
	int file, readFlag, pid;
	file = open(path, O_RDONLY, 0666); //O_RDONLY : lectura only
	if(file < 0){
		write(2, "There was an opening file, finishing readPid\n", 70);
		return 1;
	}
	readFlag = read(file, &pid, sizeof(int)); //leer el pid y lo retorna si todo ha ido bien
	if (readFlag < 0){
   		write(2, "There was an error reading file\n", 60);
		return 1;
  	}

	if(close(file) < 0) {
		write(2, "There was an error closing the file, can't read file\n", 80);
		return 1;
	}
	return pid;
}
