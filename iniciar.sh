#!/bin/bash
#@Author Vitor Carvalho

# pedro.herruzo@ub.edu

chmod u+x limpiar.sh
./limpiar.sh

make #inicia los ficheros c por medio del fichero makefile
./minutos &
./segundos &
./horas &
./temporizador_digital &
