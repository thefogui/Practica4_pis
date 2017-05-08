#ifndef __RW_PID_H_
#define __RW_PID_H_

int writePid(char* path, pid_t pid); //funcion para escribir un pid en un ficheros
                                    // pid -> pid a ser escrito
                                    //path -> direccion de fichero
int readPid(char* path); //funcion para leer un pid de un fichero

#endif
