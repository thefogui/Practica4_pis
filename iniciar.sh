#!/bin/bash
#@Author Vitor Carvalho y Rocío Márquez

#chmod u+x limpiar.sh #permiso de ejecucion
./limpiar.sh        #llamada al fichero limpiar

make #inicia los ficheros c por medio del fichero makefile
./temporizador_digital &
./horas &
./minutos &
./segundos &
