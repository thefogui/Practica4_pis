#!/bin/bash
#@Author Vitor Carvalho y Rocío Márquez
now=$(date +"%T")
echo "Current time : $now"
kill -SIGALRM $(ps -ef | grep "temporizador_digital" | grep -v "grep" | awk '{print $2}') 
