#!/bin/bash
# @Author Vitor Carvalho y Rocío Márquez


#iniciamos el contador, enviando señal SIGCONT al proceso principal
kill -SIGCONT $(ps -ef | grep "temporizador_digital" | grep -v "grep" | awk '{print $2}')


