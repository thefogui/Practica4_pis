#!/bin/bash
#@Author Vitor Carvalho y Rocio

chmod u+x limpiar.sh #permiso de ejecucion
./limpiar.sh        #llamada al fichero limpiar

make #inicia los ficheros c por medio del fichero makefile
./segundos &
./minutos &
./horas &
./temporizador_digital &
