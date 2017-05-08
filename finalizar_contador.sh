#!/bin/bash
kill -SIGTERM $(ps -ef | grep "temporizador_digital" | grep -v "grep" | awk '{print $2}')
