#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include "rw_pid.h"

int writePid(char* path, pid_t pid){
	int file, writeFlag;	
	file = open(path, O_CREAT | O_TRUNC | O_RDWR, 0666);
	if(file < 0){
		write(2, "There was an opening file\n", 43);
		return 1;
	}
	writeFlag = write(file, &pid, sizeof(pid));
	if(writeFlag < 0){
		write(2, "There was an error writing pid\n", 44);
		return 1;	
	}
	if(close(file) < 0)
		write(2, "There was an error closing the file", 45);
	return 0;
}

int readPid(char* path){
	int file, readFlag, pid;
	file = open(path, O_RDONLY, 0666);
	if(file < 0){
		write(2, "There was an opening file\n", 43);
		return 1;
	}
	readFlag = read(file, &pid, sizeof(int));
	if (readFlag < 0){
   		write(2, "There was an error reading file", 44);
		return 1;
  	}
	
	if(close(file) < 0)
		write(2, "There was an error closing the file", 45);
	return pid;
}
