#!/bin/bash
#@Author Vitor Carvalho y Rocío Márquez
kill -SIGALRM $(ps -ef | grep "temporizador_digital" | grep -v "grep" | awk '{print $2}') 
