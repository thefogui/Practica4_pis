#!/bin/bash
#@Author Vitor Carvalho

# pedro.herruzo@ub.edu
chmod u+x limpiar.sh
./limpiar.sh
rm *.pid #elimina los ficheros pid ya existentes
make #inicia los ficheros c por medio del fichero makefile
./segundos &
./minutos &
./horas &
./temporizador_digital &
