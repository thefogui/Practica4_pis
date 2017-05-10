#!/bin/bash
# @Author Vitor Carvalho y Rocío Márquez
#limpiar.sh


# kill //matar els 4 procesos (pid), menys els que inclueixen la paraula grep
#  $ps aux // todo los programas
#  grep //filtrar los 4 programas

kill $(ps -ef | grep "segundos" | grep -v "grep" | awk '{print $2}')
kill $(ps -ef | grep "minutos" | grep -v "grep" | awk '{print $2}')
kill $(ps -ef | grep "horas" | grep -v "grep" | awk '{print $2}')
kill $(ps -ef | grep "temporizador_digital" | grep -v "grep" | awk '{print $2}')

rm *.pid #elimina los ficheros pid ya existentes
make clean
