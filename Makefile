default: temporizador_digital

# To create the executable file myprog we need the object files
# main.o, calculator.o, counter.o:

temporizador_digital: principal.o segundos.o minutos.o horas.o 
	gcc principal.o segundos.o minutos. horas.o -o temporizador_digital

# Creating object files
principal.o: principal.c
	gcc -c principal.c -o principal.o
segundos.o: segundos.c
	gcc -c segundos.c -o segundos.o
minutos.o: minutos.c
	gcc -c minutos.c -o minutos.o
horas.o: horas.c
	gcc -o horas.c -o horas.o


# To start over from scratch, type 'make clean'.  This
# removes the executable file, as well as old .o object
# files and *~ backup files:
#
clean: 
	$(RM) temporizador_digital *.o *~ 
