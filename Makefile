default: temporizador_digital

# To create the executable file myprog we need the object files
# main.o, calculator.o, counter.o:

myprog: principal.o segundos.o minutos.o horas.o 
	gcc -c 

# Creating object files
main.o: main.c  
	gcc -c main.c

#calculator.o: ...


#counter.o:  ...


# To start over from scratch, type 'make clean'.  This
# removes the executable file, as well as old .o object
# files and *~ backup files:
#
clean: 
	$(RM) myprog *.o *~ 
