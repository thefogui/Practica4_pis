
#@Author Vitor Carvalho y Rocío Márquez


default: segundos minutos horas temporizador_digital

# To create the executable file myprog we need the object files

temporizador_digital: principal.o rw_pid.o
	gcc principal.o rw_pid.o -o temporizador_digital

segundos: segundos.o rw_pid.o
	gcc segundos.o rw_pid.o -o segundos

minutos: minutos.o rw_pid.o
	gcc minutos.o  rw_pid.o -o minutos

horas: horas.o rw_pid.o
	gcc horas.o rw_pid.o -o horas

# Creating object files
principal.o: principal.c
	gcc -c principal.c -o principal.o
segundos.o: segundos.c
	gcc -c segundos.c -o segundos.o
minutos.o: minutos.c
	gcc -c minutos.c -o minutos.o
horas.o: horas.c
	gcc -c horas.c -o horas.o
rw_pid.o: rw_pid.c
	gcc -c rw_pid.c -o rw_pid.o

# To start over from scratch, type 'make clean'.  This
# removes the executable file, as well as old .o object
# files and *~ backup files:
#
clean:
	$(RM) temporizador_digital segundos minutos horas *.o *~
